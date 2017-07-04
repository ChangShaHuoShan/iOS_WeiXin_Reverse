/** 功能说明
	屏蔽接收群消息
*/

#import "ShieldGroupMsg.h"

%hook MicroMessengerAppDelegate
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    UIAlertView *alertview = [[UIAlertView alloc] initWithTitle:@"iOS逆向开发" message:@"这是一个HelloWold!" delegate:self cancelButtonTitle:@"取消" otherButtonTitles:@"好的", nil];
    [alertview show];

    return %orig;
}
%end

%hook CSyncBaseEvent

- (BOOL)BatchAddMsg:(BOOL)arg1 ShowPush:(BOOL)arg2
{
    NSMutableArray *msgList = [self valueForKeyPath:@"m_arrMsgList"];
    NSMutableArray *msgListResult = [self filtMessageWrapArr:msgList];
    [self setValue:msgListResult forKeyPath:@"m_arrMsgList"];
    return %orig;
}

%new
- (NSMutableArray *)filtMessageWrapArr:(NSMutableArray *)msgList
{
    NSMutableArray *msgListResult = [msgList mutableCopy];
    for (id msgWrap in msgList) {
        Ivar nsFromUsrIvar = class_getInstanceVariable(objc_getClass("CMessageWrap"), "m_nsFromUsr");
        NSString *m_nsFromUsr = object_getIvar(msgWrap, nsFromUsrIvar);
        //如果包含群消息，则过滤掉
        if ([m_nsFromUsr containsString:@"@chatroom"]) {
            [msgListResult removeObject:msgWrap];
        }
    }
    return msgListResult;
}

%end
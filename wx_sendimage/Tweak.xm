//功能说明:发送图片消息

#import "SendImage.h"

static dispatch_group_t group = dispatch_group_create();

%hook CMessageMgr

//接收消息
- (void)AsyncOnAddMsg:(NSString *)fromUser MsgWrap:(CMessageWrap* )wrap{
    %orig;

    if([wrap.m_nsContent hasPrefix:@"Test"]) {
		NSString *imgUrl = @"http://ifanr-cdn.b0.upaiyun.com/wp-content/uploads/2017/06/shut-up-and-take-my-money.jpeg";
        [self sendImageMessage:imgUrl fromUser:wrap.m_nsFromUsr toUser:wrap.m_nsToUsr]; 
    }
}

%new
//发图片消息
- (void)sendImageMessage:(NSString *)imgUrl fromUser:(NSString *)fromUser toUser:(NSString *)toUser
{
	CContactMgr *mgr = [[objc_getClass("MMServiceCenter") defaultCenter] getService:[objc_getClass("CContactMgr") class]];

    NSMutableArray *toContacts = [[NSMutableArray alloc] init];

	CContact *contact = objc_msgSend(mgr ,@selector(getContactByName:), fromUser);
    [toContacts addObject:contact];
    
    ForwardMessageLogicController *fmlc = [[NSClassFromString(@"ForwardMessageLogicController") alloc] init];
    CMessageWrap *myMsg = [[NSClassFromString(@"CMessageWrap") alloc] initWithMsgType:3 nsFromUsr:toUser];
    
    myMsg.m_dtImg = [NSData dataWithContentsOfURL:[NSURL URLWithString:imgUrl]];
    
	objc_msgSend(fmlc, @selector(forwardMsgList:toContacts:),@[myMsg], toContacts);
    SharePreConfirmView *view = MSHookIvar<SharePreConfirmView *>(fmlc, "m_confirmView");
	objc_msgSend(view, @selector(onConfirm));
}
%end
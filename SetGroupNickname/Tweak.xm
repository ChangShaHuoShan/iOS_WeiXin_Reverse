/**
	功能说明：修改群昵称
*/

#import "Taoke.h"

%hook CMessageMgr

%new
//修改群昵称
- (void)setChatGroupNickname:(CContact *)groupContact withNickname:(NSString *)nickName
{
	ChatRoomInfoViewController *chatRoomInfo = [objc_getClass("ChatRoomInfoViewController") new];
	objc_msgSend(chatRoomInfo, @selector(setM_chatRoomContact:), groupContact);

	id m_CurrentVC = [chatRoomInfo valueForKeyPath:@"m_CurrentVC"];
	objc_msgSend(chatRoomInfo, @selector(setChatRoomDisplayName:vc:), nickName, m_CurrentVC);

	NSLog(@"groupContact:%@.",groupContact);
	NSLog(@"nickName:%@",nickName);
}

%end
/** 
	功能说明:自动通过好友添加请求
*/

#import "Taoke.h"

%hook CMessageMgr

- (void)MessageReturn:(unsigned long)flag MessageInfo:(NSDictionary *)info Event:(unsigned long)arg3
{
	%orig;

	if (flag == 332) //添加好友
	{
		SayHelloViewController *controller = [[%c(SayHelloViewController) alloc] init];
		[controller initData];
		NSArray *wraps = info[@"27"];
		for (CMessageWrap *wrap in wraps)
		{
			CPushContact *contact = [%c(SayHelloDataLogic) getContactFrom:wrap];
			[controller verifyContactWithOpCode:contact opcode:3];

			NSLog(@"Taoke MessageReturn:%@", [wrap m_nsContent]);
		}
	}
}
%end
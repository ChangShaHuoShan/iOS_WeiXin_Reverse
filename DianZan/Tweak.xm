/**
 功能说明:朋友圈点赞
*/

#import "DianZan.h"

%hook WCLikeButton

- (void)LikeBtnEnlarge 
{
	%orig;
	NSLog(@"LikeBtnEnlarge");
}

- (void)LikeBtnReduce 
{
	%orig;

	WCDataItem *m_item = [self valueForKeyPath:@"m_item"];

	NSString *tid = m_item.tid;
	NSLog(@"tid:%@", tid);

	NSString *username = m_item.username;
	NSLog(@"username:%@", username);

	NSString *nickname = m_item.nickname;
	NSLog(@"nickname:%@", nickname);

	NSMutableArray *likeUsers = m_item.likeUsers;

	for (WCUserComment *comment in likeUsers) {

		NSString *commentID = comment.commentID;
		NSLog(@"commentID:%@",commentID);

		NSString *refUserName = comment.refUserName;
		NSLog(@"refUserName:%@",refUserName);

		NSString *username = comment.username;
		NSLog(@"username:%@",username);

		NSString *nickname = comment.nickname;
		NSLog(@"nickname:%@",nickname);

		NSString *content = comment.content;
		NSLog(@"content:%@",content);

	
	}

	NSLog(@"LikeBtnReduce");
}

- (void)LikeBtnReduceEnd
{
	%orig;
	//NSLog(@"LikeBtnReduceEnd");
}

- (id)initWithDataItem:(id)arg1
{
	//NSLog(@"initWithDataItem:%@", arg1);
	return %orig;
}

- (void)onLikeFriend {
	%orig;
	//NSLog(@"onLikeFriend");
}

- (void)updateLikeBtn
{
	%orig;
	//NSLog(@"updateLikeBtn");
}
%end

%hook WCTimeLineViewController

- (void)initData
{
	%orig;
	NSLog(@"initData");
}

- (id)init
{
	id obj = %orig;
	NSLog(@"obj:%@", obj);
	return %orig;;
}

- (void)onMenuControllerWillShow:(id)arg1
{
	%orig;
	NSLog(@"onMenuControllerWillShow:%@", arg1);
}

%end

%hook FindFriendEntryViewController

- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2
{
	%orig;
	NSLog(@"didSelectRowAtIndexPath arg1:%@", arg1);
	NSLog(@"didSelectRowAtIndexPath arg1:%@", arg2);
}

- (void)openAlbum 
{
	//%orig;
	NSLog(@"openAlbum");
}

- (void)openAlbumAnimated:(BOOL)arg1
{
	%orig;
	NSLog(@"openAlbumAnimated");
}
%end
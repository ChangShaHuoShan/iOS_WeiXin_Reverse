
//常用参数宏定义
#define SCREEN_WIDTH                [[UIScreen mainScreen] bounds].size.width
#define SCREEN_HEIGHT               [[UIScreen mainScreen] bounds].size.height

//字符串处理宏定义
#define NON(str) (str?str:@"")
#define STR_NUM(num) ([NSString stringWithFormat:@"%ld",(long)num])
#define STR_OBJ(obj) (obj?[NSString stringWithFormat:@"%@",obj]:nil)
#define isEmpty(str) (str.length == 0 || str == nil)

//常用单例宏定义
#define kAppDelegate        ((AppDelegate *)[[UIApplication sharedApplication] delegate])
#define kUserDefaults       [NSUserDefaults standardUserDefaults]
#define kDocumentDirectory  (NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0])

//常用参数宏定义
#define SCREEN_WIDTH                [[UIScreen mainScreen] bounds].size.width
#define SCREEN_HEIGHT               [[UIScreen mainScreen] bounds].size.height
#define SCREEN_HEAD                 64
#define SCREEN_HEIGHT_WITHOUTHEAD   SCREEN_HEIGHT-64
#define LINE_SIZE                   1/[[UIScreen mainScreen] scale]
#define LINE_SPACE                  5

//常用颜色宏定义
#define COLOR(r,g,b,a) ([UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)])
#define kColor_Green            COLOR(76,192,95,1)
#define kColor_Blue             COLOR(155,216,93,1)
#define kColor_LightBlue        COLOR(3, 169, 246, 1)
#define kColor_LightRed         COLOR(251,132,134,1)

#import <substrate.h>

@class CMessageMgr;
@class CContactMgr;
@class WeixinContentLogicController;
@class CMessageWrap;
@class ForwardMessageMgr;
@class NSTextStorage;
@class UIImageimageWithData;
@class NSDatadataWithContentsOfURL;

extern NSOperationQueue *globalQueue;
extern CMessageMgr *globalMessageMgr;
extern WeixinContentLogicController *logicController;

@interface ForwardMessageMgr : NSObject
- (void)forwardMessage:(id)arg1 fromViewController:(id)arg2;
- (id)getCurrentViewController;
- (void)onServiceClearData;
- (void)onServiceInit;
@end

@interface CAppViewControllerManager : NSObject
+ (instancetype)getAppViewControllerManager;
- (void)createContactsViewController;
- (id)getTabBarController;
@end

@interface MMTabBarController : UITabBarController
- (void)setSelectedIndex:(unsigned)index;

@end

@interface WCPayInfoItem : NSObject
@property (retain, nonatomic) NSString *m_c2cIconUrl;
@property (retain, nonatomic) NSString *m_c2cNativeUrl;
@property (retain, nonatomic) NSString *m_c2cUrl;
@property (nonatomic) NSInteger m_c2c_msg_subtype;
@property (retain, nonatomic) NSString *m_fee_type;
@property (retain, nonatomic) NSString *m_hintText;
@property (retain, nonatomic) NSString *m_nsFeeDesc;
@property (retain, nonatomic) NSString *m_nsTranscationID;
@property (retain, nonatomic) NSString *m_nsTransferID;
@property (retain, nonatomic) NSString *m_receiverDesc;
@property (retain, nonatomic) NSString *m_receiverTitle;
@property (retain, nonatomic) NSString *m_sceneText;
@property (retain, nonatomic) NSString *m_senderDesc;
@property (retain, nonatomic) NSString *m_senderTitle;
@property (nonatomic) NSInteger m_templateID;
@property (retain, nonatomic) NSString *m_total_fee;
@property (nonatomic) NSInteger m_uiBeginTransferTime;
@property (nonatomic) NSInteger m_uiEffectiveDate;
@property (nonatomic) NSInteger m_uiInvalidTime;
@property (nonatomic) NSInteger m_uiPaySubType;
@end

@interface CMessageWrap : NSObject // 微信消息
@property (retain, nonatomic) NSData *m_dtVoice;
@property (assign, nonatomic) unsigned int m_uiMesLocalID;
@property (retain, nonatomic) NSString* m_nsFromUsr; // 发信人，可能是群或个人
@property (retain, nonatomic) NSString* m_nsToUsr; // 收信人
@property (assign, nonatomic) unsigned int m_uiStatus;
@property (retain, nonatomic) NSString* m_nsContent; // 消息内容
@property (retain, nonatomic) NSString* m_nsRealChatUsr; // 群消息的发信人，具体是群里的哪个人
@property(retain, nonatomic) NSData *m_dtImg; // 图片消息
@property (nonatomic) unsigned int m_uiMessageType;
@property (nonatomic) long long m_n64MesSvrID;
@property (nonatomic) unsigned int m_uiCreateTime;
@property (retain, nonatomic) NSString *m_nsDesc;
@property (retain, nonatomic) NSString *m_nsAppExtInfo;
@property (nonatomic) unsigned int m_uiAppDataSize;
@property (nonatomic) unsigned int m_uiAppMsgInnerType;
@property (retain, nonatomic) NSString *m_nsShareOpenUrl;
@property (retain, nonatomic) NSString *m_nsShareOriginUrl;
@property (retain, nonatomic) NSString *m_nsJsAppId;
@property (retain, nonatomic) NSString *m_nsPrePublishId;
@property (retain, nonatomic) NSString *m_nsAppID;
@property (retain, nonatomic) NSString *m_nsAppName;
@property (retain, nonatomic) NSString *m_nsThumbUrl;
@property (retain, nonatomic) NSString *m_nsAppMediaUrl;
@property (retain, nonatomic) NSData *m_dtThumbnail;
@property (retain, nonatomic) NSString *m_nsTitle;
@property (retain, nonatomic) NSString *m_nsMsgSource;
@property (retain, nonatomic) NSString *m_nsMsgAttachUrl;
@property (retain, nonatomic) WCPayInfoItem *m_oWCPayInfoItem;
- (instancetype)initWithMsgType:(int)msgType;
+ (UIImage *)getMsgImg:(CMessageWrap *)arg1;
+ (NSData *)getMsgImgData:(CMessageWrap *)arg1;
+ (NSString *)getPathOfMsgImg:(CMessageWrap *)arg1;
- (UIImage *)GetImg;
- (BOOL)IsImgMsg;
- (BOOL)IsAtMe;
+ (void)GetPathOfAppThumb:(NSString *)senderID LocalID:(NSInteger)mesLocalID retStrPath:(NSString **)pathBuffer;
+ (void)GetPathOfAppDataByUserName:(NSString *)senderID andMessageWrap:(CMessageWrap *)arg2 retStrPath:(NSString **)arg3;
+ (UIImage *)createMaskedThumbImageForMessageWrap:(CMessageWrap *)arg1;
@end

@interface CMessageMgr : NSObject // 这几个方法执行完可能需要若干秒时间；与后端的通信在其内部实现，在这些方法执行完成前，信息可能就已经发送成功，本地回调方法得到调用了，需要特别留意！
- (void)AddMsg:(NSString *)msg MsgWrap:(CMessageWrap *)wrap; // 发文字和图片（和其他各种消息），参数1是收件人ID，参数2是要发的信息
- (void)AddEmoticonMsg:(NSString *)arg1 MsgWrap:(CMessageWrap *)arg2; // 发表情
- (void)AddAppMsg:(NSString *)arg1 MsgWrap:(CMessageWrap *)arg2 Data:(NSData *)arg3 Scene:(NSInteger)arg4; // 发链接
- (void)ResendMsg:(NSString *)arg1 MsgWrap:(CMessageWrap *)arg2;
- (void)DelMsg:(NSString *)userID MsgList:(NSArray *)wraps DelAll:(BOOL)arg3;
- (void)StartDownloadAppAttach:(NSString *)arg1 MsgWrap:(CMessageWrap *)arg2;
- (BOOL)StartDownloadThumb:(CMessageWrap *)arg1;
- (NSInteger)GetDownloadThumbStatus:(CMessageWrap *)arg1;
- (CMessageWrap *)GetLastMsgFromUsr:(NSString *)arg1;
    
- (void)openAlimama;
- (void)continueMessageQueue;
- (void)checkHeart;
- (NSString *)getAlimamaAccount:(NSString *)wx_Id;

- (NSData *)ApiPost:(NSString *)url Param:(NSMutableDictionary *)param;
- (void)Welcome:(NSString *)fromUser MsgWrap:(CMessageWrap *)wrap ReMsgWrap:(CMessageWrap *)reWrap;
- (id)initWithMsgType:(int)arg1 nsFromUsr:(id)arg2;

//自动发朋友圈
- (void)autoSendFriendScircle:(NSString *)title withImage:(NSArray *)images;
//发图片消息    
- (void)sendImageMessage:(NSString *)imgUrl fromUser:(NSString *)fromUser toUser:(NSString *)toUser;
//消息转发
- (void)transmitMsgWrap:(CMessageWrap *)wrap ReMsgWrap:(CMessageWrap *)reWrap;
@end

@interface ContactsViewController : UIViewController
- (void)onAddContact;
@end

@interface CBaseContact : NSObject
@property (assign, nonatomic) NSInteger m_uiSex; // 1 for male
@property (retain, nonatomic) NSString *m_nsRemark; // nickname
@property (retain, nonatomic) NSString* m_nsNickName;
@property (retain, nonatomic) NSString* m_nsUsrName; // wechat ID
@property (retain, nonatomic) NSString *m_nsEncodeUserName;
@property (nonatomic) NSInteger m_uiFriendScene;
@property (nonatomic) NSInteger m_uiType; // 3 for stock contact, 7 for others
@end

@interface CContact : CBaseContact

@property(retain, nonatomic) NSString *m_nsUsrName;
@property(retain, nonatomic) NSString *m_nsHeadImgUrl;
@property(retain, nonatomic) NSString *m_nsNickName; //用户昵称
@property(retain, nonatomic) NSString *m_nsOwner; //群主ID
@property(retain, nonatomic) NSString *m_nsChatRoomMemList; //群内所有微信ID

@property (nonatomic) int m_iWCFlag;
@property (retain, nonatomic) NSString *m_nsCity;
@property (retain, nonatomic) NSString *m_nsCountry;
@property (retain, nonatomic) NSString *m_nsProvince;
@property (retain, nonatomic) NSString *m_nsSignature;
- (NSString *)getChatRoomMemberDisplayName:(CContact *)arg1; // caller is group contact, arg1 is member contact, 返回我们看到的名称
- (NSString *)getChatRoomMemberNickName:(CContact *)arg1; // 返回该用户自己的昵称
- (NSString *)getChatRoomMembrGroupNickName:(CContact *)arg1; // 返回用户在群里设置的昵称
@end

@interface FindContactSearchViewCellInfo : NSObject
@property (retain, nonatomic) CContact *foundContact;
- (void)doSearch;
- (void)stopLoading;
@end

@interface MMUISearchBar : UISearchBar
@end

@interface MMSearchBar : NSObject
@property (retain, nonatomic) MMUISearchBar *m_searchBar;
@end

@interface CBaseContactInfoAssist : NSObject
- (void)onAddToContacts;
@end

@interface MMUIViewController : UIViewController

- (void)startLoadingBlocked;
- (void)startLoadingNonBlock;
- (void)startLoadingWithText:(NSString *)text;
- (void)stopLoading;
- (void)stopLoadingWithFailText:(NSString *)text;
- (void)stopLoadingWithOKText:(NSString *)text;

@end

@interface ContactInfoViewController : MMUIViewController

@property(retain, nonatomic) CContact *m_contact;

- (BOOL)isInMyContactList;

@end

@interface SendVerifyMsgViewController : UIViewController
- (void)onSendVerifyMsg;

@end

@interface CContactMgr : NSObject
- (CContact *)getContactByName:(NSString *)m_nsUsrName;
- (CContact *)getSelfContact;
- (BOOL)setContact:(CContact *)arg1 remark:(NSString *)arg2 hideHashPhone:(BOOL)arg3;
- (BOOL)deleteContact:(CContact *)arg1 listType:(NSInteger)arg2; // arg2传3
- (BOOL)isInContactList:(NSString *)userID;
- (NSArray *)getContactList:(NSInteger)arg1 contactType:(NSInteger)arg2 domain:(id)arg3; // 1, 0, nil
@end

@interface MMServiceCenter : NSObject
+ (instancetype)defaultCenter;
- (id)getService:(Class)service;
@end

@interface WebViewA8KeyLogicImpl : NSObject
- (void)getA8Key:(NSString *)arg1 Reason:(int)arg2;
@end

@interface PBGeneratedMessage : NSObject // iOS 6
@end

@interface WXPBGeneratedMessage : NSObject
- (NSData *)serializedData;
@end

@interface GetA8KeyResp : WXPBGeneratedMessage
@property (retain, nonatomic) NSString *fullUrl;
@end

@interface ProtobufCGIWrap : NSObject
@property (retain, nonatomic) WXPBGeneratedMessage *m_pbResponse;
@property (retain, nonatomic) WXPBGeneratedMessage *m_pbRequest;
@end

@interface CPushContact : CContact
@property (retain, nonatomic) NSString *m_nsNickName;
@end

@interface SayHelloDataLogic : NSObject
+ (CPushContact *)getContactFrom:(CMessageWrap *)arg1;
@end

@interface SayHelloViewController : NSObject
- (void)initData;
- (void)verifyContactWithOpCode:(CPushContact *)arg1 opcode:(NSInteger)arg2;
@end

@interface BaseMsgContentLogicController : NSObject
- (void)PreviewImage:(CMessageWrap *)arg1;
- (void)SendMessageWrap:(id)arg1;
- (void)AddMsg:(id)arg1 MsgWrap:(id)arg2;
@end

@interface ViewAppMsgController : NSObject
- (void)PreviewImage:(CMessageWrap *)arg1;
@end

@interface BaseMsgContentViewController : NSObject
- (void)PreviewImage:(CMessageWrap *)arg1;
- (void)pasteImage:(id)arg1;
@end

@interface WeixinContentLogicController : BaseMsgContentLogicController
- (CMessageWrap *)FormImageMsg:(NSString *)receiverID withImage:(UIImage *)arg2;
- (CMessageWrap *)FormTextMsg:(NSString *)receiverID withText:(NSString *)arg2;
@end

@interface CGroupMgr : NSObject
- (BOOL)InviteGroupMember:(NSString *)groupID withMemberList:(NSArray *)userIDs;
- (BOOL)IsUsrInChatRoom:(NSString *)groupID Usr:(NSString *)userID;
- (NSArray *)GetGroupMember:(NSString *)groupID;
- (BOOL)SetDislayName:(NSString *)displayName forGroup:(NSString *)groupID;
- (BOOL)QuitGroup:(NSString *)groupID withUsrName:(NSString *)myUserID;
@end

@interface CSettingExt : NSObject
- (void)theadSafeSetObject:(NSString *)arg1 forKey:(NSString *)arg2;
@end

@interface SettingUtil : NSObject
+ (NSString *)getLocalUsrName:(NSInteger)arg1;
+ (id)GetLocalUsrImg;               //获取自己的头像
+ (id)getCurUsrDisplayName;         //获取自己设置的微信号
+ (id)getCurUsrName;                //获取系统分配的微信号
+ (id)getCurUsrNickname;            //获取微信昵称
+ (CSettingExt *)getMainSettingExt;
@end

@interface CUtility : NSObject
+ (NSInteger)genCurrentTime;
+ (NSString *)GetPathOfMesAudio:(NSString *)arg1 LocalID:(NSInteger)arg2 DocPath:(NSString *)arg3;
+ (NSString *)GetDocPath;
@end

@interface DelaySwitchSettingLogic : NSObject
- (void)chatProfileSwitchSetting:(NSString *)groupID withType:(int)arg2 andValue:(BOOL)arg3;
- (void)commitAllSwitchSetting;
@end

@interface SendAppMsgResponse : WXPBGeneratedMessage
@property (nonatomic) unsigned int type;
@end

@interface CDNUploadMsgImgPrepareResponse : WXPBGeneratedMessage
@end

@interface GetQRCodeResponse : PBGeneratedMessage
@end

@interface ForwardMsgUtil : NSObject
+ (void)ForwardMsg:(CMessageWrap *)arg1 ToContact:(CContact *)arg2 NeedSrcInfo:(BOOL)arg3;
+ (CMessageWrap *)GenForwardMsgFromMsgWrap:(CMessageWrap *)arg1 ToContact:(CContact *)arg2 NeedSrcInfo:(BOOL)arg3;
+ (CMessageWrap *)appMsgFromMsgWrap:(CMessageWrap *)arg1;
@end

@interface MMSessionInfo
@property (retain, nonatomic) NSString *m_nsUserName;
@end

@interface MMNewSessionMgr : NSObject
{
	NSMutableArray *m_arrSession;
}
- (void)DeleteAllSession;
- (void)ChangeSessionUnReadCount:(NSString *)userID to:(unsigned int)count;
- (void)DeleteSessionOfUser:(NSString *)userID;
@end

@interface ModSingleField : WXPBGeneratedMessage
@property (nonatomic) unsigned int opType; // 1是改自己的昵称
@property (retain, nonatomic) NSString *value;
@end

@interface ModChatRoomMemberDisplayName : WXPBGeneratedMessage
@property (retain, nonatomic) NSString *chatRoomName;
@property (retain, nonatomic) NSString *displayName;
@property (retain, nonatomic) NSString *userName;
@end

@interface NewSyncService : NSObject
- (NSInteger)StartOplog:(NSInteger)arg1 Oplog:(NSData *)arg2;
@end

@interface CUsrInfo : NSObject
@property (retain, nonatomic) NSString *m_nsCity;
@property (retain, nonatomic) NSString *m_nsCountry;
@property (retain, nonatomic) NSString *m_nsNickName;
@property (retain, nonatomic) NSString *m_nsProvince;
@property (retain, nonatomic) NSString *m_nsSignature;
@property (nonatomic) NSInteger m_uiSex;
@end

@interface UpdateProfileMgr : NSObject // for WeChat on iOS 6
+ (BOOL)modifyUserInfo:(CUsrInfo *)arg1;
@end

@interface BaseMessageNodeView : NSObject
- (CMessageWrap *)m_msgWrap;
@end

@interface OpenApiMgrHelper : NSObject
+ (NSData *)checkAppMsgThumbData:(NSData *)arg1;
@end

@interface CAppUtil : NSObject
+ (NSString *)getCurrentLanguageAppName:(NSString *)arg1;
@end

@interface SKBuiltinString_t : NSObject
@property (retain, nonatomic) NSString *string;
@end

@interface BaseResponse : NSObject
@property (retain, nonatomic) SKBuiltinString_t *errMsg;
@property (nonatomic) int ret;
@end

@interface SearchContactResponse : NSObject
@property (retain, nonatomic) NSString *myBrandList;
@property (retain, nonatomic) SKBuiltinString_t *nickName;
@property (retain, nonatomic) SKBuiltinString_t *pyinitial;
@property (retain, nonatomic) SKBuiltinString_t *quanPin;
@property (nonatomic) int sex;
@property (retain, nonatomic) SKBuiltinString_t *userName;
@property (retain, nonatomic) NSString *verifyInfo;
@property (retain, nonatomic) BaseResponse *baseResponse;
@property (retain, nonatomic) NSMutableArray *contactList;
@end

@interface GetQRCodeRequest : WXPBGeneratedMessage
@property (retain, nonatomic) SKBuiltinString_t *userName;
@end

@interface CVerifyContactWrap : NSObject
@property (retain, nonatomic) NSString *m_nsUsrName;
@property (retain, nonatomic) CContact *m_oVerifyContact;
@property (nonatomic) NSInteger m_uiScene;
@property (nonatomic) NSInteger m_uiWCFlag;
@end

@interface CContactVerifyLogic : NSObject
{
    NSArray *m_arrVerifyContactWrap;
    NSString *m_nsVerifyValue;
    NSInteger m_uiOpCode;
    NSInteger m_uiFriendScene;
}
- (BOOL)doVerify:(NSString *)arg1;
- (NSData *)ApiPost:(NSString *)url Param:(NSMutableDictionary *)param;

@end

@interface CdnTaskInfo : NSObject
@property (retain, nonatomic) CMessageWrap *m_wrapMsg;
@end

@interface CdnDownloadTaskInfo : NSObject
@property (nonatomic) long m_nRetCode;
@property (nonatomic) NSInteger m_uiFileLength;
@property (retain, nonatomic) NSString *m_nsExtInfo;
@property (retain, nonatomic) NSString *m_nsFileID;
@property (retain, nonatomic) NSString *m_nsTransInfo;
@end

@interface MMQRCodeMgr : NSObject
- (void)getQRCodeFromServer:(NSString *)userID withStyle:(NSInteger)style;
- (NSString *)getQRCodeImagePath:(NSString *)userID;
@end

@interface ChatRoomInfoViewController : UIViewController
- (BOOL)quitChatRoom;
@end

@interface AudioHelper : NSObject
+ (BOOL)isSilkFile:(NSData *)data;
@end

@interface CPDistributedMessagingCenter : NSObject
+ (instancetype)centerNamed:(id)named;
- (NSDictionary *)sendMessageAndReceiveReplyName:(NSString *)name userInfo:(NSDictionary *)info;
- (BOOL)sendMessageName:(NSString *)name userInfo:(NSDictionary *)info;
- (void)runServerOnCurrentThread;
- (void)registerForMessageName:(NSString *)messageName target:(id)target selector:(SEL)selector;
@end

@interface MicroMessengerAppDelegate : NSObject
@end

@interface SBApplication : NSObject
- (NSString *)bundleIdentifier;
@end

@interface SpringBoard : NSObject
- (SBApplication *)_accessibilityFrontMostApplication;
- (BOOL)launchApplicationWithIdentifier:(NSString *)arg1 suspended:(BOOL)arg2;
@end

@interface VoiceTransFloatPreview : NSObject
- (NSString *)getVoiceIDFromMsg:(CMessageWrap *)arg1;
@end

@interface VoiceTransHelper : NSObject
- (instancetype)initWithVoiceMsg:(CMessageWrap *)arg1 VoiceID:(NSString *)arg2;
- (void)startVoiceTrans;
@end

@interface VoiceTransRes : PBGeneratedMessage
@property (nonatomic) unsigned int endFlag;
@property (retain, nonatomic) NSString *result;
@end

@interface GetVoiceTransResResponse : WXPBGeneratedMessage
@property (retain, nonatomic) VoiceTransRes *transRes;
@end

@interface GetVoiceTransResRequest : PBGeneratedMessage
@property (retain, nonatomic) NSString *voiceId;
@end

@interface AccountStorageMgr : NSObject
- (void)SaveSettingExt;
@end

@interface ContactsDataLogic : NSObject

@property(nonatomic) unsigned int m_uiScene; // @synthesize m_uiScene;
@property (nonatomic, strong) NSMutableDictionary *m_dicAllContacts;


@end

@interface MMGrowTextView : NSObject

@end

@interface NewSettingViewController : UIViewController
- (void)reloadTableData;
- (void)pushViewController;
@end

@interface MMTableView : UIViewController
- (id)reloadData;

@end

@interface MMTableViewInfo : UIViewController

- (void)insertSection:(id)arg1 At:(unsigned long)arg2;
- (id)getTableView;


@end

@interface MMTableViewCellInfo : UIViewController

+ (id)normalCellForSel:(SEL)arg1 target:(id)arg2 title:(id)arg3 accessoryType:(int)arg4;

@end

@interface MMTableViewSectionInfo : UIViewController
+ (id)sectionInfoDefaut;
- (void)addCell:(id)arg1;
@end

@interface NewMainFrameViewController : UIViewController

- (void)pushViewController;

@end

@interface GroupSelectContactsViewController : MMUIViewController

- (void)pushViewController;

@end

@interface ForwardMessageLogicController : MMUIViewController 
- (void)ForwardMsgList:(id)arg1 ToContact:(id)arg2;
@end

@interface SharePreConfirmView : NSObject

@end



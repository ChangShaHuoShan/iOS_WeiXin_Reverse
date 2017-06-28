
@interface MMGrowTextView : NSObject
@end

@interface SharePreConfirmView : NSObject
@end

@interface ForwardMessageLogicController : NSObject 
- (void)ForwardMsgList:(id)arg1 ToContact:(id)arg2;
@end

@interface CMessageWrap : NSObject

@property(retain, nonatomic) NSString *m_nsContent;     //消息内容
@property(retain, nonatomic) NSString *m_nsFromUsr;     //发送者
@property(retain, nonatomic) NSString *m_nsToUsr;       //接收者
@property(nonatomic) unsigned int m_uiMessageType;      //消息类型
@property(retain, nonatomic) NSData *m_dtImg; 

- (id)initWithMsgType:(int)arg1 nsFromUsr:(id)arg2;
@end

@interface CMessageMgr : NSObject

+ (_Bool)isSenderFromMsgWrap:(id)arg1;

- (void)sendImageMessage:(NSString *)imgUrl fromUser:(NSString *)fromUser toUser:(NSString *)toUser;

@end


@interface CContactMgr : NSObject

- (id)getContactByName:(id)arg1;
- (id)getContactForSearchByName:(id)arg1;

@end

@interface MMServiceCenter : NSObject

+ (instancetype)defaultCenter;
- (id)getService:(Class)service;

@end

@interface CContact : NSObject

@end

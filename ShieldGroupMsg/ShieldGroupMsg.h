
@interface CMessageWrap : NSObject

@property(retain, nonatomic) NSString *m_nsContent;     //消息内容
@property(retain, nonatomic) NSString *m_nsFromUsr;     //发送者
@property(retain, nonatomic) NSString *m_nsToUsr;       //接收者
@property(nonatomic) unsigned int m_uiMessageType;      //消息类型
@property(retain, nonatomic) NSData *m_dtImg; 

@end

@interface CMessageMgr : NSObject

+ (_Bool)isSenderFromMsgWrap:(id)arg1;

@end


@interface CContactMgr : NSObject

- (id)getContactByName:(id)arg1;
- (id)getContactForSearchByName:(id)arg1;

@end

@interface MMServiceCenter : NSObject

+ (instancetype)defaultCenter;
- (id)getService:(Class)service;

@end

@interface CSyncBaseEvent : NSObject
- (NSMutableArray *)filtMessageWrapArr:(NSMutableArray *)msgList;
@end

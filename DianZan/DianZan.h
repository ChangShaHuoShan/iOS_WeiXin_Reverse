
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

@interface WCDataItem : NSObject

@property(retain, nonatomic) NSString *tid;    
@property(retain, nonatomic) NSString *username;    
@property(retain, nonatomic) NSString *nickname;    
@property(retain, nonatomic) NSString *sourceUrl;    
@property(retain, nonatomic) NSString *sourceUrl2;    

@property(retain, nonatomic) NSMutableArray *likeUsers;    
@property(retain, nonatomic) NSMutableArray *commentUsers;    

@end

@interface WCUserComment : NSObject

@property(retain, nonatomic) NSString *commentID;    
@property(retain, nonatomic) NSString *comment64ID;    
@property(retain, nonatomic) NSString *username; //点赞用户的微信号
@property(retain, nonatomic) NSString *nickname; //点赞用户的微信昵称
@property(retain, nonatomic) NSString *content;    
@property(retain, nonatomic) NSString *refUserName;    
@property(retain, nonatomic) NSString *_dataItemUsrName;    
@property(retain, nonatomic) NSString *_dataItemNickName;    


@end




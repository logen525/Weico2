//
//  Status.h
//  Weico2
//
//  Created by qianfeng on 12-12-11.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "User.h"
#import "NSDictionaryAdditions.h"

@interface Status : NSObject
{
    time_t creatAt;
    long long statusId;
    NSNumber * statusKey;
    NSString * text;//微博信息内容
    NSString * source;//微博来源
    NSString * sourceUrl;
    BOOL favourited;//是否已收藏，true：是，false：否 
    BOOL truncated;//是否被截断，true：是，false：否 
    double latitude;
    double longitude;
    long long inReplyTostatusId;//回复ID
    int inReplyToUserId;//回复人UID 
    NSString * inReplyToScreenName;//回复人昵称
    NSString * thumbnailPic;//缩略图片地址，没有时不返回此字段 
    NSString * bmiddlePic;//中等尺寸图片地址，没有时不返回此字段 
    NSString * originalPic;//原始图片地址，没有时不返回此字段 
    User * user;//微博作者信息
    int commentsCount;//评论数
    int retweetsCount;//转发数
    Status * retweetStatus;//转发的博文，内容为status，如果不是转发，则没有此字段
    
    BOOL unread;
    BOOL hasReply;
    
    BOOL hasRetwitter;
    BOOL haveRetwitterImage;
    BOOL hasImage;
    
    NSString * _formmatedText;
}

@property (nonatomic, assign) long long     statusId;
@property (nonatomic, retain) NSNumber*		statusKey;
@property (nonatomic, assign) time_t        createdAt;
@property (nonatomic, readonly) NSString*   timestamp;
@property (nonatomic, retain) NSString*     text;
@property (nonatomic, retain) NSString*     source; 
@property (nonatomic, retain) NSString*		sourceUrl;
@property (nonatomic, assign) BOOL          favorited; //是否已收藏(正在开发中，暂不支持)
@property (nonatomic, assign) BOOL          truncated; //是否被截断
@property (nonatomic, assign) double        latitude;
@property (nonatomic, assign) double        longitude;
@property (nonatomic, assign) long long     inReplyToStatusId; //回复ID
@property (nonatomic, assign) int           inReplyToUserId; //回复人UID
@property (nonatomic, retain) NSString*     inReplyToScreenName; //回复人昵称
@property (nonatomic, retain) NSString*		thumbnailPic; //缩略图
@property (nonatomic, retain) NSString*		bmiddlePic; //中型图片
@property (nonatomic, retain) NSString*		originalPic; //原始图片
@property (nonatomic, retain) User*         user; //作者信息
@property (nonatomic, assign) int           commentsCount; //评论数
@property (nonatomic, assign) int           retweetsCount; // 转发数

@property (nonatomic, retain) Status*       retweetedStatus; //转发的博文，内容为status，如果不是转发，则没有此字段

@property (nonatomic, assign) BOOL          unread;
@property (nonatomic, assign) BOOL          hasReply;

@property (nonatomic, assign) BOOL          hasRetwitter;
@property (nonatomic, assign) BOOL          haveRetwitterImage;
@property (nonatomic, assign) BOOL          hasImage;

- (NSString*)timestamp;

- (Status*)initWithJsonDictionary:(NSDictionary*)dic;

+ (Status*)statusWithJsonDictionary:(NSDictionary*)dic;

@end

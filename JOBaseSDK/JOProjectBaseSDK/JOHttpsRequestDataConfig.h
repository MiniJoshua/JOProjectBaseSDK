//
//  JOHttpRequestDataConfig.h
//  JOProjectBaseSDK
//
//  Created by 刘维 on 15/11/26.
//  Copyright © 2015年 刘维. All rights reserved.
//

#import "JOConfig.h"
#import "JOHttpRequestType.h"

@interface JOHttpsRequestDataConfig : JOConfig

//网络请求的http的地址.
@property (nonatomic, copy) NSString *httpURLString;
//请求需要带的参数.
@property (nonatomic, copy) NSDictionary *httpPostData;
//请求的类型,是get 还是 post.
@property (nonatomic, assign) HttpRequestType httpRequestType;

/**
 *  设置网络请求的参数.
 *
 *  @param httpURLString 请求的http地址.
 *  @param postData      请求的参数.
 *  @param requestType   请求的类型: post get
 *  @param requestTag    请求的标示:唯一的.
 */
- (void)setHttpURLString:(NSString *)httpURLString
                postData:(NSDictionary *)postData
             requestType:(HttpRequestType)requestType;

/**
 *  设置网络请求的参数.ps:针对不需要传参数的网络请求.
 *
 *  @param httpURLString 请求的http地址.
 *  @param requestType   请求的类型: post get
 *  @param requestTag    请求的标示:唯一的.
 */
- (void)setHttpURLString:(NSString *)httpURLString
             requestType:(HttpRequestType)requestType;

@end

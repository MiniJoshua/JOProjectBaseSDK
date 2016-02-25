//
//  JOURLRequestDataConfig.h
//  JOProjectBaseSDK
//
//  Created by 刘维 on 15/11/26.
//  Copyright © 2015年 刘维. All rights reserved.
//

#import "JOConfig.h"

@interface JOURLRequestDataConfig : JOConfig

/*
 PS:URL的数据请求,未测试过,需要后续测试修改. 2015-11-26.
 */

//网络请求的URL的地址.
@property (nonatomic, copy) NSString *URLString;
//请求需要带的参数.
@property (nonatomic, copy) NSDictionary *postData;


/**
 *  设置网络请求的信息.
 *
 *  @param URLString 请求的URL地址.
 *  @param postData  请求的参数.
 */
- (void)setURLString:(NSString *)URLString postData:(NSDictionary *)postData;

@end

//
//  JOURLFileUploadConfig.h
//  JOProjectBaseSDK
//
//  Created by 刘维 on 15/11/26.
//  Copyright © 2015年 刘维. All rights reserved.
//

#import "JOConfig.h"

@interface JOURLFileUploadConfig : JOConfig

//要上传的文件的路径. PS:会优先取该值,若该值为空的时候,然后才会取fileData的值.
//若同时设置了这两个值,则filaData则不会被用来作为文件的数据.
@property (nonatomic, copy) NSString *filePath;
//要上传的文件的数据.
@property (nonatomic, copy) NSData *fileData;
//上传的Request.
@property (nonatomic, copy) NSURLRequest *request;
//是否是文件流的请求. 默认为NO
@property (nonatomic, assign) BOOL isStreameRequest;

/*对于文件流的形式上传的情况:
 类似于Http的请求方式
 NSMutableURLRequest *request = [[AFHTTPRequestSerializer serializer] multipartFormRequestWithMethod:@"POST" URLString:urlString parameters:postData constructingBodyWithBlock:^(id<AFMultipartFormData> formData) {
 [formData appendPartWithFileData:fileData name:@"avatar" fileName:@"avatar.jpg" mimeType:@"image/jpeg"];
 } error:nil];
 */

/*
 post为传的参数
 NSData *httpBody = nil;
 if ([NSJSONSerialization isValidJSONObject:postData]) {
 NSError *error;
 NSData *registerData = [NSJSONSerialization dataWithJSONObject:postData options:kNilOptions error:&error];
 NSString *postString = [[NSString alloc] initWithData:registerData encoding:NSUTF8StringEncoding];
 httpBody = [postString dataUsingEncoding:NSUTF8StringEncoding];
 }
 
 NSURLRequest *request = [NSURLRequest requestWithURL:[NSURL URLWithString:urlString]];
 [request setHTTPBody:httpBody];
 
 */

//是否开启断点续传的状态. ps:暂时没用,未对断点续传做任何处理.
@property (nonatomic, assign) BOOL IsOpenBreakUploadState;

/**
 *  设置上传的信息.
 *
 *  @param file     上传的文件数据. 可以为一个文件的地址或者文件的data. 二选一
 *  @param request  请求的request.
 */
- (void)setUploadFile:(id)file request:(NSURLRequest *)reqeust streameRequestState:(BOOL)isStreameRequestState;

@end

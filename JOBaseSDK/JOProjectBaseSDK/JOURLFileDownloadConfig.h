//
//  JOURLFileDownloadConfig.h
//  JOProjectBaseSDK
//
//  Created by 刘维 on 15/11/26.
//  Copyright © 2015年 刘维. All rights reserved.
//

#import "JOConfig.h"

@interface JOURLFileDownloadConfig : JOConfig

//下载的文件保存到本地的路径.
@property (nonatomic, copy) NSString *fileSavePath;
//下载的文件保存到本地的名字
@property (nonatomic, copy) NSString *fileSaveName;
//下载的Request. 是否需要根据传参来下载东西,可以在Request里面设置传参,
@property (nonatomic, copy) NSURLRequest *request;
/*
 post为传的参数
 若需要已http的形式下载的话可以参照JOURLFileUploadConfig中的设置.
 
     NSData *httpBody = nil;
     if ([NSJSONSerialization isValidJSONObject:postData]) {
         NSError *error;
         NSData *registerData = [NSJSONSerialization dataWithJSONObject:postData options:kNilOptions error:&error];
         NSString *postString = [[NSString alloc] initWithData:registerData encoding:NSUTF8StringEncoding];
         httpBody = [postString dataUsingEncoding:NSUTF8StringEncoding];
     }
     
     NSURLRequest *request = [NSURLRequest requestWithURL:[NSURL URLWithString:urlString]];  若无参数,直接设置这个就OK
     
     [request setHTTPBody:httpBody];
 
 */

//是否在下载前清空已存在的该文件. 根据给定的路径与名字来判断文件是否存在.
//YES:则会在下载前删除掉已存在的文件  NO:则不会删除.
@property (nonatomic, assign) BOOL isCleanExistFile;
//是否开启需要断点续传.下载前会自动去检查该路径下是否已经存在了缓存的文件.
//PS:与isCleanExistFile状态是互斥的.会优先检查isCleanExistFile的状态并作出相应的操作
@property (nonatomic, assign) BOOL isOpenBreakDownloadState;

/**
 *  设置文件下载的相关信息.
 *
 *  @param fileSavePath 文件保存的地址.
 *  @param fileSaveName 文件保存的名字.
 *  @param isClean      下载前是否清空已存在的文件.
 */
- (void)setFileSavePath:(NSString *)fileSavePath fileSaveName:(NSString *)fileSaveName isCleanExistFile:(BOOL)isClean;

@end

//
//  JONetRequestManage.h
//  JOProjectBaseSDK
//
//  Created by 刘维 on 15/11/16.
//  Copyright © 2015年 刘维. All rights reserved.
//

#import "JOManage.h"
#import "JSONModel.h"
#import "JOHttpRequestType.h"
#import "JOHttpsRequestDataConfig.h"
//#import "JOURLRequestDataConfig.h"
#import "JOURLFileUploadConfig.h"
#import "JOURLFileDownloadConfig.h"

typedef NS_ENUM(NSInteger,JONetworkReachabilityStatus) {

    JONetworkReachabilityStatusUnknown          = -1, //未知的网络状态.
    JONetworkReachabilityStatusNotReachable     = 0,//无任何网络
    JONetworkReachabilityStatusReachableViaWWAN = 1,//2G 3G 4G...手机运行商
    JONetworkReachabilityStatusReachableViaWiFi = 2,//Wifi
};

/**
 *  文件存在上传与下载的进度Block.
 *
 *  @param progressValue 进的的值.
 */
typedef void(^NetFileOperationProgressHandler)(CGFloat progressValue);

/**
 *  用于返回的数据的解析,传入你想要将解析后的数据模型(JSONModel)传给的对象.
 *  (其实只是使用这个对象,然后得到这个对象的类名去初始化并赋值一个对象,并返回该对象)
 *  JSONModel *(^JSONModelParseHandler) (JSONModel *josnModel)
 *
 *  @param josnModel 传入你想要赋值的JSONModel数据模型对象.
 *
 *  @return 返回解析后的数据模型.
 */
typedef id(^JSONModelParseHandler) (JSONModel *josnModel);

/**
 *  网络请求成功返回了数据,JSONModelParseHandler可以将返回的数据解析为想要的JSONModel的数据模型.
 *  可以使用:- manageMissionCompleteHandler 方法来获取返回的数据.
 *
 *  @param parseHandler JSONModelParseHandler.
 */
typedef void(^NetManageMissionSuccessHandler) (JSONModelParseHandler parseHandler);


@interface JONetRequestManage : JOManage

/**
 *  该方法用来监听整个网络的状态.网络发生改变将通过该Hanlder得到响应.
 *
 *  @param handler 网络状态更改的Handler.
 */
+ (void)networkReachabilityMonitoringHandler:(void(^)(JONetworkReachabilityStatus states))handler;

/**
 *  执行一个网络请求.
 *
 *  @param config           网络配置的类.不同的配置类代表不同的网络请求.
 *  @param progressHandler  NetFileOperationProgressHandler 文件上传或下载的进度.
 *  @param jsonModelHanler  NetManageMissionSuccessHandler 可以将网络返回得到的数据转作为你传入的数据模型对象返回.
 *                          ps:必须确保返回的数据与你给的数据模型是一一对应的,不然转换会失败.
 *  @param successHandler   MissionCompleteHandler 任务完成的回调,返回的对象为从服务器得到的数据,已转换为字典类型.
 *  @param interruptHandler MissionInterruptHandler 任务中断的回调,返回的为任务中断的原因.
 */
+ (void)startNetRequestManageWithConfig:(JOConfig *)config
                        progressHandler:(NetFileOperationProgressHandler)progressHandler
                       jsonModelHandler:(NetManageMissionSuccessHandler)jsonModelHandler
                         successHandler:(MissionCompleteHandler)successHandler
                       interruptHandler:(MissionInterruptHandler)interruptHandler;

+ (void)startNetRequestManageWithConfig:(JOConfig *)config
                         successHandler:(MissionCompleteHandler)successHandler
                       interruptHandler:(MissionInterruptHandler)interruptHandler;

+ (void)startNetRequestManageWithConfig:(JOConfig *)config
                       jsonModelHandler:(NetManageMissionSuccessHandler)jsonModelHandler
                       interruptHandler:(MissionInterruptHandler)interruptHandler;

+ (void)startNetRequestManageWithConfig:(JOConfig *)config
                       jsonModelHandler:(NetManageMissionSuccessHandler)jsonModelHandler
                         successHandler:(MissionCompleteHandler)successHandler
                       interruptHandler:(MissionInterruptHandler)interruptHandler;

+ (void)startNetRequestManageWithConfig:(JOConfig *)config
                        progressHandler:(NetFileOperationProgressHandler)progressHandler
                         successHandler:(MissionCompleteHandler)successHandler
                       interruptHandler:(MissionInterruptHandler)interruptHandler;

+ (void)startNetRequestManageWithConfig:(JOConfig *)config
                        progressHandler:(NetFileOperationProgressHandler)progressHandler
                       jsonModelHandler:(NetManageMissionSuccessHandler)jsonModelHandler
                       interruptHandler:(MissionInterruptHandler)interruptHandler;

+ (void)startNetRequestManageWithConfig:(JOConfig *)config
                        progressHandler:(NetFileOperationProgressHandler)progressHandler
                       interruptHandler:(MissionInterruptHandler)interruptHandler;


@end

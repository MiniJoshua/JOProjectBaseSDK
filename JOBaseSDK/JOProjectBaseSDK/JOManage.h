//
//  JOManage.h
//  JOProjectBaseSDK
//
//  Created by 刘维 on 15/10/23.
//  Copyright © 2015年 刘维. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JOConfig.h"
#import "JOMission.h"
#import "JODefine.h"
#import "EXTScope.h"
//@class JOMission;
/**
 *  任务都成功完成的Block.
 *
 *  @param completeObject 返回成功的对象
 *  @param completeTag   完成的tag值, 可以根据它设置不同的完成状态.
 */
typedef void (^MissionCompleteBlock)  (id completeObject, NSInteger completeTag);

/**
 *  任务执行中断的Block. 其中出现了失败的任务
 *
 *  @param interruptObject 返回中断的对象
 *  @param interruptTag   中断的tag值, 可以根据它设置不同的中断的状态.
 */
typedef void (^MissionInterruptBlock) (id interruptObject, NSInteger interruptTag);

@protocol Manage
@end

@interface JOManage : NSObject<Manage>

@property (nonatomic, strong) NSString *manageDescription;
@property (nonatomic, strong) JOConfig *config;
@property (nonatomic, copy) NSArray *missionArray;
@property (nonatomic, strong) JOMission *mission;
@property (nonatomic, copy) MissionCompleteBlock missionCompleteBlock;
@property (nonatomic, copy) MissionInterruptBlock missionInterruptBlock;

/**
 *  根据配置文件去执行一个任务. ps:如果调用此区开始执行一个任务,则需要重载cancelAllMission自己去实现任务的取消,否则达不到你取消的目的.
 *
 *  @param config 配置类
 */
- (void)startManageWithConfig:(JOConfig *)config;

- (void)startManageMission:(JOMission *)mission;

- (void)startManageMissionArray:(NSArray *)missionArray;

/**
 *  取消所有的任务.
 */
- (void)cancelAllMission;

@end

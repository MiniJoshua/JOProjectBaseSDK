//
//  JOMission.h
//  JOProjectBaseSDK
//
//  Created by 刘维 on 15/10/23.
//  Copyright © 2015年 刘维. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JOConfig;

/**
 *  任务成功执行完的Block.
 *
 *  @param successObject MissionSuccessBlock.
 */
typedef void(^MissionSuccessBlock) (id successObject);

/**
 *  任务执行失败的Block
 *
 *  @param failedObject MissionFailedBlock.
 */
typedef void(^MissionFailedBlock)  (id failedObject);

@protocol Mission
@end

@interface JOMission : NSObject<Mission>

@property (nonatomic, strong) NSString *missionDescription;
@property (nonatomic, copy) MissionSuccessBlock missionSuccessBlock;
@property (nonatomic, copy) MissionFailedBlock missionFailedBlock;

- (void)startMissionWithConfig:(JOConfig *)config;

- (void)cancelMission;

@end

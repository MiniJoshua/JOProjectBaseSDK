//
//  JOConfig.h
//  JOProjectBaseSDK
//
//  Created by 刘维 on 15/10/23.
//  Copyright © 2015年 刘维. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol Config
@end

@interface JOConfig : NSObject<Config>

@property (nonatomic, strong) NSString *configDescription;

@end

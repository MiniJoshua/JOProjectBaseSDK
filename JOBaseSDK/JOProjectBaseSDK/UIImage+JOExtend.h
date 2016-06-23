//
//  UIImage+JOExtend.h
//  JOProjectBaseSDK
//
//  Created by 刘维 on 16/6/23.
//  Copyright © 2016年 刘维. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage(Extend)

/**
 *  获取view的截图.
 *
 *  @param view 需要截图的View
 *
 *  @return 截图
 */
+ (UIImage *)JOImageWithView:(UIView *)view;

@end

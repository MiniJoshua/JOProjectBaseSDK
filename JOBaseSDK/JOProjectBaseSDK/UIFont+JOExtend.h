//
//  UIFont+JOExtend.h
//  JOProjectBaseSDK
//
//  Created by 刘维 on 16/6/23.
//  Copyright © 2016年 刘维. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JOMacro.h"

@interface JOFont : NSObject{
    
@public
    NSString *name;
    UIColor *color;
    UIFont *font;
    CGFloat size;
}

@end

@interface UIFont(Extend)

JO_EXTERN JOFont * JOFontMake(NSString *fontName,UIColor *fontColor,CGFloat fontSize);

JO_EXTERN JOFont * JOFontsMake(UIFont *font, UIColor *fontColor);

@end

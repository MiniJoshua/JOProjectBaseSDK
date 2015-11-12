//
//  JODefine.h
//  JOProjectBaseSDK
//
//  Created by 刘维 on 15/10/23.
//  Copyright © 2015年 刘维. All rights reserved.
//

#ifndef JODefine_h
#define JODefine_h

//|----------------------------------|
//|---------Create RGB Color---------|
//|----------------------------------|
#define Create_Color(r,g,b,a)   [UIColor colorWithRed:r/255. green:g/255. blue:b/255. alpha:a]
#define Create_Color_Same(r)    [UIColor colorWithRed:r/255. green:r/255. blue:r/255. alpha:1.]

//|----------------------------|
//|---------View Frame---------|
//|----------------------------|

#define View_Origin(v)      v.frame.origin
#define View_Size(v)        v.frame.size
#define View_X(v)           v.frame.origin.x
#define View_Y(v)           v.frame.origin.y
#define View_Width(v)       v.frame.size.width
#define View_Height(v)      v.frame.size.height
#define View_Bottom_Y(v)    v.frame.origin.y+v.frame.size.height
#define View_Right_X(v)     v.frame.origin.x+v.frame.size.width

//|----------------------------------|
//|---------Localized String---------|
//|----------------------------------|
#define LS(key)             NSLocalizedString(key, nil)

//|-----------------------|
//|---------Block---------|
//|-----------------------|

/*
 __weak typeof(self) weakSelf = self; //Block的外部先weak self
 __strong typeof(weakSelf) strongSelf = weakSelf;//Block的内部再strong self 这个主要是为了避免block还没完成self就被释放了而引起问题
 
 Block_WeakSelf weakSelf =  self;
 Block_StrongObject(weakSelf) strongSelf =  weakSelf;
 */
#define Block_Variable              __block
#define Block_WeakSelf_MRC          __block typeof(self) //非ARC
#define Block_WeakSelf              __weak typeof(self)  //ARC
#define Block_StrongObject(object)  __strong typeof(object)

//|---------------------|
//|---------LOG---------|
//|---------------------|
#ifdef DEBUG
#define JOLog(...) NSLog(__VA_ARGS__)
#define JOMethod() NSLog(@"%s", __func__)
#else
#define JOLog(...)
#define JOMethod()
#endif

//|-------------------------------------------|
//|---------ARG Check is nil : Assert---------|
//|-------------------------------------------|

#define JOArgumentsAssertNotNil(condition, description, ...) NSAssert(condition, description, ##__VA_ARGS__)

//|--------------------------------|
//|---------String Convert---------|
//|--------------------------------|
/*
 若一个字符串为空或者nil,将其转换为@""的字符串
 */
#define JOConvertSpecialString(str) (![str isEqual:[NSNull null]] && str)? str : @""

//|--------------------------|
//|---------Extern c---------|
//|--------------------------|

#ifdef __cplusplus
#define JO_EXTERN		extern "C" __attribute__((visibility ("default")))
#else
#define JO_EXTERN	    extern __attribute__((visibility ("default")))
#endif

//|------------------------|
//|---------Inline---------|
//|------------------------|

#define JO_STATIC_INLINE	static inline

#endif /* JODefine_h */

//
//  JOFDataBaseProperty.h
//  JOProjectBaseSDK
//
//  Created by 刘维 on 15/10/27.
//  Copyright © 2015年 刘维. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JOFDataBaseProperty : NSObject

@property (nonatomic, copy) NSString *DBName;//DB的名字  若是给定名字,则默认DB实在document文件夹中
@property (nonatomic, copy) NSString *DBPath;//DB的路径

@property (nonatomic, copy) NSString *tableName;//表的名字

@property (nonatomic, copy) NSArray<NSString *>  *columnArray;//表中字段的数组

//字典的类型 对应columnArray的Index的值作为key,对应的value为需要设置的类型.默认都为TEXT类型. 若无特殊需要设置的类型,则可以不用管它,里面都会被默认置为TEXT类型
@property (nonatomic, copy) NSDictionary *columnTypeInfo;//字段的类型

@property (nonatomic, copy) NSString *selectedColumnKey;//需要所有某个字段下面的数据时候.

@property (nonatomic, copy) NSDictionary *insertDataInfo;//需要插入的一条数据,vaule为需要插入的值,key为表中的字段名.
@property (nonatomic, copy) NSArray<NSDictionary *> *insertDataArray;//插入多条数据,内容为insertDataInfo格式的字典类型.

@property (nonatomic, copy) NSDictionary *updateDataInfo;//需要更新的一条数据,value为需要更新的值,key为表中对应的字段名.

@end

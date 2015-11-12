//
//  JOFDataBase.h
//  JOProjectBaseSDK
//
//  Created by 刘维 on 15/10/26.
//  Copyright © 2015年 刘维. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JOFDataBase : NSObject

/**
 *  初始化操作.
 *
 *  @param path DB的路径.
 *
 *  @return JOFDataBase的对象.
 */
- (instancetype)initWithDBPath:(NSString *)path;

/**
 *  改变DB文件的路径.
 *
 *  @param path 新的db文件的路径.
 */
- (void)changeDBPath:(NSString *)path;

/**
 *  获得当前DB操作可用的状态.
 *
 *  @return 可用的状态,根据是否给定了DB的路径来判定的,若不可用则说明当前DB的路径位给定.
 */
- (BOOL)dataBaseExecuteAvailableState;

/**
 *  检测table表是否已经存在.
 *
 *  @param SQLString 检测table是否存在的SQL语句.
 *
 *  @return 存在的状态.
 */
- (BOOL)tableExistStateWithSQLString:(NSString *)SQLString;

/**
 *  数据库执行操作.
 *
 *  @param SQLString 数据库操作的SQL语句.
 *
 *  @return 执行完成的状态  YES:成功  NO: 失败.
 */
- (BOOL)databaseExecuteSQLString:(NSString *)SQLString;

/**
 *  数据库执行查询操作.
 *
 *  @param SQLString   数据库操作的SQL语句.
 *  @param columnArray 字段的数组.
 *  @param columnKey   需要查询某个特定的字段的key.
 *
 *  @return 符合结果的数组.
 */
- (NSMutableArray *)databaseExecuteSelectedDataSQLString:(NSString *)SQLString columnArray:(NSArray *)columnArray columnKey:(NSString *)columnKey;

@end

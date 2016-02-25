//
//  JOFDataBaseSQL.h
//  JOProjectBaseSDK
//
//  Created by 刘维 on 15/10/27.
//  Copyright © 2015年 刘维. All rights reserved.
//

#import "JOFunctionObject.h"
#import "JOFDataBaseProperty.h"

typedef NS_ENUM(NSInteger, ExectueType){

    ExectueType_Default,//除查询之外的数据操作.
    ExectueType_Insert,//插入数据.
    ExectueType_Delete,//删除数据.
    ExectueType_Update,//更新数据.
    ExectueType_Selected,//仅仅是查的数据操作.
    ExectueType_Drop,//删除表.
};

NS_ASSUME_NONNULL_BEGIN

/**
 *  除查询操作之外的其他操作执行完成的block回调.
 *
 *  @param state 执行的状态 YES 成功 NO 失败.
 */
typedef void(^DBExecuteCompleteHandler)(BOOL state);

/**
 *  查询操作执行完的block回调.
 *
 *  @param resultArray 查询得到的结果.
 *  @param state       执行的状态 YES 成功 NO 失败.
 */
typedef void(^DBSelectExecuteCompleteHandler)(NSMutableArray <NSDictionary*> *resultArray);


@interface JOFDataBaseSQL : JOFunctionObject

/**
 *  设置当前的数据库操作的信息.
 *
 *  @param dataBaseProperty JOFDataBaseProperty.
 */
- (void)setCurrentDataBaseProperty:(JOFDataBaseProperty *)dataBaseProperty;

/**
 *  根据dataBaseProperty的信息创建一个Table表.
 */
- (void)createTable;

/**
 *  根据dataBaseProperty的信息检查Table表是否存在.
 */
- (BOOL)tableExist;

/**
 *  根据dataBaseProperty的信息插入一条数据到数据库中.
 */
- (void)insertOneDataToTable;

/**
 *  根据dataBaseProperty的信息出入多条数据到数据库中.
 */
- (void)insertArrayDataToTable;

/**
 *  根据dataBaseProperty的信息查找表中所有的数据.
 */
- (void)selectedAllDataFromTable;

/**
 *  根据dataBaseProperty的信息查找当前符合条件的数据.
 *
 *  @param conditionString 查询的条件.
 */
- (void)selectedDataWithConditionString:(NSString *)conditionString;

/**
 *  根据dataBaseProperty的信息删除表中所有的数据.
 */
- (void)deleteAllData;

/**
 *  根据dataBaseProperty的信息删除表中符合条件的数据.
 *
 *  @param conditionString 条件语句.
 */
- (void)deleteDataWithConditionString:(NSString *)conditionString;

/**
 *  根据dataBaseProperty的信息删除Table表.
 */
- (void)deleteTable;

/**
 *  根据dataBaseProperty的信息更新表中符合条件的一条数据
 *
 *  @param conditionString 条件 e.g : C2 = '4'.
 */
- (void)updateTableOneDataWithConditionString:(NSString *)conditionString;

#pragma mark - Block

/**
 *  除查询外的数据库操作完成的block回调.
 *
 *  @param sendBlock DBExecuteCompleteBlock.
 */
- (void)dataBaseExecuteCompleteHandler:(DBExecuteCompleteHandler)handler;

/**
 *  查询的数据库操作完成的block回调.
 *
 *  @param sendBlock DBSelectExecuteCompleteBlock.
 */
- (void)dataBaseSelectExecuteCompleteHandler:(DBSelectExecuteCompleteHandler)handler;

@end
NS_ASSUME_NONNULL_END

//
//  RXUIKitService.h
//  RXUIKit
//
//  Created by 陈汉 on 2022/2/19.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RXUserInfoModel.h"
#import <RXSDK_Pure/RXSDK_Pure.h>
#import "RXUICommonRequestError.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    AntiBtnType_logout, // 退出登录
    AntiBtnType_default // 知道了
} AntiBtnType; // 防沉迷按钮类型

@interface RXUIKitService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 调用登录弹窗
 * @param accounts 要展示的登录方式，按照数组顺序展示
 * @param clickAddAccount 点击"注册/添加账号"回调
 * @param loginType 点击的登陆方式
 */
- (void)setLoginViewWithAccounts:(NSMutableArray <RXUserInfoModel *> *)accounts
                 clickAddAccount:(void(^)(void))clickAddAccount
                       loginType:(void(^)(LoginType loginType))loginType;

// 关闭登陆弹窗
- (void)closeLoginView;

/**
 * 注册/添加账号
 * @param extDic 扩展字段，可传nil
 * @param isSelect 协议是否勾选
 */
- (void)setAddAccountViewWithIsSelect:(BOOL)isSelect
                               extDic:(NSMutableDictionary * _Nullable)extDic
                             complete:(void(^)(BOOL success, NSString *username, NSString *password))complete;

/**
 * 单条协议弹框
 * @param complete isAgree YES 同意  NO 不同意
 */
- (void)setProtocolViewWithKey:(NSString *)key
                      complete:(void(^)(BOOL isAgree))complete;

/**
 * 声明（所有协议）
 * @param key 默认展示的条款key
 */
- (void)setPrivacyViewWithKey:(NSString *)key;

/**
 * 实名认证
 */
- (void)setApproveViewWithComplete:(void(^)(NSDictionary *backData, RXUICommonRequestError *error))complete;

/**
 * 防沉迷弹框
 * @param title 标题
 * @param des 内容
 * @param type 按钮类型   AntiBtnType_logout按钮为退出游戏，点击后关闭进程   AntiBtnType_default按钮为知道了，点击后block回调
 */
- (void)setAntiAdditionViewWithTitle:(NSString *)title
                                 des:(NSString *)des
                                type:(AntiBtnType)type
                            complete:(void(^)(void))complete;

/**
 * 权限弹框
 * @param keys 要展示的权限key 传空展示所有权限
 * @param clickBlock 点击事件回调   status 0拒绝  1同意
 */
- (void)setLimitViewWithKeys:(NSArray * _Nullable)keys
                  clickBlock:(void(^)(NSInteger status))clickBlock;

/**
 * 绑定手机
 */
- (void)bindingPhoneWithComplete:(void(^)(NSDictionary *response, RXUICommonRequestError *error))complete;

/**
 * 查询注销状态
 */
- (void)destroyAccountStatusView;

@end

NS_ASSUME_NONNULL_END

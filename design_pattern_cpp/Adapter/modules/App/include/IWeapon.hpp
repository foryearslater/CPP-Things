#pragma once
#include <string>

/**
 * @class IWeapon
 * @brief 武器接口。
 * @detail 定义了所有武器都必须实现的基本操作
 */

class IWeapon 
{
public:
   
    virtual ~IWeapon() = default;

    /**
     * @brief 执行武器攻击动作
     * @param target 攻击的目标名称
     * @return 描述攻击结果的字符串
     */

    virtual std::string Attack(const std::string& target) const = 0;

};
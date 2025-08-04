#pragma once
#include <string>

/**
 * @class OldSword
 * @brief 旧系统中的剑类
 * @detail 具有特定的旧接口，需要适配才能在新系统中使用, 它的功能是 "挥舞" (Swing)，而不是 "攻击" (Attack)
 */
class OldSword 
{
public:
 
    OldSword();

    ~OldSword();

    /**
     * @brief 挥舞剑的动作
     * @param enemy 挥舞的目标敌人名称
     * @return 描述挥舞剑动作的字符串
     */

    std::string Swing(const std::string& enemy) const;

};
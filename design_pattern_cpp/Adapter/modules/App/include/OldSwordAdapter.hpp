#pragma once
#include "IWeapon.hpp"      
#include "OldSword.hpp"    

/**
 * @class OldSwordAdapter
 * @brief 适配器：将OldSword的接口适配到IWeapon接口
 * @detail 实现了IWeapon接口，但在内部使用OldSword的方法来完成操作
 */

class OldSwordAdapter : public IWeapon 
{
public:
  
    explicit OldSwordAdapter(OldSword* oldSword); 

    ~OldSwordAdapter() override;

    /**
     * @brief 实现IWeapon::Attack接口
     * @detail 在内部调用OldSword::Swing方法来完成攻击行为
     * @param target 攻击的目标名称
     * @return 描述适配后攻击结果的字符串
     */

    std::string Attack(const std::string& target) const override;

private:

    OldSword* m_oldSword; 

};
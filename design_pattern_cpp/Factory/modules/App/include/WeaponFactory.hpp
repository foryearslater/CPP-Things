#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Weapon.hpp"
#include "Sword.hpp"
#include "Bow.hpp"

/**
 * @class WeaponFactory
 * @brief 简单工厂：负责创建各种Weapon对象。
 *
 * @detail这个工厂类集中了所有武器对象的创建逻辑。客户端通过调用其静态方法
 * 并传入类型参数来获取所需的武器。
 */
class WeaponFactory {
public:
    /**
    * @brief 根据指定的武器类型创建武器对象。
    *
    * @param type 一个字符串，指定要创建的武器类型
    * @return 返回指向所创建Weapon对象的指针，如果类型未知则返回nullptr。
    */
    static Weapon* createWeapon(const std::string& type) 
    {
        if (type == "sword") 
        {
            std::cout << "WeaponFactory is creating a Sword..." << std::endl;
            return new Sword();
        } 
        else if (type == "bow") 
        {
            std::cout << "WeaponFactory is creating a Bow..." << std::endl;
            return new Bow();
        } else 
        {
            std::cerr << "Error: Unknown weapon type '" << type << "'." << std::endl;
            return nullptr; // 抛出异常
        }
    }
};
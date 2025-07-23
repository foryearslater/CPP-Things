#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Weapon.hpp"

/**
 * @class Sword
 * @brief 具体产品：表示一个剑武器。
 *
 * @detail s实现了Weapon接口，定义了剑的特定使用行为。
 */
class Sword : public Weapon {
public:
    void use() override 
    {
        std::cout << "Using Sword: Swish! Slash! Deal close combat damage." << std::endl;
    }
    ~Sword() 
    {
        std::cout << "Sword destructor called." << std::endl;
    }
};
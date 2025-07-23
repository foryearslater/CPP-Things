#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Weapon.hpp"

/**
 * @class Bow
 * @brief 具体产品：表示一个弓武器。
 *
 * @detail 实现了Weapon接口，定义了弓的特定使用行为。
 */
class Bow : public Weapon {
public:
    void use() override 
    {
        std::cout << "Using Bow: Twang! Thwack! Deal long-range damage." << std::endl;
    }
    ~Bow() 
    {
        std::cout << "Bow destructor called." << std::endl;
    }
};
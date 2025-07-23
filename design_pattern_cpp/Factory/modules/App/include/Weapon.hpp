#pragma once

#include <iostream>
#include <vector>
#include <string>

/**
 * @class Weapon
 * @brief 抽象产品：定义所有武器的通用接口。
 *
 * @detail 所有具体的武器类都将继承此接口，并实现其纯虚函数。
 */
class Weapon
{
public:
   /**
    * @brief 使用武器的纯虚方法。
    *
    * @detail 具体的武器类必须实现此方法，来定义如何“使用”该武器。
    */
    virtual void use() = 0;
    virtual ~Weapon()
    {
        std::cout << "Weapon destructor called." << std::endl;
    }
};
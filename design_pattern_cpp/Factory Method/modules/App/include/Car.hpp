#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include <string>
#include <memory> 

/**
 * @class Car
 * @brief 抽象产品：定义了所有汽车产品共有的接口。
 *
 * @detail 作为汽车产品层次结构的基类，声明了所有具体汽车必须实现的纯虚函数。
 *         这确保了所有汽车都具备组装、喷漆、试驾和显示信息的基本能力。
 */
class Car 
{
public:
    /**
     * @brief 纯虚函数：组装汽车。
     * @detail 
     */

    virtual void Assemble() const = 0;

    /**
     * @brief 纯虚函数：为汽车喷漆。
     * @detail 
     */

    virtual void Paint() const = 0;

    /**
     * @brief 纯虚函数：试驾汽车。
     * @detail 
     */

    virtual void TestDrive() const = 0;

    /**
     * @brief 纯虚函数：显示汽车信息。
     * @detail 
     */

    virtual void ShowInfo() const = 0;

    /**
     * @brief 虚析构函数。
     * @detail 
     *       
     */

    virtual ~Car() 
    {
        std::cout << "Car destructor called.\n";
    }
};

#endif // CAR_HPP
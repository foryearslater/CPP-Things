#include "SUVCarFactory.hpp"  
#include "SUVCar.hpp"       


/**
 * @brief 覆盖抽象工厂方法：创建一辆SUV。
 * @detail 返回一个新的SUVCar智能指针实例。
 *         这是SUV工厂的核心创建方法。
 * @return std::unique_ptr<Car> 指向新创建的SUV对象的智能指针。
 */

std::unique_ptr<Car> SUVCarFactory::CreateCar() 
{
    std::cout << "SUV工厂：正在创建一辆SUV...\n";
    return std::make_unique<SUVCar>();
}
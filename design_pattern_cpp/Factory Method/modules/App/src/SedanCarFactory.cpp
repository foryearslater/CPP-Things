#include "SedanCarFactory.hpp" 
#include "SedanCar.hpp"       


/**
 * @brief 覆盖抽象工厂方法：创建一辆轿车。
 * @detail 返回一个新的SedanCar智能指针实例。
 *         这个方法是工厂方法模式的核心，负责具体产品的实例化。
 * @return std::unique_ptr<Car> 指向新创建的轿车对象的智能指针。
 */

std::unique_ptr<Car> SedanCarFactory::CreateCar() 
{
    std::cout << "轿车工厂：正在创建一辆轿车...\n";
    return std::make_unique<SedanCar>();
}
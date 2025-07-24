#include "TruckCarFactory.hpp" 
#include "TruckCar.hpp"      


/**
 * @brief 覆盖抽象工厂方法：创建一辆卡车。
 * @detail 返回一个新的TruckCar智能指针实例。
 *         这是卡车工厂的核心创建方法。
 * @return std::unique_ptr<Car> 指向新创建的卡车对象的智能指针。
 */

std::unique_ptr<Car> TruckCarFactory::CreateCar() 
{
    std::cout << "卡车工厂：正在创建一辆卡车...\n";
    return std::make_unique<TruckCar>();
}
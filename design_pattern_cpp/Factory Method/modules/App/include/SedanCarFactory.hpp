#ifndef SEDAN_CAR_FACTORY_HPP
#define SEDAN_CAR_FACTORY_HPP

#include "CarFactory.hpp" 
#include "SedanCar.hpp"   
    

/**
 * @class SedanCarFactory
 * @brief 具体工厂：专门负责生产轿车。
 *
 * @detail 继承自CarFactory，并实现了createCar()工厂方法，
 *         返回一个SedanCar的具体实例。
 */

class SedanCarFactory : public CarFactory 
{
public:

    /**
     * @brief 覆盖抽象工厂方法：创建一辆轿车。
     * @detail 返回一个新的SedanCar智能指针实例。
     * @return std::unique_ptr<Car> 指向新创建的轿车对象的智能指针。
     */

    std::unique_ptr<Car> CreateCar() override;

    /**
     * @brief 轿车工厂析构函数。
     * @detail 在轿车工厂对象被销毁时调用。
     */

    ~SedanCarFactory() override 
    {
        std::cout << "SedanCarFactory destructor called.\n";
    }
};

#endif // SEDAN_CAR_FACTORY_HPP
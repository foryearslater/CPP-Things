// SUVCarFactory.h - 具体工厂：SUV工厂
#ifndef SUV_CAR_FACTORY_HPP
#define SUV_CAR_FACTORY_HPP

#include "CarFactory.hpp"
#include "SUVCar.hpp"

/**
 * @class SUVCarFactory
 * @brief 具体工厂：专门负责生产SUV。
 *
 * @detail 继承自CarFactory，并实现了createCar()工厂方法，
 *         返回一个SUVCar的具体实例。
 */
class SUVCarFactory : public CarFactory 
{
public:
    /**
     * @brief 覆盖抽象工厂方法：创建一辆SUV。
     * @detail 返回一个新的SUVCar智能指针实例。
     * @return std::unique_ptr<Car> 指向新创建的SUV对象的智能指针。
     */

    std::unique_ptr<Car> CreateCar() override;

    /**
     * @brief SUV工厂析构函数。
     * @detail 在SUV工厂对象被销毁时调用。
     */

    ~SUVCarFactory() override 
    {
        std::cout << "SUVCarFactory destructor called.\n";
    }
};

#endif // SUV_CAR_FACTORY_HPP
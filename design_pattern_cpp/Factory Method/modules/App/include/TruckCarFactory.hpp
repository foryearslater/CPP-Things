// TruckCarFactory.h - 具体工厂：卡车工厂
#ifndef TRUCK_CAR_FACTORY_H
#define TRUCK_CAR_FACTORY_H

#include "CarFactory.hpp"
#include "TruckCar.hpp"
#include <memory>

/**
 * @class TruckCarFactory
 * @brief 具体工厂：专门负责生产卡车。
 *
 * @detail 继承自CarFactory，并实现了createCar()工厂方法，
 *         返回一个TruckCar的具体实例。
 */

class TruckCarFactory : public CarFactory {
public:

    /**
     * @brief 覆盖抽象工厂方法：创建一辆卡车。
     * @detail 返回一个新的TruckCar智能指针实例。
     * @return std::unique_ptr<Car> 指向新创建的卡车对象的智能指针。
     */

    std::unique_ptr<Car> CreateCar() override;

    /**
     * @brief 卡车工厂析构函数。
     * @detail 在卡车工厂对象被销毁时调用。
     */

    ~TruckCarFactory() override 
    {
        std::cout << "TruckCarFactory destructor called.\n";
    }

};

#endif // TRUCK_CAR_FACTORY_H
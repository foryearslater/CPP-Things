#ifndef CAR_FACTORY_HPP
#define CAR_FACTORY_HPP

#include "Car.hpp"

#include <memory> 
#include <iostream>

/**
 * @class CarFactory
 * @brief 抽象工厂：定义了创建汽车产品的工厂方法接口。
 *
 * @detail 作为汽车工厂层次结构的基类，声明了纯虚函数 createCar()，
 *         该函数返回一个抽象产品类型的智能指针。
 *         还包含了一个通用的 produceCar() 方法，定义了汽车的生产流程。
 */

class CarFactory 
{
public:
    /**
     * @brief 抽象工厂方法：创建一辆汽车。
     * @detail 这是一个纯虚函数，由具体工厂子类实现。
     *         每个具体工厂会实现此方法来创建并返回特定类型的 Car 对象。
     * @return std::unique_ptr<Car> 一个指向抽象 Car 产品的智能指针。
     */

    virtual std::unique_ptr<Car> CreateCar() = 0;

    /**
     * @brief 通用的汽车生产流程。
     * @detail 定义了汽车从创建到组装、喷漆、试驾的完整生产流程。
     *         客户端通常调用此方法来获取产品，而无需直接调用 createCar()。
     *         该方法内部调用了抽象的 createCar() 方法来实现多态创建。
     * @return std::unique_ptr<Car> 一个指向已生产完成的汽车产品的智能指针。
     */

    std::unique_ptr<Car> ProduceCar() 
    {
       // std::cout << "\n--- 开始生产新车 ---\n";
        std::unique_ptr<Car> car = CreateCar();
        car->Assemble();
        car->Paint();
        car->TestDrive();
     //   std::cout << "--- 新车生产完成 ---\n";
        return car;
    }

    /**
     * @brief 虚析构函数。
     * @detail 确保通过基类指针删除派生类工厂对象时，能够正确调用派生类的析构函数。
     */

    virtual ~CarFactory() 
    {
        std::cout << "CarFactory destructor called.\n";
    }
};

#endif // CAR_FACTORY_HPP
// TruckCar.h - 具体产品：卡车
#ifndef TRUCK_CAR_HPP
#define TRUCK_CAR_HPP

#include "Car.hpp"

/**
 * @class TruckCar
 * @brief 具体产品：表示一辆卡车。
 *
 * @detail 实现了Car接口，定义了卡车特有的组装、喷漆、试驾和信息显示行为。
 * 
 */
class TruckCar : public Car 
{
public:
    /**
     * @brief 覆盖基类函数：组装卡车。
     * @detail 具体实现了卡车的组装过程，例如安装重型底盘、货厢等。
     */
    void Assemble() const override;

    /**
     * @brief 覆盖基类函数：为卡车喷漆。
     * @detail 具体实现了卡车的喷漆过程，例如使用坚固耐用色系。
     */
    void Paint() const override;

    /**
     * @brief 覆盖基类函数：试驾卡车。
     * @detail 具体实现了卡车的试驾行为，强调载重能力强。
     */
    void TestDrive() const override;

    /**
     * @brief 覆盖基类函数：显示卡车信息。
     * @detail 显示卡车的详细信息和特点。
     */
    void ShowInfo() const override;

    /**
     * @brief 卡车析构函数。
     * @detail 
     */
    ~TruckCar() override 
    {
        std::cout << "TruckCar destructor called.\n";
    }
};

#endif // TRUCK_CAR_HPP
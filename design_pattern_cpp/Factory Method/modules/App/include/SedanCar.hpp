#ifndef SEDAN_CAR_HPP
#define SEDAN_CAR_HPP

#include "Car.hpp" 

/**
 * @class SedanCar
 * @brief 具体产品：表示一辆轿车。
 *
 * @detail 实现了Car接口，定义了轿车特有的组装、喷漆、试驾和信息显示行为。
 *         轿车以其流线型外观和舒适的乘坐体验为特点。
 */
class SedanCar : public Car 
{
public:
    /**
     * @brief 覆盖基类函数：组装轿车。
     * @detail 具体实现了轿车的组装过程，例如安装座椅、内饰等。
     */
    void Assemble() const override;

    /**
     * @brief 覆盖基类函数：为轿车喷漆。
     * @detail 具体实现了轿车的喷漆过程，例如使用经典雅致色系。
     */
    void Paint() const override;

    /**
     * @brief 覆盖基类函数：试驾轿车。
     * @detail 具体实现了轿车的试驾行为，强调平稳舒适和城市通勤特性。
     */
    void TestDrive() const override;

    /**
     * @brief 覆盖基类函数：显示轿车信息。
     * @detail 显示轿车的详细信息和特点。
     */
    void ShowInfo() const override;

    /**
     * @brief 轿车析构函数。
     * @detail 在轿车对象被销毁时调用。
     */
    ~SedanCar() override 
    {
        std::cout << "SedanCar destructor called.\n";
    }
};

#endif // SEDAN_CAR_HPP
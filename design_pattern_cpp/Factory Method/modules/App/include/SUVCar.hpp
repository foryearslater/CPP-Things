#ifndef SUV_CAR_HPP
#define SUV_CAR_HPP

#include "Car.hpp"

/**
 * @class SUVCar
 * @brief 具体产品：表示一辆SUV。
 *
 * @detail 实现了Car接口，定义了SUV特有的组装、喷漆、试驾和信息显示行为。
 *       
 */
class SUVCar : public Car 
{
public:
    /**
     * @brief 覆盖基类函数：组装SUV。
     * @detail 具体实现了SUV的组装过程，例如安装越野轮胎、加固底盘等。
     */
    void Assemble() const override;

    /**
     * @brief 覆盖基类函数：为SUV喷漆。
     * @detail 具体实现了SUV的喷漆过程，例如使用动感越野色系。
     */
    void Paint() const override;

    /**
     * @brief 覆盖基类函数：试驾SUV。
     * @detail 具体实现了SUV的试驾行为，强调动力强劲和通过性好。
     */
    void TestDrive() const override;

    /**
     * @brief 覆盖基类函数：显示SUV信息。
     * @detail 显示SUV的详细信息和特点。
     */
    void ShowInfo() const override;

    /**
     * @brief SUV析构函数。
     * @detail 
     */
    ~SUVCar() override 
    {
        std::cout << "SUVCar destructor called.\n";
    }
};

#endif // SUV_CAR_HPP
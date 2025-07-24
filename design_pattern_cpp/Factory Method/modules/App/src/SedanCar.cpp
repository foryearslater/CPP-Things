#include "SedanCar.hpp"   
#include <iostream>     

/**
 * @brief 覆盖基类函数：组装轿车。
 * @detail 具体实现等。
 */

void SedanCar::Assemble() const 
{
    std::cout << "正在组装轿车：安装座椅、内饰...🚗\n";
}

/**
 * @brief 覆盖基类函数：为轿车喷漆。
 * @detail 具体实现了轿车的喷漆过程，例如使用经典雅致色系。
 */

void SedanCar::Paint() const 
{
    std::cout << "正在为轿车喷漆：经典雅致色系...🎨\n";
}

/**
 * @brief 覆盖基类函数：试驾轿车。
 * @detail 具体实现了轿车的试驾行为，强调平稳舒适和城市通勤特性。
 */

void SedanCar::TestDrive() const 
{
    std::cout << "正在试驾轿车：平稳舒适，适合城市通勤。🛣️\n";
}

/**
 * @brief 覆盖基类函数：显示轿车信息。
 * @detail 显示轿车的详细信息和特点。
 */

void SedanCar::ShowInfo() const 
{
    std::cout << "这是一辆轿车，特点是流线型外观和舒适的乘坐体验。\n";
}
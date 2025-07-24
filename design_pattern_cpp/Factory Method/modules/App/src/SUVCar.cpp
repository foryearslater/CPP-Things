#include "SUVCar.hpp"   
#include <iostream>     

/**
 * @brief 覆盖基类函数：组装SUV。
 * @detail 具体实现了SUV的组装过程，例如安装越野轮胎、加固底盘等。
 */

void SUVCar::Assemble() const 
{
    std::cout << "正在组装SUV：安装越野轮胎、加固底盘...🚙\n";
}

/**
 * @brief 覆盖基类函数：为SUV喷漆。
 * @detail 具体实现了SUV的喷漆过程，例如使用动感越野色系。
 */

void SUVCar::Paint() const 
{
    std::cout << "正在为SUV喷漆：动感越野色系...🎨\n";
}

/**
 * @brief 覆盖基类函数：试驾SUV。
 * @detail 具体实现了SUV的试驾行为，强调动力强劲和通过性好。
 */

void SUVCar::TestDrive() const 
{
    std::cout << "正在试驾SUV：动力强劲，通过性好，适合多种路况。🏔️\n";
}

/**
 * @brief 覆盖基类函数：显示SUV信息。
 * @detail 显示SUV的详细信息和特点。
 */

void SUVCar::ShowInfo() const 
{
    std::cout << "这是一辆SUV，特点是宽敞空间和良好的越野性能。\n";
}
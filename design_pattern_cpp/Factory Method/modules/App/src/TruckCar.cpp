#include "TruckCar.hpp"     

/**
 * @brief 覆盖基类函数：组装卡车。
 * @detail 具体实现了卡车的组装过程，例如安装重型底盘、货厢等。
 */

void TruckCar::Assemble() const 
{
    std::cout << "正在组装卡车：安装重型底盘、货厢...🚚\n";
}

/**
 * @brief 覆盖基类函数：为卡车喷漆。
 * @detail 具体实现了卡车的喷漆过程，例如使用坚固耐用色系。
 */

void TruckCar::Paint() const 
{
    std::cout << "正在为卡车喷漆：坚固耐用色系...🎨\n";
}

/**
 * @brief 覆盖基类函数：试驾卡车。
 * @detail 具体实现了卡车的试驾行为，强调载重能力强。
 */

void TruckCar::TestDrive() const 
{
    std::cout << "正在试驾卡车：载重能力强，适合货物运输。🏗️\n";
}

/**
 * @brief 覆盖基类函数：显示卡车信息。
 * @detail 显示卡车的详细信息和特点。
 */

void TruckCar::ShowInfo() const 
{
    std::cout << "这是一辆卡车，特点是超强的载重能力和耐用性。\n";
}
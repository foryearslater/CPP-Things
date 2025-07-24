#include "TruckCarFactory.hpp" 
#include "TruckCar.hpp"      


/**
 * @brief ���ǳ��󹤳�����������һ��������
 * @detail ����һ���µ�TruckCar����ָ��ʵ����
 *         ���ǿ��������ĺ��Ĵ���������
 * @return std::unique_ptr<Car> ָ���´����Ŀ������������ָ�롣
 */

std::unique_ptr<Car> TruckCarFactory::CreateCar() 
{
    std::cout << "�������������ڴ���һ������...\n";
    return std::make_unique<TruckCar>();
}
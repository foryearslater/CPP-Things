#include "SUVCarFactory.hpp"  
#include "SUVCar.hpp"       


/**
 * @brief ���ǳ��󹤳�����������һ��SUV��
 * @detail ����һ���µ�SUVCar����ָ��ʵ����
 *         ����SUV�����ĺ��Ĵ���������
 * @return std::unique_ptr<Car> ָ���´�����SUV���������ָ�롣
 */

std::unique_ptr<Car> SUVCarFactory::CreateCar() 
{
    std::cout << "SUV���������ڴ���һ��SUV...\n";
    return std::make_unique<SUVCar>();
}
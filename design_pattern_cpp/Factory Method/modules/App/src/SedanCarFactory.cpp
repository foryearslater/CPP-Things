#include "SedanCarFactory.hpp" 
#include "SedanCar.hpp"       


/**
 * @brief ���ǳ��󹤳�����������һ���γ���
 * @detail ����һ���µ�SedanCar����ָ��ʵ����
 *         ��������ǹ�������ģʽ�ĺ��ģ���������Ʒ��ʵ������
 * @return std::unique_ptr<Car> ָ���´����Ľγ����������ָ�롣
 */

std::unique_ptr<Car> SedanCarFactory::CreateCar() 
{
    std::cout << "�γ����������ڴ���һ���γ�...\n";
    return std::make_unique<SedanCar>();
}
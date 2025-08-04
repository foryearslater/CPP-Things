#include "Factory.hpp"

/**
 * @brief �ͻ��˴��룬ʹ�ó��󹤳������Ͳ����Ҿߡ�
 *
 * @param factory ����ļҾ߹���ʵ�������á�
 * @detail �ͻ���ͨ������ӿ��빤���Ͳ�Ʒ�����������ľ���ʵ�֣����磬����֪��
 *         ���ڴ�������ά�����Ƿ�����ִ����ļҾߣ���
 *         ���ڹ����������ص��� std::unique_ptr���ڴ����������ָ���Զ�����
 *         �����ֶ� delete��
 */

void clientCode(const FurnitureFactory& factory)
{
    std::cout << "\n--- �ͻ�������Ҿ� ---" << std::endl;

    std::unique_ptr<Chair> chair = factory.createChair();
    std::unique_ptr<Sofa> sofa = factory.createSofa();
    std::unique_ptr<CoffeeTable> table = factory.createCoffeeTable();

    std::cout << chair->sitOn() << std::endl;
    std::cout << sofa->lieOn() << std::endl;
    std::cout << table->placeItems() << std::endl;
    std::cout << "--- �Ҿ�������� ---" << std::endl;
}


int main() {

    VictorianFurnitureFactory victorianFactory;

    clientCode(victorianFactory);

    ModernFurnitureFactory modernFactory;

    clientCode(modernFactory);

    return 0;
}
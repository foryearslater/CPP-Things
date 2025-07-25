#include "AbFactory.hpp"
/**
 * @brief ά�����Ƿ��Ҿߵľ��幤����
 *
 * @detail ʵ����FurnitureFactory�ӿڣ�������������ά�����Ƿ��ļҾߡ�
 */
class VictorianFurnitureFactory : public FurnitureFactory 
{
public:
    /**
     * @brief ����ά�����Ƿ������ӡ�
     *
     * @return ָ��VictorianChair������ָ�롣
     */
    std::unique_ptr<Chair> createChair() const override 
    {
        return std::make_unique<VictorianChair>();
    }

    /**
     * @brief ����ά�����Ƿ���ɳ����
     *
     * @return ָ��VictorianSofa������ָ�롣
     */
    std::unique_ptr<Sofa> createSofa() const override 
    {
        return std::make_unique<VictorianSofa>();
    }

    /**
     * @brief ����ά�����Ƿ��Ĳ輸��
     *
     * @return ָ��VictorianCoffeeTable������ָ�롣
     */
    std::unique_ptr<CoffeeTable> createCoffeeTable() const override 
    {
        return std::make_unique<VictorianCoffeeTable>();
    }
};

/**
 * @brief �ִ����Ҿߵľ��幤����
 *
 * @detail ʵ����FurnitureFactory�ӿڣ��������������ִ����ļҾߡ�
 */
class ModernFurnitureFactory : public FurnitureFactory 
{
public:
    /**
     * @brief �����ִ��������ӡ�
     *
     * @return ָ��ModernChair������ָ�롣
     */
    std::unique_ptr<Chair> createChair() const override 
    {
        return std::make_unique<ModernChair>();
    }

    /**
     * @brief �����ִ�����ɳ����
     *
     * @return ָ��ModernSofa������ָ�롣
     */
    std::unique_ptr<Sofa> createSofa() const override 
    {
        return std::make_unique<ModernSofa>();
    }

    /**
     * @brief �����ִ����Ĳ輸��
     *
     * @return ָ��ModernCoffeeTable������ָ�롣
     */
    std::unique_ptr<CoffeeTable> createCoffeeTable() const override 
    {
        return std::make_unique<ModernCoffeeTable>();
    }
};

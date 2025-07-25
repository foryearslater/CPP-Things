#include "ConProducts.hpp"

/**
 * @brief ����Ҿ߹����ӿڡ�
 *
 * @detail �����˴�����ͬ���ͼҾߣ����ӡ�ɳ�����輸���ķ�����
 *         ����Ĺ�����ʵ����Щ�����������ض����ļҾ��塣
 */

class FurnitureFactory 
{
public:
    /**
     * @brief ������������
     */
    virtual ~FurnitureFactory() = default;

    /**
     * @brief �����������Ӳ�Ʒ�Ľӿڡ�
     *
     * @return ָ�����Chair������ָ�룬ȷ���ڴ��Զ�����
     */
    virtual std::unique_ptr<Chair> createChair() const = 0;

    /**
     * @brief ��������ɳ����Ʒ�Ľӿڡ�
     *
     * @return ָ�����Sofa������ָ�롣
     */
    virtual std::unique_ptr<Sofa> createSofa() const = 0;

    /**
     * @brief ���������輸��Ʒ�Ľӿڡ�
     *
     * @return ָ�����CoffeeTable������ָ�롣
     */
    virtual std::unique_ptr<CoffeeTable> createCoffeeTable() const = 0;
};
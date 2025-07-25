#include "AbProducts.hpp"
/**
 * @brief ά�����Ƿ��ľ������Ӳ�Ʒ��
 *
 * @detail ʵ���˳���Chair�ӿڣ��ṩά�����Ƿ������ӡ�
 */
class VictorianChair : public Chair 
{
public:
    /**
     * @brief ʵ��ά�����Ƿ�����ӵ�������Ϊ��
     *
     * @return ����ά�����Ƿ����������������ַ�����
     */
    std::string sitOn() const override 
    {
        return "�����ݻ���ά�����Ƿ�������ϡ�";
    }
};

/**
 * @brief ά�����Ƿ��ľ���ɳ����Ʒ��
 *
 * @detail ʵ���˳���Sofa�ӿڣ��ṩά�����Ƿ���ɳ����
 */
class VictorianSofa : public Sofa 
{
public:
    /**
     * @brief ʵ��ά�����Ƿ��ɳ����������Ϊ��
     *
     * @return ����ά�����Ƿ��ɳ������������ַ�����
     */
    std::string lieOn() const override 
    {
        return "���ڸ��ŵ�ά�����Ƿ��ɳ���ϣ�������ʷ�ĺ��ء�";
    }
};

/**
 * @brief ά�����Ƿ��ľ���輸��Ʒ��
 *
 * @detail ʵ���˳���CoffeeTable�ӿڣ��ṩά�����Ƿ��Ĳ輸��
 */
class VictorianCoffeeTable : public CoffeeTable 
{
public:
    /**
     * @brief ʵ��ά�����Ƿ��輸�ķ�����Ʒ��Ϊ��
     *
     * @return ����ά�����Ƿ��輸������Ʒ������ַ�����
     */
    std::string placeItems() const override 
    {
        return "����Ʒ���ڵ�̾�����ά�����Ƿ��輸�ϡ�";
    }
};

// --- �ִ����Ҿ� (Modern Family) ---

/**
 * @brief �ִ����ľ������Ӳ�Ʒ��
 *
 * @detail ʵ���˳���Chair�ӿڣ��ṩ�ִ��������ӡ�
 */
class ModernChair : public Chair 
{
public:
    /**
     * @brief ʵ���ִ�������ӵ�������Ϊ��
     *
     * @return �����ִ������������������ַ�����
     */
    std::string sitOn() const override 
    {
        return "���ڼ����ִ���������ϡ�";
    }
};

/**
 * @brief �ִ����ľ���ɳ����Ʒ��
 *
 * @detail ʵ���˳���Sofa�ӿڣ��ṩ�ִ�����ɳ����
 */
class ModernSofa : public Sofa 
{
public:
    /**
     * @brief ʵ���ִ����ɳ����������Ϊ��
     *
     * @return �����ִ����ɳ������������ַ�����
     */
    std::string lieOn() const override 
    {
        return "�������ʵ��ִ����ɳ���ϣ����ܼ������塣";
    }
};

/**
 * @brief �ִ����ľ���輸��Ʒ��
 *
 * @detail ʵ���˳���CoffeeTable�ӿڣ��ṩ�ִ����Ĳ輸��
 */
class ModernCoffeeTable : public CoffeeTable 
{
public:
    /**
     * @brief ʵ���ִ����輸�ķ�����Ʒ��Ϊ��
     *
     * @return �����ִ����輸������Ʒ������ַ�����
     */
    std::string placeItems() const override 
    {
        return "����Ʒ���ڹ�����ǿ���ִ����輸�ϡ�";
    }
};
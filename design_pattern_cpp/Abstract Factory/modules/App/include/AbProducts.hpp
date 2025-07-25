#include <iostream>
#include <string>
#include <memory> 

/**
 * @brief �������Ӳ�Ʒ�ӿڡ�
 *
 * @detail ����������������Ӧʵ�ֵ���Ϊ��
 *         ��Ϊ������࣬���������麯����
 */
class Chair 
{
public:
    /**
     * @brief ������������
     *
     * @detail ȷ��ͨ������ָ��ɾ�����������ʱ������ȷ����������������������ֹ�ڴ�й©��
     */
    virtual ~Chair() = default;

    /**
     * @brief ����������Ϊ�Ľӿڡ�
     *
     * @return ��ʾ����������ַ�����
     */
    virtual std::string sitOn() const = 0;
};

/**
 * @brief ����ɳ����Ʒ�ӿڡ�
 *
 * @detail ����������ɳ����Ӧʵ�ֵ���Ϊ��
 */
class Sofa 
{
public:
    /**
     * @brief ������������
     */
    virtual ~Sofa() = default;

    /**
     * @brief ����������Ϊ�Ľӿڡ�
     *
     * @return ��ʾ����������ַ�����
     */
    virtual std::string lieOn() const = 0;
};

/**
 * @brief ����輸��Ʒ�ӿڡ�
 *
 * @detail ���������в輸��Ӧʵ�ֵ���Ϊ��
 */
class CoffeeTable 
{
public:
    /**
     * @brief ������������
     */
    virtual ~CoffeeTable() = default;

    /**
     * @brief ����������Ʒ��Ϊ�Ľӿڡ�
     *
     * @return ��ʾ������Ʒ������ַ�����
     */
    virtual std::string placeItems() const = 0;
};
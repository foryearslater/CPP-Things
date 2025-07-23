#pragma once

#include <iostream>
#include <vector>
#include <string>

/**
 * @class Weapon
 * @brief �����Ʒ����������������ͨ�ýӿڡ�
 *
 * @detail ���о���������඼���̳д˽ӿڣ���ʵ���䴿�麯����
 */
class Weapon
{
public:
   /**
    * @brief ʹ�������Ĵ��鷽����
    *
    * @detail ��������������ʵ�ִ˷�������������Ρ�ʹ�á���������
    */
    virtual void use() = 0;
    virtual ~Weapon()
    {
        std::cout << "Weapon destructor called." << std::endl;
    }
};
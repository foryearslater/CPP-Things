#include "ConProducts.hpp"

/**
 * @brief 抽象家具工厂接口。
 *
 * @detail 定义了创建不同类型家具（椅子、沙发、茶几）的方法。
 *         具体的工厂将实现这些方法以生产特定风格的家具族。
 */

class FurnitureFactory 
{
public:
    /**
     * @brief 虚析构函数。
     */
    virtual ~FurnitureFactory() = default;

    /**
     * @brief 声明创建椅子产品的接口。
     *
     * @return 指向抽象Chair的智能指针，确保内存自动管理。
     */
    virtual std::unique_ptr<Chair> createChair() const = 0;

    /**
     * @brief 声明创建沙发产品的接口。
     *
     * @return 指向抽象Sofa的智能指针。
     */
    virtual std::unique_ptr<Sofa> createSofa() const = 0;

    /**
     * @brief 声明创建茶几产品的接口。
     *
     * @return 指向抽象CoffeeTable的智能指针。
     */
    virtual std::unique_ptr<CoffeeTable> createCoffeeTable() const = 0;
};
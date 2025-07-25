#include "AbFactory.hpp"
/**
 * @brief 维多利亚风格家具的具体工厂。
 *
 * @detail 实现了FurnitureFactory接口，负责生产所有维多利亚风格的家具。
 */
class VictorianFurnitureFactory : public FurnitureFactory 
{
public:
    /**
     * @brief 创建维多利亚风格的椅子。
     *
     * @return 指向VictorianChair的智能指针。
     */
    std::unique_ptr<Chair> createChair() const override 
    {
        return std::make_unique<VictorianChair>();
    }

    /**
     * @brief 创建维多利亚风格的沙发。
     *
     * @return 指向VictorianSofa的智能指针。
     */
    std::unique_ptr<Sofa> createSofa() const override 
    {
        return std::make_unique<VictorianSofa>();
    }

    /**
     * @brief 创建维多利亚风格的茶几。
     *
     * @return 指向VictorianCoffeeTable的智能指针。
     */
    std::unique_ptr<CoffeeTable> createCoffeeTable() const override 
    {
        return std::make_unique<VictorianCoffeeTable>();
    }
};

/**
 * @brief 现代风格家具的具体工厂。
 *
 * @detail 实现了FurnitureFactory接口，负责生产所有现代风格的家具。
 */
class ModernFurnitureFactory : public FurnitureFactory 
{
public:
    /**
     * @brief 创建现代风格的椅子。
     *
     * @return 指向ModernChair的智能指针。
     */
    std::unique_ptr<Chair> createChair() const override 
    {
        return std::make_unique<ModernChair>();
    }

    /**
     * @brief 创建现代风格的沙发。
     *
     * @return 指向ModernSofa的智能指针。
     */
    std::unique_ptr<Sofa> createSofa() const override 
    {
        return std::make_unique<ModernSofa>();
    }

    /**
     * @brief 创建现代风格的茶几。
     *
     * @return 指向ModernCoffeeTable的智能指针。
     */
    std::unique_ptr<CoffeeTable> createCoffeeTable() const override 
    {
        return std::make_unique<ModernCoffeeTable>();
    }
};

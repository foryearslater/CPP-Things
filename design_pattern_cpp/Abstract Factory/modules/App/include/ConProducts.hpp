#include "AbProducts.hpp"
/**
 * @brief 维多利亚风格的具体椅子产品。
 *
 * @detail 实现了抽象Chair接口，提供维多利亚风格的椅子。
 */
class VictorianChair : public Chair 
{
public:
    /**
     * @brief 实现维多利亚风格椅子的坐下行为。
     *
     * @return 描述维多利亚风格椅子坐下体验的字符串。
     */
    std::string sitOn() const override 
    {
        return "坐在奢华的维多利亚风格椅子上。";
    }
};

/**
 * @brief 维多利亚风格的具体沙发产品。
 *
 * @detail 实现了抽象Sofa接口，提供维多利亚风格的沙发。
 */
class VictorianSofa : public Sofa 
{
public:
    /**
     * @brief 实现维多利亚风格沙发的躺下行为。
     *
     * @return 描述维多利亚风格沙发躺下体验的字符串。
     */
    std::string lieOn() const override 
    {
        return "躺在复古的维多利亚风格沙发上，感受历史的厚重。";
    }
};

/**
 * @brief 维多利亚风格的具体茶几产品。
 *
 * @detail 实现了抽象CoffeeTable接口，提供维多利亚风格的茶几。
 */
class VictorianCoffeeTable : public CoffeeTable 
{
public:
    /**
     * @brief 实现维多利亚风格茶几的放置物品行为。
     *
     * @return 描述维多利亚风格茶几放置物品体验的字符串。
     */
    std::string placeItems() const override 
    {
        return "将物品放在雕刻精美的维多利亚风格茶几上。";
    }
};

// --- 现代风格家具 (Modern Family) ---

/**
 * @brief 现代风格的具体椅子产品。
 *
 * @detail 实现了抽象Chair接口，提供现代风格的椅子。
 */
class ModernChair : public Chair 
{
public:
    /**
     * @brief 实现现代风格椅子的坐下行为。
     *
     * @return 描述现代风格椅子坐下体验的字符串。
     */
    std::string sitOn() const override 
    {
        return "坐在简洁的现代风格椅子上。";
    }
};

/**
 * @brief 现代风格的具体沙发产品。
 *
 * @detail 实现了抽象Sofa接口，提供现代风格的沙发。
 */
class ModernSofa : public Sofa 
{
public:
    /**
     * @brief 实现现代风格沙发的躺下行为。
     *
     * @return 描述现代风格沙发躺下体验的字符串。
     */
    std::string lieOn() const override 
    {
        return "躺在舒适的现代风格沙发上，享受极简主义。";
    }
};

/**
 * @brief 现代风格的具体茶几产品。
 *
 * @detail 实现了抽象CoffeeTable接口，提供现代风格的茶几。
 */
class ModernCoffeeTable : public CoffeeTable 
{
public:
    /**
     * @brief 实现现代风格茶几的放置物品行为。
     *
     * @return 描述现代风格茶几放置物品体验的字符串。
     */
    std::string placeItems() const override 
    {
        return "将物品放在功能性强的现代风格茶几上。";
    }
};
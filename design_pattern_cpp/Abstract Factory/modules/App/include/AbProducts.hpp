#include <iostream>
#include <string>
#include <memory> 

/**
 * @brief 抽象椅子产品接口。
 *
 * @detail 定义了所有椅子类应实现的行为。
 *         作为抽象基类，它包含纯虚函数。
 */
class Chair 
{
public:
    /**
     * @brief 虚析构函数。
     *
     * @detail 确保通过基类指针删除派生类对象时，能正确调用派生类析构函数，防止内存泄漏。
     */
    virtual ~Chair() = default;

    /**
     * @brief 声明坐下行为的接口。
     *
     * @return 表示坐下体验的字符串。
     */
    virtual std::string sitOn() const = 0;
};

/**
 * @brief 抽象沙发产品接口。
 *
 * @detail 定义了所有沙发类应实现的行为。
 */
class Sofa 
{
public:
    /**
     * @brief 虚析构函数。
     */
    virtual ~Sofa() = default;

    /**
     * @brief 声明躺下行为的接口。
     *
     * @return 表示躺下体验的字符串。
     */
    virtual std::string lieOn() const = 0;
};

/**
 * @brief 抽象茶几产品接口。
 *
 * @detail 定义了所有茶几类应实现的行为。
 */
class CoffeeTable 
{
public:
    /**
     * @brief 虚析构函数。
     */
    virtual ~CoffeeTable() = default;

    /**
     * @brief 声明放置物品行为的接口。
     *
     * @return 表示放置物品体验的字符串。
     */
    virtual std::string placeItems() const = 0;
};
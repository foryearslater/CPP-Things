#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream> 

/**
* @class Logger
* @brief 单例模式实现，用于提供一个全局唯一的日志记录器实例.
*
* @detail 该类实现了单例模式，确保在整个应用程序生命周期中只有一个Logger实例存在.
* @detail 它提供了一个统一的接口用于记录各种类型的日志消息，如信息、警告、错误等.
*/

class Logger 
{
private:
    /**
     * @brief 私有构造函数，防止外部直接创建 Logger 对象.
     * @detail 这是单例模式的关键，确保只能通过 getInstance() 方法获取实例.
     */
    Logger();

    /**
     * @brief 私有析构函数，控制 Logger 对象的生命周期.
     * @detail 对于 Meyers Singleton (静态局部变量)，析构函数会在程序退出时自动调用.
     */
    ~Logger();

    /**
     * @brief 删除拷贝构造函数，防止 Logger 对象被复制.
     * @detail 这是确保单例唯一性的重要手段.
     */
    Logger(const Logger&) = delete;

    /**
     * @brief 删除赋值运算符，防止 Logger 对象被赋值.
     * @detail 这是确保单例唯一性的重要手段.
     */
    Logger& operator=(const Logger&) = delete;

public:
    /**
     * @brief 获取 Logger 类的唯一实例.
     * @return Logger 类的引用，保证是同一个实例.
     */
    static Logger& GetInstance();
    static Logger* GetInstanceLazy();
    /**
     * @brief 记录一条日志消息.
     * @detail 将格式化后的日志消息输出到控制台.
     * @param message 要记录的字符串消息.
     */
    void Log(const std::string& message);

private:

    static Logger instance_Eager;
    /**
     * @brief 懒汉式 
     */
    static Logger* instance_lazy;

};

/**
* @brief 饿汉式 (Eager Initialization)
* @detail 在源文件中初始化静态成员 (在任何线程访问之前)
* @detail 在程序启动时或类加载时就立即创建好唯一的实例，而不是等到第一次使用时才创建
*/

Logger Logger::instance_Eager;


/**
* @brief 懒汉式 (Eager Initialization)
* @detail  只有在第一次调用 getInstance() 方法时才创建实例
*/

Logger* Logger::instance_lazy = nullptr;
#endif // LOGGER_H
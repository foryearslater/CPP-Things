#include "Logger.hpp"

#include <iostream> 
#include <ctime>    
#include <iomanip> 

Logger::Logger() 
{
    std::cout << "[Logger] Logger 实例已创建." << std::endl;
}

Logger::~Logger() 
{
    std::cout << "[Logger] Logger 实例已销毁." << std::endl;
}

Logger& Logger::GetInstance() 
{
    return instance_Eager;
}

Logger& Logger::GetInstanceLazy()
{
    if (instance_lazy == nullptr)
    {
        instance_lazy = new Logger();
    }
    return instance_lazy;
}

void Logger::Log(const std::string& message) 
{
    std::time_t now = std::time(nullptr);
    std::tm* ltm = std::localtime(&now);

    std::cerr << "[" << std::put_time(ltm, "%Y-%m-%d %H:%M:%S") << "] " << message << std::endl;
}
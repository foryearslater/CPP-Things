#include "Logger.hpp" 
#include <iostream>
#include <thread>   
#include <vector>   

void task_function(const std::string& taskName) 
{
    Logger::GetInstance().Log("Task '" + taskName + "' is running.");
}

int main() 
{
    std::cout << "--- 应用程序启动 ---" << std::endl;

    Logger::GetInstance().Log("Application initialized.");

    Logger::GetInstance().Log("Performing core operations.");

    Logger& logger1 = Logger::GetInstance();
    Logger& logger2 = Logger::GetInstance();

    if (&logger1 == &logger2) 
    {
        std::cout << "验证成功: logger1 和 logger2 指向同一个 Logger 实例." << std::endl;
    }
    else 
    {
        std::cout << "验证失败: 竟然创建了多个 Logger 实例!" << std::endl;
    }
    logger1.Log("This message comes from 'logger1' reference.");
    logger2.Log("This message comes from 'logger2' reference.");

    std::cout << "\n--- 演示多线程访问 ---\n";

    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) 
    {
        threads.emplace_back(task_function, "Thread-" + std::to_string(i + 1));
    }

    for (auto& t : threads) 
    {
        t.join();
    }

    std::cout << "\n--- 应用程序结束 ---" << std::endl;
    Logger::GetInstance().Log("Application exiting.");
    return 0;
}
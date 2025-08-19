#include "Test.hpp"

HungrySingleton HungrySingleton::instance;

LazySingletonNotSafe *LazySingletonNotSafe::instance = nullptr;

std::unique_ptr<LazySingletonDCL> LazySingletonDCL::instance = nullptr;
std::once_flag LazySingletonDCL::once_flag;

void run()
{
    HungrySingletonTest();
    LazySingletonNotSafeTest();
    LazySingletonMeyersTest();
    LazySingletonDCLTest();
}

void HungrySingletonTest()
{
    auto thread_func = [&](int i) -> void
    {
        std::cout << "this is thread " << i << std::endl;
        std::cout << "instance is " << &HungrySingleton::GetInstance() << std::endl;
    };
    std::cout << "s1 addr is " << &HungrySingleton::GetInstance() << std::endl;
    std::cout << "s2 addr is " << &HungrySingleton::GetInstance() << std::endl;

    for (int i = 0; i < 3; i++)
    {
        std::thread tid(thread_func, i);
        tid.join();
    }
}

void LazySingletonNotSafeTest()
{
    auto thread_func = [&](int i) -> void
    {
        std::cout << "this is thread " << i << std::endl;
        std::cout << "instance is " << LazySingletonNotSafe::GetInstance() << std::endl;
    };
    std::cout << "s1 addr is " << LazySingletonNotSafe::GetInstance() << std::endl;
    std::cout << "s2 addr is " << LazySingletonNotSafe::GetInstance() << std::endl;

    for (int i = 0; i < 3; i++)
    {
        std::thread tid(thread_func, i);
        tid.join();
    }
}

void LazySingletonMeyersTest()
{
    auto thread_func = [&](int i) -> void
    {
        std::cout << "this is thread " << i << std::endl;
        std::cout << "instance is " << &LazySingletonMeyers::GetInstance() << std::endl;
    };
    std::cout << "s1 addr is " << &LazySingletonMeyers::GetInstance() << std::endl;
    std::cout << "s2 addr is " << &LazySingletonMeyers::GetInstance() << std::endl;

    for (int i = 0; i < 3; i++)
    {
        std::thread tid(thread_func, i);
        tid.join();
    }
}

void LazySingletonDCLTest()
{
    auto thread_func = [&](int i) -> void
    {
        std::cout << "this is thread " << i << std::endl;
        std::cout << "instance is " << &LazySingletonDCL::GetInstance() << std::endl;
    };
    std::cout << "s1 addr is " << &LazySingletonDCL::GetInstance() << std::endl;
    std::cout << "s2 addr is " << &LazySingletonDCL::GetInstance() << std::endl;

    for (int i = 0; i < 3; i++)
    {
        std::thread tid(thread_func, i);
        tid.join();
    }
}
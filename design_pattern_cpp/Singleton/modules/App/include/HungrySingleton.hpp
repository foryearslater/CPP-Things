#pragma once
#include <iostream>

class HungrySingleton
{
private:
    HungrySingleton()
    {
        std::cout << "HungrySingleton: created !" << std::endl;
    }
    ~HungrySingleton()
    {
        std::cout << "HungrySingleton: destory !" << std::endl;
    }
    HungrySingleton(const HungrySingleton &) = delete;
    HungrySingleton &operator=(const HungrySingleton &) = delete;

public:
    static HungrySingleton &GetInstance()
    {
        return instance;
    }

    void ShowMessage() const
    {
        std::cout << "HungrySingleton: Hello from the eager instance!" << std::endl;
    }

private:
    static HungrySingleton instance;
};

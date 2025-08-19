#include <iostream>

class LazySingletonNotSafe
{
private:
    LazySingletonNotSafe()
    {
        std::cout << "LazySingletonNotSafe:  created !" << std::endl;
    }
    LazySingletonNotSafe(const LazySingletonNotSafe &) = delete;
    LazySingletonNotSafe &operator=(const LazySingletonNotSafe &) = delete;

public:
    static LazySingletonNotSafe *GetInstance()
    {
        if (instance == nullptr)
        {
            instance = new LazySingletonNotSafe();
        }
        return instance;
    }

    void ShowMessage() const
    {
        std::cout << "LazySingletonNotSafe: Hello from the lazy instance!" << std::endl;
    }

    static void DestroyInstance()
    {
        if (instance != nullptr)
        {
            delete instance;
            instance = nullptr;
            std::cout << "LazySingletonNotSafe: destory !" << std::endl;
        }
    }

public:
    static LazySingletonNotSafe *instance;
};

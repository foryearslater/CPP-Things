#include <iostream>

class LazySingletonMeyers
{
private:
    LazySingletonMeyers()
    {
        std::cout << "LazySingletonMeyers: created !" << std::endl;
    }
    ~LazySingletonMeyers()
    {
        std::cout << "LazySingletonMeyers: destory !" << std::endl;
    }
    LazySingletonMeyers(const LazySingletonMeyers &) = delete;
    LazySingletonMeyers &operator=(const LazySingletonMeyers &) = delete;

public:
    static LazySingletonMeyers &GetInstance()
    {
        static LazySingletonMeyers instance;
        return instance;
    }

    void ShowMessage() const
    {
        std::cout << "LazySingletonMeyers: Hello from the lazy instance!" << std::endl;
    }
};
#include <iostream>
#include <mutex>
#include <memory>

class LazySingletonDCL
{
public:
    LazySingletonDCL()
    {
        std::cout << "LazySingletonDCL: created !" << std::endl;
    }
    ~LazySingletonDCL()
    {
        std::cout << "LazySingletonDCL: destory !" << std::endl;
    }
    LazySingletonDCL(const LazySingletonDCL &) = delete;
    LazySingletonDCL &operator=(const LazySingletonDCL &) = delete;

public:
    static LazySingletonDCL &GetInstance()
    {
        std::call_once(once_flag, []()
                       { instance.reset(new LazySingletonDCL()); });
        return *instance;
    }

    void ShowMessage() const
    {
        std::cout << "LazySingletonDCL: Hello from the lazy instance!" << std::endl;
    }

private:
    static std::unique_ptr<LazySingletonDCL> instance;
    static std::once_flag once_flag;
};

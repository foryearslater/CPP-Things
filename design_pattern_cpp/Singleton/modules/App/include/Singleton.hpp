#include <iostream>
#include <mutex>

template <typename T>
class Singleton
{
private:
    Singleton()
    {
        std::cout << "Singleton<" << typeid(T).name() << ">: created !" << std::endl;
    }

    ~Singleton()
    {
        std::cout << "Singleton<" << typeid(T).name() << ">: destory !" << std::endl;
    }
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

public:
    static Singleton &GetInstance()
    {
        static Singleton instance;
        return instance;
    }

    T value;

    void ShowMessage() const
    {
        std::cout << "Singleton<" << typeid(T).name() << ">: Hello from the instance! Value: " << value << std::endl;
    }

    void SetValue(const T &val)
    {
        value = val;
        std::cout << "Singleton<" << typeid(T).name() << ">: Value set to " << value << std::endl;
    }
};

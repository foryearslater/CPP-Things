
// 单例实现要点：
// 构造函数和析构函数是私有的，不允许外部生成和释放
// 静态成员变量和静态返回单例的成员函数
// 禁用拷贝构造和赋值运算符
#include <iostream>
#include <mutex>
#include <atomic>
#include <bits/stdc++.h>

class Singleton1
{
public:
    static Singleton1 *GetInstance()
    {
        if (_instance == nullptr)
        {
            _instance = new Singleton1();
        }
        return _instance;
    }

private:
    Singleton1() {}
    ~Singleton1()
    {
        std::cout << "~Singleton1()" << std::endl;
    }
    Singleton1(const Singleton1 &) = delete;
    Singleton1 &operator=(const Singleton1 &) = delete;
    Singleton1(Singleton1 &&) = delete;
    Singleton1 &operator=(Singleton1 &&) = delete;

    static Singleton1 *_instance; // 全局静态区, 指向堆区
};

Singleton1 *Singleton1::_instance = nullptr;

class Singleton2
{
public:
    static Singleton2 *GetInstance()
    {
        if (_instance == nullptr)
        {
            _instance = new Singleton2();
            atexit(Destructor); // 注册析构函数，程序退出时自动调用
        }
        return _instance;
    }

private:
    static void Destructor()
    {
        if (nullptr != _instance)
        {
            delete _instance;
            _instance = nullptr;
        }
    }

    Singleton2() {}
    ~Singleton2()
    {
        std::cout << "~Singleton2()" << std::endl;
    }
    Singleton2(const Singleton2 &) = delete;
    Singleton2 &operator=(const Singleton2 &) = delete;
    Singleton2(Singleton2 &&) = delete;
    Singleton2 &operator=(Singleton2 &&) = delete;

    static Singleton2 *_instance;
};

Singleton2 *Singleton2::_instance = nullptr;

// 双锁
// 没有考虑多核心处理器cpu指令重排
class Singleton3
{
public:
    static Singleton3 *GetInstance()
    {
        if (_instance == nullptr)
        {
            std::unique_lock<std::mutex> lock(&_mutex);
            if (_instance == nullptr)
            {
                _instance = new Singleton3();
                atexit(Destructor);
            }
        }
        return _instance;
    }

private:
    static void Destructor()
    {
        if (nullptr != _instance)
        {
            delete _instance;
            _instance = nullptr;
        }
    }

    Singleton3() {}
    ~Singleton3()
    {
        std::cout << "~Singleton3()" << std::endl;
    }

    Singleton3(const Singleton3 &) = delete;
    Singleton3 &operator=(const Singleton3 &) = delete;
    Singleton3(Singleton3 &&) = delete;
    Singleton3 &operator=(Singleton3 &&) = delete;

    static Singleton3 *_instance;
    static std::mutex _mutex;
};

Singleton3 *Singleton3::_instance = nullptr;
std::mutex Singleton3::_mutex;

// 线程安全
// 内存屏障:1.可见性
class Singleton4
{
public:
    static Singleton4 *GetInstance()
    {
        Singleton4 *tmp = _instance.load(std::memory_order_relaxed);
        std::atomic_thread_fence(std::memory_order_acquire);
        if (tmp == nullptr)
        {
            std::unique_lock<std::mutex> lock(_mutex);
            tmp = _instance.load(std::memory_order_relaxed);
            if (tmp == nullptr)
            {
                tmp = new Singleton4();
                std::atomic_thread_fence(std::memory_order_release);
                _instance.store(tmp, std::memory_order_relaxed);
                atexit(Destructor);
            }
        }
        return tmp;
    }

private:
    static void Destructor()
    {
        Singleton4 *tmp = _instance.load(std::memory_order_relaxed);
        if (nullptr != tmp)
        {
            delete tmp;
        }
    }
    Singleton4() {}
    ~Singleton4()
    {
        std::cout << "~Singleton4()" << std::endl;
    }
    Singleton4(const Singleton4 &) = delete;
    Singleton4 &operator=(const Singleton4 &) = delete;
    Singleton4(Singleton4 &&) = delete;
    Singleton4 &operator=(Singleton4 &&) = delete;
    static std::atomic<Singleton4 *> _instance;
    static std::mutex _mutex;
};

std::atomic<Singleton4 *> Singleton4::_instance;
std::mutex Singleton4::_mutex;

class Singleton5
{
public:
    static Singleton5 *GetInstance()
    {
        static Singleton5 instance;
        return &instance;
    }

private:
    Singleton5() {}
    ~Singleton5()
    {
        std::cout << "~Singleton5()" << std::endl;
    }
    Singleton5(const Singleton5 &) = delete;
    Singleton5 &operator=(const Singleton5 &) = delete;
    Singleton5(Singleton5 &&) = delete;
    Singleton5 &operator=(Singleton5 &&) = delete;
};

template <typename T>
class Singleton
{
public:
    static T *GetInstance()
    {
        static T instance;
        return &instance;
    }

protected:
    virtual ~Singleton()
    {
        std::cout << "~Singleton()" << std::endl;
    }
    Singleton() {}

private:
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton &operator=(Singleton &&) = delete;
};

class DesignPattern : public Singleton<DesignPattern>
{
    friend class Singleton<DesignPattern>;

public:
    //...
private:
    DesignPattern() {}
    ~DesignPattern()
    {
        std::cout << "~DesignPattern()" << std::endl;
    }
};

int main()
{
    // 版本1:堆上资源不能正确析构（没有调用析构函数）
    Singleton1 *s1 = Singleton1::GetInstance();

    // 版本2: 堆上资源能正确析构（调用了析构函数）
    Singleton2 *s2 = Singleton2::GetInstance();

    // 版本3: 双重检查，可能造成内存泄露（可能没有调用析构函数）
    Singleton3 *s3 = Singleton3::GetInstance();

    // 版本4: 线程安全 原子操作+互斥锁+内存屏障
    Singleton4 *s4 = Singleton4::GetInstance();

    // 版本5: C++11 静态局部变量实现线程安全性 延迟加载 内存正确释放
    Singleton5 *s5 = Singleton5::GetInstance();

    // 版本6: 模板类 单例模式 模板类封装了单例要点
    DesignPattern *s6 = DesignPattern::GetInstance();

    return 0;
}
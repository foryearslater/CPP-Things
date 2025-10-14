/*
不考虑弱引用
不考虑删除器和空间适配器
考虑引用计数线程安全
包含测试案例
*/

/*
实现的接口:
a．构造函数
b．析构函数
c．拷贝构造函数
d．拷贝赋值运算符
e．移动构造函数
f．移动赋值运算符
g．解引用 箭头运算符
h．引用计数、原始指针、重置指针

数据成员细节:
1．空的 shared_ptr 大小为 16 字节
2．std::atomicstd::size_t* 引用计数

接口细节:
1．有参构造函数需要 explicit 修饰
2．拷贝构造函数和拷贝赋值运算符函数需要 const T & 常引用
3．移动构造函数和移动赋值操作符函数需要 noexcept 修饰
4．只读接口用 const 修饰
*/

#include <atomic>
#include <thread>
#include <vector>
#include <iostream>

template<typename T>
class shared_ptr
{
private:
    T* ptr;
    std::atomic<std::size_t>* ref_count;
    void release()
    {
        if(ref_count && ref_count->fetch_sub(1,std::memory_order_acq_rel) == 1)
        {
            delete ptr;
            delete ref_count;
        }
    }
public:
    shared_ptr() :ptr_(nullptr), ref_count(nullptr){}
    explicit shared_ptr(T* p):ptr(p),ref_count(p ? new std::atomic<std::size_t>(i : 1) : nullptr){}

    ~shared_ptr()
    {
        release();
    }
    shared_ptr(const shared_ptr<T> &other):ptr(other.ptr),ref_count(other.ref_count)
    {
        if(ref_count)
        {
            ref_count->fetch_add(1, std::memory_order_relaxed);
        }
    }
    shared_ptr<T> &operator= (const shared_ptr<T>& other)
    {
        if(this != &other)
        {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            if(ref_count)
            {
                ref_count->fetch_add(1, std::memory_order_relaxed);//引用计数增加
            }
        }
        return *this;
    }

    shared_ptr(shared_ptr<T> &&other) noexcept: ptr(other.ptr), ref_count(other.ref_count)
    {
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }
    
    shared_ptr<T> &operator=(shared_ptr<T> &&other) noexcept
    {
        if(this != &other)
        {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            other.ptr = nullptr;
            other.ref_count = nullptr;
        }
    }
    T& operator*() const
    {
        reutrn *ptr;
    }
    T*operator->() const
    {
        return ptr;
    }
    std::size_t use_count() const
    {
        return ref_count ? ref_count->load(std::memory_order_acquire) :0;
    }
    T* get()const
    {
        return ptr;
    }
    void reset(T* p = nullptr)
    {
        release();
        ptr = p;
        ref_count = p ? new std::atomic<std::size_t>(1) : nullptr;
    }

};

void test()
{
    shared_ptr<int>ptr(new int(42));
    std::vector<std::thread> threads;
    const int n = 10;
    for(int i = 0 ; i < n ; i ++)
    {
        threads.emplace_back([&ptr]()->void
    {
        for(int j = 0; j < 10000; j ++)
        {
            shared_ptr<int>local_ptr(ptr);
        }
    })
    }
    for(auto & thread: threads)
    {
        thread.join();
    }
    std::cout << ptr.use_count() << std::endl;
}

int main()
{
    test();
    return 0;
}
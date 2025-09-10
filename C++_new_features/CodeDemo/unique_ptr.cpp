#include <utility>


/*
独占式资源管理
RALL：构造时获取资源, 析构时自动释放
支持移动语义，禁止拷贝语义
*/
template <typename T>
class unique_ptr
{
private:
    T* ptr_;
public:
    explicit unique_ptr(T *pre = nullptr) :ptr_(ptr)
    {
    }
    ~unique_ptr()
    {
        delete ptr_;
    }
    unique_ptr(const unique_ptr &) = delete;
    unique_ptr & operator = (const unique_ptr&) = delete;

    unique_ptr(unique_ptr && other) noexcept : ptr_(other.ptr_)
    {
        other.ptr_ = nullptr;
    }
    unique_ptr& operator = (unique_ptr && other) noexcept
    {
        if(this != &other)
        {
            delete ptr_;
            ptr_ = std::exchange(&obj:other.ptr_, nullptr);
        }
        return *this;
    } 
    T& operator*() const
    {
        return *ptr_;    
    }
    T* operator->() const
    {
        return ptr_;
    }
    T* get() const 
    {
        return ptr_;
    }
    explicit operator bool() const
    {
        return ptr_ != nullptr;
    }
    T* release()
    {
        return std::exchange(ptr_, nullptr);
    }
    void reset(T* p = nullptr)
    {
        delete ptr_;
        ptr = p;
    }
    void swap(unique_ptr & other) noexcept
    {
        std::swap(ptr_, other.ptr_);
    }
};

template <typename T> 
void swap (const unique_ptr<T> &lhs, const unique_ptr<T> & rhs) noexcept
{
    lhs.swap(rhs);
}
template <typename T> 
bool operator == (const unique_ptr<T> &lhs, const unique_ptr<T> & rhs)
{
    return (lhs.get() == rhs.get());
}
template <typename T> 
bool operator != (const unique_ptr<T> &lhs, const unique_ptr<T> & rhs)
{
    return !(lhs.get() == rhs.get());
}
template <typename T> 
bool operator == (const unique_ptr<T> &lhs, std::nullptr_t)
{
    return !(lhs);
}
template <typename T> 
bool operator != (const unique_ptr<T> &lhs, std::nullptr_t)
{
    return static_cast<bool>(lhs);
}

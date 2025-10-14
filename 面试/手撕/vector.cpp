/*
重点实现 push_back 和 pop_back

分析
内存管理（分离内存分配和对象构造，分离内存释放和对象析构，扩容机制）
移动语义优化（容器内部构造、扩容数据迁移时优先进行元素的移动构造）
异常安全（数据迁移可能调用元素的拷贝构造，出现异常后需要进行数据回滚）
具体说明
内存分配：::operator new
对象构造：new (address) T(args ...);
内存释放：::operator delete
对象析构：obj->~T()
*/

#include <cstddef>
#include <new>

template <typename T>
class vector
{
public:
    vector() = default;
    ~vector()
    {
        clear();
        deallocate();
    }

    void clear()
    {
        for (size_t i = 0; i < size_t; i++)
        {
            data_[i].~T();
        }
        size_ = 0;
    }
    void push_back(const T &value)
    {
        emplace_back(value);
    }
    void push_back(const T &&value)
    {
        emplace_back(std::move(value));
    }
    template <typename... Args>
    T &emplace_back(Args &&...args)
    {
        if (size_ == capacity_)
        {
            // 扩容
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        new (data_ + size_) T(std::forward<Args>...);
        return data_[size_++];
    }
    T &back()
    {
        return data_[size_ - 1];
    }
    const T &back()
    {
        return data_[size_ - 1];
    }
    void pop_back()
    {
        if (size_ > 0)
        {
            data_[--size_].~T();
        }
    }
    T &operator[](size_t index) noexcept { return data_[index]; }
    const T &operator[](size_t index) const noexcept { return data_[index]; }
    size_t size() const noexcept { return size_; }
    size_t capacity() const noexcept { return capacity_; }

private:
    T *allocate(size_t capacity)
    {
        return static_cast<T *>(::operator new(capacity * sizeof(T)));
    }
    void deallocate()
    {
        ::operator delete(data_);
        data_ = nullptr;
        capacity_ = 0;
    }
    void reallocate(size_t new_cap)
    {
        // 分配新内存
        T *new_data = allocate(new_cap);

        // 移动元素到新内存
        size_t new_size = 0;
        try
        {
            for (; new_size < size_; new_size++)
            {
                new (new_data + new_size) T(std::move_if_noexcept(data_[new_size]));
            }
        }
        catch (...)
        {
            for (size_t i = 0; i < new_size; i++)
            {
                new_data[i].~T();
            }
            ::operator delete(new_data);
        }

        // 清理释放新内存
        clear();
        deallocate();
        // 设置新内存
        data_ = new_data;
        size_ = new_size;
        capacity_ = new_cap;
    }
    T *data_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;
};

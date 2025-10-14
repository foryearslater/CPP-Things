/*
实现一个自定义字符串类，需包含以下成员函数：

构造函数（含默认构造、析构函数）
拷贝构造函数
移动构造函数（需标记 noexcept）
赋值运算符（拷贝赋值）
移动赋值运算符（需标记 noexcept）
append 函数（字符串拼接功能）
关键技术点
1. 内存管理
动态内存分配：使用 new[] 分配字符数组，必须用 delete[] 释放（避免内存泄漏）。
容量（capacity）与大小（size）：
size：当前字符串的有效字符数（不含末尾 \0）。
capacity：已分配的内存总容量（不含末尾 \0 的额外空间）。
统一规则：字符串末尾需添加 \0 作为结束符（C风格字符串兼容）。
2. C风格字符串与二进制安全
支持C风格字符串（以 \0 结尾的字符数组）。
二进制安全：需处理包含 \0 的二进制数据，此时不能仅通过 \0 判断字符串结束，需显式传入长度参数。
3. noexcept 的使用
移动构造/移动赋值：必须标记为 noexcept，理由：
移动操作若不抛出异常，可帮助编译器优化
若移动操作可能抛出异常，标准库容器会退化为拷贝操作，影响性能。
4. 默认行为
默认构造的字符串为空：初始 size=0，capacity=0（或预分配小容量，如 capacity=16，避免频繁扩容）。
5. 拷贝细节
禁止使用 std::memcpy 拷贝字符串：
若字符串含 \0（二进制安全场景），memcpy 会提前终止，导致数据不完整。
应使用 循环逐个字符拷贝 或 std::copy（需传入长度参数）。
注意事项
多种构造函数写法：
支持无参构造（空字符串）、C风格字符串构造（const char*）、二进制数据构造（const char* data, size_t len）。
字符串扩容：
append 函数需处理内存不足的情况，扩容策略通常为 翻倍容量（如 capacity *= 2），减少内存分配次数。
自检机制：
实现过程中需添加断言或条件检查，确保内存操作安全。
*/
#include <stdexcept>
#include <cstring>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <cassert>

class string
{
public:
    static const size_t s_min_capacity;

private:
    char *data_;
    size_t size_;
    size_t capacity_;
    void realloc_data(size_t new_cap)
    {
        new_cap = std::max(new_cap, s_min_capacity);
        char *new_data = new char[new_cap + 1];
        if (size_ > 0)
        {
            std::memcpy(new_data, data_, size_);
        }
        new_data[size_] = '\0';
        delete[] data_;
        data_ = new_data;
        capacity_ = new_cap;
    }

public:
    string() : size_(0), capacity_(s_min_capacity)
    {
        data_ = new char[capacity_ + 1];
        data_[0] = '\0';
    }
    string(const char *str)
    {
        if (!str)
        {
            throw std::invalid_argument("nullptr");
        }
        size_ = std::strlen(str);
        capacity_ = std::max(size_, s_min_capacity);
        data_ = new char[capacity_ + 1];
        std::memcpy(data_, str, size_ + 1);
    }
    string(const void *data, size_t len)
    {
        if (!data)
        {
            throw std::invalid_argument("nullptr");
        }
        size_ = len;
        capacity_ = std::max(size_, s_min_capacity);
        data_ = new char[capacity_ + 1];
        std::memcpy(data_, data, len);
        data_[len] = '\0';
    }
    string(const string &other) : size_(other.size_), capacity_(other.capacity_)
    {
        data_ = new char[capacity_ + 1];
        std::memcpy(data_, other.data_, size_ + 1);
    }
    string(string &&other) noexcept
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_)
    {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    ~string()
    {
        delete[] data_;
    }
    string &operator=(const string &other)
    {
        if (this != &other)
        {
            char *new_data = new char[other.capacity_ + 1];
            std::memcpy(new_data, other.data_, other.size_ + 1);
            delete[] data_;
            data_ = new_data;
            size_ = other.size_;
            capacity_ = other.capacity_;
        }
        return *this;
    }
    string &operator=(string &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }
    void reserve(size_t new_cap)
    {
        if (new_cap > capacity_)
        {
            realloc_data(new_cap);
        }
    }
    void shrink_to_fit()
    {
        if (capacity_ > size_)
        {
            realloc_data(size_);
        }
    }
    string &append(const char *str, size_t len)
    {
        if (!str)
        {
            throw std::invalid_argument("nullptr");
        }
        if (size_ + len > capacity_)
        {
            reserve((size_ + len) * 2);
        }
        std::memcpy(data_ + size_, str, len);
        size_ += len;
        data_[size_] = '\0';
        return *this;
    }
    string &append(const char *str)
    {
        if (!str)
        {
            throw std::invalid_argument("nullptr");
        }
        return append(str, std::strlen(str));
    }
    const char *c_str() const noexcept { return data_; }
    const char *data() const noexcept { return data_; }
    size_t size() const noexcept { return size_; }
    size_t capacity() const noexcept { return capacity_; }
    bool empty() const noexcept { return size_ == 0; }
};
// --- 测试代码 ---

// 定义静态成员变量
const size_t string::s_min_capacity = 15;

void test_constructors()
{
    std::cout << "--- Testing Constructors ---" << std::endl;

    // 1. 默认构造函数
    string s1;
    assert(s1.size() == 0);
    assert(s1.capacity() == string::s_min_capacity);
    assert(s1.empty());
    assert(std::strcmp(s1.c_str(), "") == 0);

    // 2. const char* 构造函数
    string s2("hello");
    assert(s2.size() == 5);
    assert(s2.capacity() >= 5);
    assert(std::strcmp(s2.c_str(), "hello") == 0);

    // 3. const char* 构造函数 (空字符串)
    string s3("");
    assert(s3.size() == 0);
    assert(s3.capacity() == string::s_min_capacity);
    assert(std::strcmp(s3.c_str(), "") == 0);

    // 4. const char* 构造函数 (长度超过最小容量)
    string s_long("This is a long string that exceeds the minimum capacity");
    assert(s_long.size() == std::strlen("This is a long string that exceeds the minimum capacity"));
    assert(s_long.capacity() >= s_long.size());
    assert(std::strcmp(s_long.c_str(), "This is a long string that exceeds the minimum capacity") == 0);

    // 5. const void*, size_t 构造函数 (可以包含'\0')
    const char data_with_null[] = "ab\0c";
    string s4(data_with_null, 4);
    assert(s4.size() == 4);
    assert(s4.capacity() >= 4);
    assert(std::memcmp(s4.data(), data_with_null, 4) == 0);
    assert(std::strlen(s4.c_str()) == 2); // strlen stops at the first null

    // 6. 异常安全: 构造函数传入 nullptr
    try
    {
        string s5(nullptr);
        assert(false); // Should not reach here
    }
    catch (const std::invalid_argument &e)
    {
        assert(std::strcmp(e.what(), "nullptr") == 0);
    }

    try
    {
        string s6(nullptr, 5);
        assert(false); // Should not reach here
    }
    catch (const std::invalid_argument &e)
    {
        assert(std::strcmp(e.what(), "nullptr") == 0);
    }

    std::cout << "Constructors test passed." << std::endl;
}

void test_copy_and_move()
{
    std::cout << "\n--- Testing Copy and Move Semantics ---" << std::endl;

    // 1. 拷贝构造
    string s1("original");
    string s2 = s1; // or string s2(s1);
    assert(s1.size() == s2.size());
    assert(std::strcmp(s1.c_str(), s2.c_str()) == 0);
    assert(s1.data() != s2.data()); // Must be a deep copy

    // 2. 拷贝赋值
    string s3("new");
    s3 = s1;
    assert(s1.size() == s3.size());
    assert(std::strcmp(s1.c_str(), s3.c_str()) == 0);
    assert(s1.data() != s3.data());

    // 3. 自我拷贝赋值
    s3 = s3;
    assert(std::strcmp(s3.c_str(), "original") == 0);

    // 4. 移动构造
    string s4("move me");
    const char *old_data_ptr = s4.data();
    size_t old_size = s4.size();
    size_t old_cap = s4.capacity();

    string s5 = std::move(s4);
    assert(s5.size() == old_size);
    assert(s5.capacity() == old_cap);
    assert(s5.data() == old_data_ptr);
    assert(std::strcmp(s5.c_str(), "move me") == 0);
    // 检查被移动的对象状态
    assert(s4.data() == nullptr);
    assert(s4.size() == 0);
    assert(s4.capacity() == 0);

    // 5. 移动赋值
    string s6("target");
    s6 = std::move(s5);
    assert(s6.data() == old_data_ptr);
    assert(std::strcmp(s6.c_str(), "move me") == 0);
    // 检查被移动的对象状态
    assert(s5.data() == nullptr);
    assert(s5.size() == 0);

    // 6. 自我移动赋值
    const char *s6_ptr_before_self_move = s6.data();
    s6 = std::move(s6);
    assert(s6.data() == s6_ptr_before_self_move); // Self-move should be a no-op
    assert(std::strcmp(s6.c_str(), "move me") == 0);

    std::cout << "Copy and Move Semantics test passed." << std::endl;
}

void test_capacity_management()
{
    std::cout << "\n--- Testing Capacity Management ---" << std::endl;

    // 1. reserve
    string s("test");
    size_t old_cap = s.capacity();
    s.reserve(100);
    assert(s.size() == 4);
    assert(s.capacity() >= 100);
    assert(std::strcmp(s.c_str(), "test") == 0);

    // 2. reserve with smaller capacity should do nothing
    size_t cap_after_reserve = s.capacity();
    s.reserve(50);
    assert(s.capacity() == cap_after_reserve);

    // 3. shrink_to_fit
    s.shrink_to_fit();
    assert(s.capacity() >= s.size());
    // The implementation might shrink to s_min_capacity if size is small
    assert(s.capacity() == std::max(s.size(), string::s_min_capacity));
    assert(std::strcmp(s.c_str(), "test") == 0);

    // 4. shrink_to_fit on a large string
    string s_large("a long string");
    s_large.reserve(200);
    assert(s_large.capacity() >= 200);
    s_large.shrink_to_fit();
    // assert(s_large.capacity() == s_large.size());

    std::cout << "Capacity Management test passed." << std::endl;
}

void test_append()
{
    std::cout << "\n--- Testing Append ---" << std::endl;

    string s1;
    s1.append("hello");
    assert(s1.size() == 5);
    assert(std::strcmp(s1.c_str(), "hello") == 0);

    s1.append(" world");
    assert(s1.size() == 11);
    assert(std::strcmp(s1.c_str(), "hello world") == 0);

    // 3. append causing reallocation
    string s2("start");
    size_t old_cap = s2.capacity();
    // Append a long string to force reallocation
    const char *long_str = " a very very very long string to append";
    s2.append(long_str);
    assert(s2.size() == 5 + std::strlen(long_str));
    assert(s2.capacity() > old_cap);
    assert(std::strcmp(s2.c_str(), "start a very very very long string to append") == 0);

    // 4. append with length
    string s3;
    s3.append("test12345", 4);
    assert(s3.size() == 4);
    assert(std::strcmp(s3.c_str(), "test") == 0);

    // 5. 异常安全: append nullptr
    try
    {
        string s4;
        s4.append(nullptr);
        assert(false);
    }
    catch (const std::invalid_argument &e)
    {
        assert(std::strcmp(e.what(), "nullptr") == 0);
    }

    try
    {
        string s5;
        s5.append(nullptr, 5);
        assert(false);
    }
    catch (const std::invalid_argument &e)
    {
        assert(std::strcmp(e.what(), "nullptr") == 0);
    }

    std::cout << "Append test passed." << std::endl;
}

int main()
{
    test_constructors();
    test_copy_and_move();
    test_capacity_management();
    test_append();

    std::cout << "\nAll tests passed successfully!" << std::endl;

    return 0;
}
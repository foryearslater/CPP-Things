#include <bits/stdc++.h>

class String
{
private:
    char *data_;
    size_t size_;
    size_t capacity_;

public:
    String() : size_(0)
    {
        data_ = new char[capacity_ + 1];
        data_[0] = '\0';
    }
    ~String()
    {
        delete[] data_;
    }
    String(const String &other) : size_(other.size_), capacity_(other.capacity_)
    {
        data_ = new char[capacity_ + 1];
        std::memcpy(data_, other.data_, size_ + 1);
    }
    String(String &&other) noexcept
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_)
    {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    String &operator=(const String &other)
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
    String &operator=(String &&other) noexcept
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
};
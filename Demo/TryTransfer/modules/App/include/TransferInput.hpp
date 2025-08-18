#pragma once
#include <string_view>

#define FS_NV_META(NAME, VALUE) MakeTransferData(NAME, VALUE)

template <typename T>
class TransferData
{
public:
    TransferData(std::string_view a_name, T &a_value) : name{a_name}, value{a_value} {};

    std::string_view name;
    T &value;
};

template <typename T>
inline const TransferData<T> MakeTransferData(const char *n, T &v)
{
    return TransferData(n, v);
}
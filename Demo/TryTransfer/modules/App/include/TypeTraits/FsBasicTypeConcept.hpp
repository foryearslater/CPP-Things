#pragma once

#include <concepts>
#include <vector>

template <typename T>
concept ArithemeticType = std::is_arithmetic_v<T>;

template <typename T>
struct is_vector : std::false_type
{
};

template <typename U, typename Alloc>
struct is_vector<std::vector<U, Alloc>> : std::true_type
{
};

template <typename T>
concept VectorType = is_vector<T>::value;
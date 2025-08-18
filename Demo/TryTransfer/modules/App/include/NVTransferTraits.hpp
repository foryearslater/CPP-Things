#pragma once

#include "TransferInput.hpp"
#include <type_traits>

// Name-Value 对象
template <typename T>
struct NVTransferTraits
{
	static_assert(false, "Unknown Transfer Input");
	using TransferType = T;

	static constexpr std::string_view TransferName(const T &a_data) {}
	static constexpr T &TransferValue(const T &a_data) { return a_data; }
};

template <typename T>
struct NVTransferTraits<TransferData<T>>
{
public:
	using TransferType = T;

	static constexpr std::string_view TransferName(const TransferData<T> &a_data) { return a_data.name; }
	static constexpr T &TransferValue(const TransferData<T> &a_data) { return a_data.value; }
};
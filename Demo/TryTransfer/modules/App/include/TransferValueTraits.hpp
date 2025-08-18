#pragma once

#include <type_traits>
#include <concepts>
#include <string_view>
#include "TypeTraits/FsBasicTypeConcept.hpp"
#include "TypeTraits/FsBasicTypeNameTraits.hpp"

template <typename T>
concept NamedObject = requires(const T &obj) {
	{ obj.GetTypeName() } -> std::same_as<std::string_view>;
};

template <typename TransferType>
struct TransferValueTraitsBase
{
	using Type = TransferType;

	static constexpr bool is_class_type = false;
	static constexpr bool is_vector = false;
};

template <typename T>
struct TransferValueTraits : TransferValueTraitsBase<T>
{
	static_assert(false, "NoTransferValue Matched.");
};

template <ArithemeticType TransferType>
struct TransferValueTraits<TransferType> : public TransferValueTraitsBase<TransferType>
{
	using Type = TransferType;

	constexpr static bool is_class_type = false;
	constexpr static bool is_vector = false;
	static constexpr std::string_view GetTypeName(const TransferType &a_type) { return FsTypeNameTraits<TransferType>::Name(); };
};

template <VectorType TransferType>
struct TransferValueTraits<TransferType> : public TransferValueTraitsBase<TransferType>
{
	using ElementType = TransferType::value_type;

	constexpr static bool is_vector = true;

	int Count(const TransferType &a_vector_type) { return a_vector_type.size(); }
	const ElementType &Item(const TransferType &a_vector_type, int index) { return a_vector_type[index]; }
};

template <NamedObject TransferType>
struct TransferValueTraits<TransferType> : public TransferValueTraitsBase<TransferType>
{
	constexpr static bool is_class_type = true;
	static constexpr std::string_view GetTypeName(const TransferType &a_type) { return a_type.GetTypeName(); };
};

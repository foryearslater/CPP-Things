#pragma once

#include <cstdint>
#include <type_traits>
#include <vector>
#include <memory>

template <typename TransferBackendImpl>
class TransferBackend
{
public:
	template <typename TFieldMeta>
	void Transfer(TFieldMeta &a_field_meta);

	template <typename TFieldMeta>
	void Transfer(const TFieldMeta &a_field_meta);

protected:
};

template <typename TransferBackendImpl>
template <typename TFieldMeta>
void TransferBackend<TransferBackendImpl>::Transfer(const TFieldMeta &a_field_meta)
{
	static_cast<TransferBackendImpl *>(this)->Transfer(a_field_meta);
}

template <typename TransferBackendImpl>
template <typename TFieldMeta>
void TransferBackend<TransferBackendImpl>::Transfer(TFieldMeta &a_field_meta)
{
	static_cast<TransferBackendImpl *>(this)->Transfer(a_field_meta);
}

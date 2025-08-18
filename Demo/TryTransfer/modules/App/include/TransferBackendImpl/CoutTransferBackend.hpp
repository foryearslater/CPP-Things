#pragma once
#include "TransferBackend.hpp"
#include "NVTransferTraits.hpp"
#include <iostream>
#include <format>
#include "TransferValueTraits.hpp"

class XmlTransferBackend : public TransferBackend<XmlTransferBackend>
{
private:
    // pugixml xml_document;

    template <typename Type>
    void TransferValue(std::string_view a_view, Type a_type);

public:
    template <typename TFieldMeta>
    void Transfer(const TFieldMeta &a_field_meta);
};

class CoutTransferBackend : public TransferBackend<CoutTransferBackend>
{
private:
    int m_ident = 0;

    void PrintIdent();
    template <ArithemeticType Type>
    void TransferValue(std::string_view a_view, Type a_type);
    template <VectorType Type>
    void TransferValue(std::string_view a_view, Type a_type);
    template <typename Type>
    void TransferValue(std::string_view a_view, Type a_type);

public:
    template <typename TFieldMeta>
    void Transfer(const TFieldMeta &a_field_meta);
};

void CoutTransferBackend::PrintIdent()
{
    for (int i = 0; i < m_ident; ++i)
    {
        std::cout << " ";
    }
}

template <VectorType Type>
void CoutTransferBackend::TransferValue(std::string_view a_view, Type a_type)
{
    PrintIdent();
    m_ident += 2;
    std::cout << "Vector" << std::endl;
    int index = 0;
    for (auto &val : a_type)
    {
        auto s = std::format("{}->", index);
        TransferValue(s, val);
        index++;
    }
    m_ident -= 2;
}

template <typename Type>
void CoutTransferBackend::TransferValue(std::string_view a_view, Type a_type)
{
    PrintIdent();
    std::cout << a_view << "  " << std::endl;
    m_ident += 2;

    a_type.Transfer(*this);

    m_ident -= 2;
}

template <ArithemeticType Type>
void CoutTransferBackend::TransferValue(std::string_view a_view, Type a_type)
{
    PrintIdent();
    std::cout << a_view << "  " << a_type << std::endl;
}

template <typename TFieldMeta>
void CoutTransferBackend::Transfer(const TFieldMeta &a_field_meta)
{
    using NVTransferTraits = NVTransferTraits<TFieldMeta>;
    using TransferType = NVTransferTraits::TransferType;
    using ValueTraits = TransferValueTraits<TransferType>;

    TransferValue(NVTransferTraits::TransferName(a_field_meta), NVTransferTraits::TransferValue(a_field_meta));
}

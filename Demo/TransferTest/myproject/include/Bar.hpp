#ifndef BAR_H_
#define BAR_H_

#include "Serializable.hpp"
#include <vector>
#include <string>
#include <cstdint>
#include <sstream>
template <typename T>
class Bar : public Serializable<T>
{
public:
    T m_data;
    Bar(T d = {}) : m_data(d) {}
    std::string GetTypeName() const override { return "Bar"; }
    // XML

    void SaveToXml(pugi::xml_node &node) const
    {
        node.append_child("m_data").text().set(m_data);
        // pugi::xml_document doc;
        // doc.append_child("Bar").append_copy(node);
        // doc.save(std::cout, "  ", pugi::format_default | pugi::format_no_declaration);
    }
    void LoadFromXml(pugi::xml_node &node)
    {
        pugi::xml_node dataNode = node.child("m_data");
        if (!dataNode)
        {
            throw std::runtime_error("Missing <m_data> element in XML");
        }
        auto getValue = [](const pugi::xml_node &n) -> T
        {
            if constexpr (std::is_same_v<T, int>)
                return n.text().as_int();
            else if constexpr (std::is_same_v<T, double>)
                return n.text().as_double();
            else if constexpr (std::is_same_v<T, float>)
                return n.text().as_float();
            else if constexpr (std::is_same_v<T, std::string>)
                return std::string(n.text().as_string());
            else
                static_assert(sizeof(T) == 0, "Unsupported type for Point3D::LoadFromXml");
        };
        m_data = getValue(dataNode);
    }

    // BINARY

    void SerializeBinary(std::vector<T> &node) const
    {
        size_t size = sizeof(m_data);
        node.resize(size);
        std::memcpy(node.data(), &m_data, size);
    }

    void DeserializeBinary(const std::vector<T> &node)
    {
        if (node.size() != sizeof(m_data))
        {
            throw std::runtime_error("Binary data size mismatch");
        }
        std::memcpy(&m_data, node.data(), sizeof(m_data));
    }
};
#endif // BAR_H

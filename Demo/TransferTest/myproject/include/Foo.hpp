#ifndef FOO_H_
#define FOO_H_

#include "Point3D.hpp"
#include "Serializable.hpp"

template <typename T>
class Foo : public Serializable<T>
{

public:
    T m_value;
    Point3D<T> m_point;
    Foo(T value, const Point3D<T> &point) : m_value(value), m_point(point) {}
    Foo(T value, Point3D<T> &&point) : m_value(value), m_point(std::move(point)) {}
    std::string GetTypeName() const override { return "Foo"; }
    // XML

    void SaveToXml(pugi::xml_node &node) const
    {
        node.append_child("m_value").text().set(m_value);
        pugi::xml_node pointNode = node.append_child("m_point");
        m_point.SaveToXml(pointNode);
    }

    void LoadFromXml(pugi::xml_node &node)
    {
        pugi::xml_node value = node.child("m_value");
        if (!value)
        {
            throw std::runtime_error("Missing <m_value> element in XML");
        }
        std::string valueStr = value.text().as_string();
        if constexpr (std::is_same<T, int>::value)
        {
            m_value = std::stoi(valueStr);
        }
        else if constexpr (std::is_same<T, double>::value)
        {
            m_value = std::stod(valueStr);
        }
        else if constexpr (std::is_same<T, float>::value)
        {
            m_value = std::stof(valueStr);
        }
        else if constexpr (std::is_same<T, std::string>::value)
        {
            m_value = valueStr;
        }
        else
        {
            static_assert(sizeof(T) == 0, "Unsupported type for Foo::LoadFromXml");
        }

        pugi::xml_node point = node.child("m_point");
        if (!point)
        {
            throw std::runtime_error("Missing <m_point> element in XML");
        }
        m_point.LoadFromXml(point);
    }

    // BINARY

    void SerializeBinary(std::vector<T> &node) const
    {
        size_t size = sizeof(m_value) + sizeof(m_point);
        node.resize(size);
        std::memcpy(node.data(), &m_value, sizeof(m_value));
        m_point.SerializeBinary(node);
    }

    void DeserializeBinary(const std::vector<T> &node)
    {
        if (node.size() < sizeof(m_value) + sizeof(m_point))
        {
            throw std::runtime_error("Binary data size mismatch");
        }
        std::memcpy(&m_value, node.data(), sizeof(m_value));
        m_point.DeserializeBinary(std::vector<T>(node.begin() + sizeof(m_value), node.end()));
    }
};
#endif // FOO_H_
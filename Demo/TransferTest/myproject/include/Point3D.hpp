#ifndef POINT3D_H
#define POINT3D_H

#include "Serializable.hpp"
template <typename T>
class Point3D : public Serializable<T>
{
public:
    T x;
    T y;
    T z;

public:
    Point3D(T point_x, T point_y, T point_z) : x(point_x), y(point_y), z(point_z) {}
    std::string GetTypeName() const override { return "Point3D"; }
    // XML

    void SaveToXml(pugi::xml_node &node) const
    {
        node.append_child("x").text().set(x);
        node.append_child("y").text().set(y);
        node.append_child("z").text().set(z);
    }

    void LoadFromXml(pugi::xml_node &node)
    {
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

        pugi::xml_node node_x = node.child("x");
        pugi::xml_node node_y = node.child("y");
        pugi::xml_node node_z = node.child("z");
        if (!node_x || !node_y || !node_z)
            throw std::runtime_error("Missing <x>, <y>, or <z> element in XML");

        x = getValue(node_x);
        y = getValue(node_y);
        z = getValue(node_z);
    }

    // BINARY

    void SerializeBinary(std::vector<T> &node) const
    {
        size_t size = sizeof(x) + sizeof(y) + sizeof(z);
        node.resize(size);
        std::memcpy(node.data(), &x, sizeof(x));
        std::memcpy(node.data() + sizeof(x), &y, sizeof(y));
        std::memcpy(node.data() + sizeof(x) + sizeof(y), &z, sizeof(z));
    }

    void DeserializeBinary(const std::vector<T> &node)
    {
        if (node.size() != sizeof(x) + sizeof(y) + sizeof(z))
        {
            throw std::runtime_error("Binary data size mismatch");
        }
        std::memcpy(&x, node.data(), sizeof(x));
        std::memcpy(&y, node.data() + sizeof(x), sizeof(y));
        std::memcpy(&z, node.data() + sizeof(x) + sizeof(y), sizeof(z));
    }
};
#endif // POINT3D_H
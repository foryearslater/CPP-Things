#ifndef SERIALIZABLE_H_
#define SERIALIZABLE_H_

#include "pugixml.hpp"

#include <map>
#include <memory>
#include <vector>
#include <string>
#include <cstdint>

template <typename T>
class Serializable
{
public:
    virtual std::string GetTypeName() const = 0;
    // XML
    virtual void SaveToXml(pugi::xml_node &node) const = 0;
    virtual void LoadFromXml(pugi::xml_node &node) = 0;
    // BINARY
    virtual void SerializeBinary(std::vector<T> &node) const = 0;
    virtual void DeserializeBinary(const std::vector<T> &node) = 0;
};

#endif // SERIALIZABLE_H_
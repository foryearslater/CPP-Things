#ifndef SERIALIZEFACTORY_H_
#define SERIALIZEFACTORY_H_

#include "Serializable.hpp"

#include <memory>
#include <string>
#include <functional>
#include <iostream>
#include <map>

template <typename T>
class SerializeFactory
{
public:
    using func = std::function<std::unique_ptr<Serializable<T>>()>;
    static void Register(const std::string &type, func creator);
    static std::unique_ptr<Serializable<T>> Create(const std::string &type);

private:
    static std::map<std::string, func> &GetRegistry();
};
template <typename T>
std::map<std::string, typename SerializeFactory<T>::func> &SerializeFactory<T>::GetRegistry()
{
    static std::map<std::string, func> registry;
    return registry;
}

template <typename T>
void SerializeFactory<T>::Register(const std::string &type, func creator)
{
    GetRegistry()[type] = std::move(creator);
}

template <typename T>
std::unique_ptr<Serializable<T>> SerializeFactory<T>::Create(const std::string &type)
{
    auto &registry = GetRegistry();
    auto it = registry.find(type);
    if (it != registry.end())
    {
        return (it->second)();
    }
    return nullptr;
}
#endif // SERIALIZEFACTORY_H_
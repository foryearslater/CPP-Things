#include "TreeModelFactory.hpp"

std::shared_ptr<TreeModel> TreeModelFactory::GetTreeModel(const std::string& mesh, const std::string& texture) 
{
    std::string key = mesh + "_" + texture;

    auto it = m_flyweights.find(key);
    if (it == m_flyweights.end()) 
    {
        std::cout << "TreeModelFactory: Flyweight for '" << key << "' not found. Creating a new one." << std::endl;
        auto new_flyweight = std::make_shared<TreeModel>(mesh, texture);
        m_flyweights[key] = new_flyweight;
        return new_flyweight;
    } 
    else 
    {
        std::cout << "TreeModelFactory: Reusing existing flyweight for '" << key << "'." << std::endl;
        return it->second;
    }
}

void TreeModelFactory::ListFlyweights() const 
{
    std::cout << "\nTreeModelFactory has " << m_flyweights.size() << " flyweights in cache:" << std::endl;
    for (const auto& pair : m_flyweights) 
    {
        std::cout << "  - " << pair.first << std::endl;
    }
}
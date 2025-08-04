#include "Folder.hpp"
#include <iostream>
#include <algorithm> 

Folder::Folder(const std::string& name) : m_name(name) {}

const std::string& Folder::GetName() const 
{
    return m_name;
}

int Folder::GetSize() const 
{
    int total_size = 0;
    for (const auto& child : m_children) 
    {
        if (child) 
        {
            total_size += child->GetSize();
        }
    }
    return total_size;
}

void Folder::Display(int indent) const 
{
    std::cout << std::string(indent * 2, ' ') << "+ " << m_name << "/" << std::endl;
    for (const auto& child : m_children) 
    {
        if (child) 
        {
            child->Display(indent + 1);
        }
    }
}

void Folder::Add(std::shared_ptr<FileSystemComponent> component) 
{
    m_children.push_back(component);
}

void Folder::Remove(std::shared_ptr<FileSystemComponent> component) 
{
    m_children.erase(std::remove(m_children.begin(), m_children.end(), component), m_children.end());
}
#include "File.hpp"
#include <iostream>

File::File(const std::string& name, int size) : m_name(name), m_size(size) {}

const std::string& File::GetName() const 
{
    return m_name;
}

int File::GetSize() const 
{
    return m_size;
}

void File::Display(int indent) const 
{
    std::cout << std::string(indent * 2, ' ') << "- " << m_name 
              << " (" << m_size << " bytes)" << std::endl;
}
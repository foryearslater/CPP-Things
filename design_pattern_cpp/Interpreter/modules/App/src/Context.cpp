#include "Context.hpp"
#include <iostream>

Context::Context() 
{
    std::cout << "Context created." << std::endl;
}

Context::~Context() 
{
    std::cout << "Context destroyed." << std::endl;
}

int Context::GetValue(const std::string& varName) const 
{
    auto it = m_variables.find(varName);
    if (it != m_variables.end()) 
    {
        return it->second;
    }
    std::cerr << "Error: Variable '" << varName << "' not found in context." << std::endl;
    return 0; 
}

void Context::SetValue(const std::string& varName, int value) 
{
    m_variables[varName] = value;
    std::cout << "Context: Set variable '" << varName << "' to " << value << std::endl;
}
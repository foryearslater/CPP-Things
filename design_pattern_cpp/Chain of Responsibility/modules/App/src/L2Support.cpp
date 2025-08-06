#include "L2Support.hpp"

L2Support::L2Support() 
{
    std::cout << "L2Support handler created." << std::endl;
}

L2Support::~L2Support() 
{
    if (m_nextHandler) 
    {
        delete m_nextHandler;
    }
    std::cout << "L2Support handler destroyed." << std::endl;
}

SupportHandler* L2Support::SetNext(SupportHandler* nextHandler) 
{
    m_nextHandler = nextHandler;
    return nextHandler;
}

bool L2Support::Handle(const Request& request) 
{
    if (request.type == Request::TECHNICAL) 
    {
        std::cout << "L2Support: Handled request '" << request.description << "' (Type: TECHNICAL)." << std::endl;
        return true;
    } 
    else if (m_nextHandler) 
    {
        std::cout << "L2Support: Cannot handle request '" << request.description << "'. Passing to next handler." << std::endl;
        return m_nextHandler->Handle(request);
    } 
    else 
    {
        std::cout << "L2Support: No handler for request '" << request.description << "'. (End of chain)" << std::endl;
        return false;
    }
}
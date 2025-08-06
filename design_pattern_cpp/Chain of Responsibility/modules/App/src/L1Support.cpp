#include "L1Support.hpp"


L1Support::L1Support() 
{
    std::cout << "L1Support handler created." << std::endl;
}

L1Support::~L1Support() 
{
    if (m_nextHandler) 
    {
        delete m_nextHandler; 
    }
    std::cout << "L1Support handler destroyed." << std::endl;
}


SupportHandler* L1Support::SetNext(SupportHandler* nextHandler) 
{
    m_nextHandler = nextHandler;
    return nextHandler;
}

bool L1Support::Handle(const Request& request) 
{
    if (request.type == Request::GENERAL)
    {
        std::cout << "L1Support: Handled request '" << request.description << "' (Type: GENERAL)." << std::endl;
        return true;
    } 
    else if (m_nextHandler) 
    {
        std::cout << "L1Support: Cannot handle request '" << request.description << "'. Passing to next handler." << std::endl;
        return m_nextHandler->Handle(request);
    } 
    else 
    {
        std::cout << "L1Support: No handler for request '" << request.description << "'. (End of chain)" << std::endl;
        return false;
    }
}
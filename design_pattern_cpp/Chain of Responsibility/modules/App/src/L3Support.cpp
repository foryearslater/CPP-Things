#include "L3Support.hpp"


L3Support::L3Support() 
{
    std::cout << "L3Support handler created." << std::endl;
}


L3Support::~L3Support() 
{
    if (m_nextHandler) 
    {
        delete m_nextHandler; 
    }
    std::cout << "L3Support handler destroyed." << std::endl;
}

SupportHandler* L3Support::SetNext(SupportHandler* nextHandler) 
{
    m_nextHandler = nextHandler;
    return nextHandler;
}

bool L3Support::Handle(const Request& request) 
{
    if (request.type == Request::BILLING || request.type == Request::CRITICAL) 
    {
        std::cout << "L3Support: Handled request '" << request.description << "' (Type: "
                  << (request.type == Request::BILLING ? "BILLING" : "CRITICAL") << ")." << std::endl;
        return true;
    } 
    else if (m_nextHandler) 
    {
        std::cout << "L3Support: Cannot handle request '" << request.description << "'. Passing to next handler." << std::endl;
        return m_nextHandler->Handle(request);
    } 
    else 
    {
        std::cout << "L3Support: No handler for request '" << request.description << "'. (End of chain)" << std::endl;
        return false;
    }
}
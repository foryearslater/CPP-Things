#pragma once
#include <string>
#include <memory> 

struct Request 
{
    enum Type 
    {
        GENERAL,        // 一般问题
        TECHNICAL,      // 技术问题
        BILLING,        // 账单问题
        CRITICAL        // 紧急问题
    };
    Type type;            
    std::string description; 
};

/**
 * @class SupportHandler
 * @brief 抽象处理者接口：定义处理请求的接口, 并维护一个指向链中下一个处理者的引用
 * @detail 所有具体处理者都必须实现此接口
 */

class SupportHandler 
{
public:
    
    virtual ~SupportHandler() = default;

    virtual SupportHandler* SetNext(SupportHandler* nextHandler) = 0;

    virtual bool Handle(const Request& request) = 0;

protected:

    SupportHandler* m_nextHandler = nullptr;

};
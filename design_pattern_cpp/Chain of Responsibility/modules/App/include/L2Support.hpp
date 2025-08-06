#pragma once
#include "SupportHandler.hpp" 
#include <iostream>

/**
 * @class L2Support
 * @brief 具体处理者:中级支持处理者
 * @detail 能够处理技术性问题, 否则将请求传递给下一个处理者
 */

class L2Support : public SupportHandler 
{
public:
  
    L2Support();

    ~L2Support() override;

    SupportHandler* SetNext(SupportHandler* nextHandler) override;

    bool Handle(const Request& request) override;

};
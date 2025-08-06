#pragma once
#include "SupportHandler.hpp"
#include <iostream>

/**
 * @class L1Support
 * @brief 具体处理者:初级支持处理者
 * @detail 能够处理一般性问题, 否则将请求传递给下一个处理者
 */
class L1Support : public SupportHandler 
{
public:

    L1Support();

    ~L1Support() override;

    SupportHandler* SetNext(SupportHandler* nextHandler) override;

    bool Handle(const Request& request) override;

};
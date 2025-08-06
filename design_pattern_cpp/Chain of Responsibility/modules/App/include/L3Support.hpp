#pragma once
#include "SupportHandler.hpp" 
#include <iostream>

/**
 * @class L3Support
 * @brief 具体处理者：高级支持处理者
 * @detail 能够处理账单和紧急问题，否则无法处理
 */
class L3Support : public SupportHandler 
{
public:
   
    L3Support();

    ~L3Support() override;

    SupportHandler* SetNext(SupportHandler* nextHandler) override;

    bool Handle(const Request& request) override;

};
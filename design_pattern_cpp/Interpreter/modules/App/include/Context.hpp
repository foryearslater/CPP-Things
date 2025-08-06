#pragma once
#include <map>
#include <string>

/**
 * @class Context
 * @brief 上下文：存储解释器在执行过程中需要的信息
 *
 */
class Context
{
public:
    Context();

    ~Context();

    int GetValue(const std::string &varName) const;

    void SetValue(const std::string &varName, int value);

private:
    std::map<std::string, int> m_variables;
};
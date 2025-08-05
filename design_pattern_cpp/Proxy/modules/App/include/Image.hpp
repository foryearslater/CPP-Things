#pragma once
#include <string>

/**
 * @class Image
 * @brief 主题接口：定义了图像的基本操作
 * @detail 真实图像和代理图像都将实现这个接口，确保它们能够互换使用
 */
class Image
{
public:
    virtual ~Image() = default;

    virtual void Display() const = 0;
};
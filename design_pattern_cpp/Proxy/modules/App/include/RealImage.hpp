#pragma once
#include "Image.hpp" 
#include <iostream>  

/**
 * @class RealImage
 * @brief 真实主题：表示一个实际的图像对象。
 * @detail 实现了Image接口，负责加载和显示图片
 */
class RealImage : public Image 
{
public:

    explicit RealImage(const std::string& filename);

    ~RealImage() override;

    void Display() const override;

private:

    std::string m_filename; 

    void LoadFromDisk() const;

};
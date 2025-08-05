#pragma once
#include "Image.hpp"      
#include "RealImage.hpp" 

/**
 * @class ProxyImage
 * @brief 代理：为RealImage提供一个替身
 * @detail 实现了Image接口，并控制对RealImage的访问
 */      
class ProxyImage : public Image 
{
public:

    explicit ProxyImage(const std::string& filename);

    ~ProxyImage() override;

    void Display() const override;

private:

    std::string m_filename;             

    mutable RealImage* m_realImage; 

};
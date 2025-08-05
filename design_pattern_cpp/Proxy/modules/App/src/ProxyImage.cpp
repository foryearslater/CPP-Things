#include "ProxyImage.hpp"
#include <iostream>


ProxyImage::ProxyImage(const std::string& filename) : m_filename(filename), m_realImage(nullptr) 
{
    std::cout << "ProxyImage (" << m_filename << ") created, real image not loaded yet." << std::endl;
}

ProxyImage::~ProxyImage() {
    if (m_realImage) 
    {
        delete m_realImage;
    }
    std::cout << "ProxyImage (" << m_filename << ") destroyed." << std::endl;
}



void ProxyImage::Display() const 
{
    if (!m_realImage) 
    {
        std::cout << "Proxy: First time display, creating RealImage for " << m_filename << "..." << std::endl;
        m_realImage = new RealImage(m_filename);
    }
    m_realImage->Display();
}
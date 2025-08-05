#include "RealImage.hpp"
#include <thread>   
#include <chrono>  

RealImage::RealImage(const std::string& filename) : m_filename(filename) 
{
    LoadFromDisk(); 
}


RealImage::~RealImage() 
{
    std::cout << "RealImage (" << m_filename << ") destroyed." << std::endl;
}

void RealImage::LoadFromDisk() const 
{
    std::cout << "Loading " << m_filename << " from disk... (This takes time)" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2)); 
    std::cout << "Finished loading " << m_filename << "." << std::endl;
}

void RealImage::Display() const 
{
    std::cout << "Displaying " << m_filename << "." << std::endl;
}
#include <iostream>
#include <memory> 

#include "Image.hpp"
#include "RealImage.hpp"
#include "ProxyImage.hpp"

void ClientCode(const Image* img) 
{
    std::cout << "Client: Attempting to display image..." << std::endl;
    img->Display(); 
    std::cout << "Client: Image displayed." << std::endl;
    
    std::cout << "Client: Attempting to display image again..." << std::endl;
    img->Display(); 
    std::cout << "Client: Image displayed again." << std::endl;
    std::cout << std::endl;
}


int main() 
{
    std::unique_ptr<Image> realImg = std::make_unique<RealImage>("photo_real.jpg");
    ClientCode(realImg.get()); 

    std::unique_ptr<Image> proxyImg = std::make_unique<ProxyImage>("photo_proxy.jpg");
    ClientCode(proxyImg.get()); 
    return 0;
}
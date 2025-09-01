#include <iostream>
#include <thread>
#include <chrono>

volatile bool isDeviceReady = false;

void setupDevice() 
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Ready  !" << std::endl;
    isDeviceReady = true;
}

int main() 
{
    std::cout << "Begin : " << std::endl;
    std::thread deviceThread(setupDevice);

    
    while (!isDeviceReady) 
    {

    }

    deviceThread.join();
    return 0;
}
#include <mutex>
#include <iostream>
#include <thread>

std::mutex mtx;

void print(int n, char c)
{
    mtx.lock();
    for (int i = 0; i < n; i++)
    {
        std::cout << c;
    }
    std::cout << std::endl;
    mtx.unlock();
}
int main()
{
    std::thread a(print, 10, 'a');
    std::thread b(print, 10, 'b');
    a.join();
    b.join();
    return 0;
}
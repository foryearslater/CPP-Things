#include <mutex>
#include <iostream>
#include <thread>

std::mutex mtx1;
std::mutex mtx2;

int num = 1;
void print1(int n, char c)
{
    mtx1.lock();
    num = 1;
    for (int i = 0; i < n; i++)
    {
        num = 1;
        // std::cout << c;
        std::cout << num << " ";
    }
    std::cout << std::endl;
    mtx1.unlock();
}
void print2(int n, char c)
{
    mtx2.lock();
    num = 2;
    for (int i = 0; i < n; i++)
    {
        num = 2;
        // std::cout << c;
        std::cout << num << " ";
    }
    std::cout << std::endl;
    mtx2.unlock();
}
int main()
{
    std::thread a(print1, 10, 'a');
    std::thread b(print2, 10, 'b');
    a.join();
    b.join();
    return 0;
}
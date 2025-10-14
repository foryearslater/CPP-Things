#include <iostream>
#include <atomic>
#include <thread>

void thread_1()
{
    while (1)
    {
        std::cout << "子线程1111" << std::endl;
    }
}

void thread_2(int x)
{
    while (1)
    {
        std::cout << "子线程2222" << std::endl;
    }
}

int main()
{
    std::thread first(thread_1);
    std::thread second(thread_2, 100);

    first.detach();
    second.detach();
    for (int i = 0; i < 10; i++)
    {
        std::cout << "主线程\n";
    }
    return 0;
}

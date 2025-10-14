#include <thread>
#include <mutex>
#include <iostream>

int i = 0;
std::mutex mtx;

void safe_increment()
{
    const std::lock_guard<std::mutex> lock(mtx);
    ++i;
    std::cout << std::this_thread::get_id() << ": " << i << '\n';
    std::cout << "main id: " << std::this_thread::get_id() << std::endl;
    std::cout << "main: " << i << '\n';

    std::thread t1(safe_increment);
    std::thread t2(safe_increment);

    t1.join();
    t2.join();

    std::cout << "main: " << i << '\n';
}

int main()
{
    safe_increment();
    return 0;
}
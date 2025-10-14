#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
/*
两个线程，一个不停打印a，一个不停打印b，那么如何操作，使得可以在输出时a、b交替输出
*/
std::mutex mtx;
std::condition_variable cv;
std::atomic<bool> flag{true};

void print(char c, bool is_a)
{
    for (int i = 0; i < 10; i++)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]
                { return is_a == flag.load(); });
        std::cout << c;
        flag.store(!flag);
        cv.notify_one();
    }
}
int main()
{
    std::thread t1(print, 'a', true);
    std::thread t2(print, 'b', false);
    t1.join();
    t2.join();
    std::cout << std::endl;
    return 0;
}
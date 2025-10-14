#include <thread>
#include <mutex>
#include <iostream>
#include <atomic>
#include <condition_variable>
std::mutex mtx;
std::condition_variable cv;
std::atomic<int> a;
void print(char c, bool flag)
{
    for (int i = 0; i < 10; i++)
    {
        std::unique_lock<std::mutex> q(mtx);
        cv.wait(q, [&]
                { return flag == a.load(); });
        std::cout << c;

        cv.notify_one();
    }
    a.store(!a);
}

int main()
{
    std::thread a(print, 'a', 0);
    std::thread b(print, 'b', 1);
    a.join();
    b.join();
}
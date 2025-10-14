#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int cargo = 0;
bool check()
{
    return cargo != 0;
}
void consume(int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, check);
        std::cout << cargo << '\n';
        cargo = 0;
    }
}
int main()
{
    std::thread thread(consume, 10);
    for (int i = 0; i < 10; ++i)
    {
        while (check())
        {
            std::this_thread::yield();
        }
        std::unique_lock<std::mutex> lck(mtx);
        cargo = i + 1;
        cv.notify_one();
    }

    thread.join();
    return 0;
}
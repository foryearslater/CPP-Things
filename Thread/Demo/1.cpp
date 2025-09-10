#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>

std::mutex mtx;
std::condition_variable cv;
bool num_turn = true;

void print_func(const std::string& str, bool is_num_thread) 
{
    for (char c : str) 
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [is_num_thread] { return num_turn == is_num_thread; });
        std::cout << c;
        num_turn = !num_turn;
        cv.notify_one();
    }
}

int main() 
{
    std::thread t1(print_func, "1234", true);
    std::thread t2(print_func, "abcd", false);
    t1.join();
    t2.join();
    std::cout << std::endl;
    return 0;
}
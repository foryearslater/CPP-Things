#include <mutex>
#include <thread>
#include <iostream>

struct Box
{
    explicit Box(int num) : num{num} {}
    int num;
    std::mutex m;
};
void transfer(Box &from, Box &to, int num)
{
    std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
    std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);
    std::lock(lock1, lock2);

    from.num -= num;
    to.num += num;
}

int main()
{
    Box acc1(100);
    Box acc2(50);

    std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
    std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);

    t1.join();
    t2.join();
    std::cout << "acc1 num_things: " << acc1.num << std::endl;
    std::cout << "acc2 num_things: " << acc2.num << std::endl;
}

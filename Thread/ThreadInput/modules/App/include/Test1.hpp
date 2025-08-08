#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int cur = 1;
int thread_id = 0;

void print(int id)
{
	while (true)
	{
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, [id]() { return id == thread_id; });
		if (cur > 100)
		{
			thread_id = (thread_id + 1) % 3;
			cv.notify_all();
			break;
		}
		std::cout << "Thread " << id + 1 << ": " << cur++ << std::endl;
		thread_id = (thread_id + 1) % 3;
		cv.notify_all();
	}
}

void test1()
{
	std::thread t1(print, 0);
	std::thread t2(print, 1);
	std::thread t3(print, 2);
	t1.join();
	t2.join();
	t3.join();
}
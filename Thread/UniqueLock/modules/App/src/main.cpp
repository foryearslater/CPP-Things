#include <iostream>
#include <mutex>

std::timed_mutex mutex;

void Work1()
{
	std::unique_lock ulock(mutex, std::defer_lock);
	ulock.lock();
	std::cout << "Work1 Locked" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "Work1 To Die" << std::endl;
}

void Work2()
{
	std::unique_lock ulock(mutex, std::defer_lock);
	if (ulock.try_lock_for(std::chrono::seconds(1)))
	{
		std::cout << "Work2 Locked" << std::endl;
	}
	else
	{
		std::cout << "Work2 Not Lock" << std::endl;
	}
}

void Work3()
{
	std::unique_lock ulock(mutex, std::defer_lock);
	if (ulock.try_lock_for(std::chrono::seconds(4)))
	{
		std::cout << "Work3 Locked" << std::endl;
	}
	else
	{
		std::cout << "Work3 Not Lock" << std::endl;
	}
}

int main()
{
	std::jthread th1(Work1);

	std::this_thread::sleep_for(std::chrono::milliseconds(200));

	std::jthread th2(Work2);
	std::jthread th3(Work3);

	return 0;
}
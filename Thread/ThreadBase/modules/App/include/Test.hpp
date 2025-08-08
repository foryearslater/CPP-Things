#include <thread>
#include <string>

//线程等待

void test1()
{
	auto threadFunc = [](std::string str) 
    {
		std::cout << "str is " << str << std::endl;
	};
	std::string str = "Hello, world!";
	std::thread t1(threadFunc, str);
	t1.join();
}

//线程允许采用分离的方式在后台独自运行称为守护线程
struct func
{
	int& _i;
	func(int& i) : _i(i) {}
	void operator()() const
	{
		for (int i = 0; i < 3; i++) {
			_i = i;
			std::cout << "_i is " << _i << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
};

void test2()
{
	int state = 0;
	func f(state);
	std::thread t2(f);
	t2.detach();
}
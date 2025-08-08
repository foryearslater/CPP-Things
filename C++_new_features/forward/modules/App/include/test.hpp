#include <iostream>
#include <vector>

//左值

void test1()
{
	int x = 20;
	int& p = x;
	p = 21;
	std::cout << x << " " << p << std::endl;
}

//右值

void test2()
{
	int&& x = 20;
	std::cout << x << " ";
	x = 21;
	std::cout << x << std::endl;
}


//std::move

void test3()
{
	std::vector<int> a = { 1, 2, 3, 4, 5 };
	std::vector<int>b = std::move(a);

	std::cout << "a:" << a.size() << " b:" << b.size() << std::endl;
	for (auto x : a)
	{
		std::cout << x << " ";
	}

	std::cout << std::endl;

	for (auto x : b)
	{
		std::cout << x << " ";
	}

	std::cout << std::endl;
}

//右值 + 完美转发

template<typename Func, typename... Args>
auto performTest(Func func, Args&&... args)
{
	func(std::forward<Args>(args)...);
}

void print(int a, int b)
{
	std::cout << "sum = " << a + b << std::endl;
}

void test4()
{
	int x = 10;
	int y = 20;
	performTest(print, x, y);
	performTest(print, std::move(x), std::move(y));
}

//用完美转发实现委托构造函数

class MyString
{
public:
	template <typename... Args>
	MyString(Args&&... args) : _data(std::forward<Args>(args)...) {}
private:
	std::string _data;
};

void test5()
{
	MyString str1("Hello, World!");
	MyString str2(10, 'A');
	MyString str3(std::string("Hello, World!"));
	MyString str4(std::move(std::string("Hello, World!")));
}

//结合 std::unique_ptr 和完美转发 (所有权转移)

class MyObject
{
public:
	int id;
	MyObject(int i) : id(i)
	{
		std::cout << "  MyObject " << id << " constructed" << std::endl;
	}
	MyObject(const MyObject& other) : id(other.id)
	{
		std::cout << "  MyObject " << id << " copy-constructed" << std::endl;
	}
	MyObject(MyObject&& other) noexcept : id(other.id)
	{
		std::cout << "  MyObject " << id << " move-constructed" << std::endl; other.id = -1;
	}
	~MyObject()
	{
		std::cout << "  MyObject " << id << " destructed" << std::endl;
	}
};

void consume_object(MyObject& obj) 
{
	std::cout << "  consume_object(Lvalue): Processing MyObject " << obj.id << std::endl;
}
void consume_object(MyObject&& obj) 
{
	std::cout << "  consume_object(Rvalue): Processing and moving MyObject " << obj.id << std::endl;
}

template<typename T, typename... Args>
std::unique_ptr<T> make_unique_wrapper(Args&&... args) 
{
	std::cout << "make_unique_wrapper inner: ";
	return std::make_unique<T>(std::forward<Args>(args)...);
}

void test6() 
{
	std::unique_ptr<MyObject> u_ptr1 = make_unique_wrapper<MyObject>(100);
	std::cout << "u_ptr1 id: " << u_ptr1->id << std::endl;

	std::unique_ptr<MyObject> u_ptr2 = std::move(u_ptr1);
	std::cout << "u_ptr1 id: " << (u_ptr1 ? u_ptr1->id : -1) << std::endl;
	std::cout << "u_ptr2 id: " << u_ptr2->id << std::endl;
}
#include <iostream>
#include <vector>

//valid
struct Info1
{
	uint8_t a;
	uint16_t b;
	uint8_t c;
};
void test1()
{
	std::cout << sizeof(Info1) << std::endl;
	std::cout << alignof(Info1) << std::endl;
}

struct alignas (4) Info2
{
	uint8_t a;
	uint16_t b;
	uint8_t c;
};

void test2()
{
	std::cout << sizeof(Info2) << std::endl;
	std::cout << alignof(Info2) << std::endl;
}
//invalid

struct Info3
{
	uint8_t a;
	uint32_t b;
	uint8_t c;
};
void test3()
{
	std::cout << sizeof(Info3) << std::endl;
	std::cout << alignof(Info3) << std::endl;
}

struct alignas (4) Info4
{
	uint8_t a;
	uint32_t b;
	uint8_t c;
};

void test4()
{
	std::cout << sizeof(Info4) << std::endl;
	std::cout << alignof(Info4) << std::endl;
}

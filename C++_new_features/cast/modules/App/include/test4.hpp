#include <iostream>
#include <cstdint> 

struct MyData 
{
    int a;
    char b;
};

void test4()
{
    int my_int = 123;
    int* p_int = &my_int;

    uintptr_t int_addr = reinterpret_cast<uintptr_t>(p_int);
    std::cout << "Address as integer: " << std::hex << int_addr << std::endl;

    int* p_int_again = reinterpret_cast<int*>(int_addr);

    std::cout << "Value from restored pointer: " << std::dec << *p_int_again << std::endl;
    MyData data = { 65, 'B' };
    MyData* p_data = &data;

    char* p_char = reinterpret_cast<char*>(p_data);

    std::cout << "First byte of MyData: " << static_cast<int>(*p_char) << std::endl;

    std::cout << "Fifth byte of MyData (char 'b'): " << *(p_char + sizeof(int)) << std::endl;
}
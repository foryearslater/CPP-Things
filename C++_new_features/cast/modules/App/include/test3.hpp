#include <iostream>

void print(char* str) 
{
    std::cout << "function received: " << str << std::endl;
}


void test3()
{
    std::string message = "Hello, world!";
    const std::string& const_ref_message = message;

    print(const_cast<char*>(const_ref_message.c_str()));

    const int const_value = 100;
    int* non_const_ptr = const_cast<int*>(&const_value);

    *non_const_ptr = 200; 

}
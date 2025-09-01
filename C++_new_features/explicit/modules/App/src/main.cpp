#include <iostream>
#include <string>

class MyString 
{
public:
    explicit MyString(int size) 
    {
        m_str.resize(size);
        std::cout << "MyString(" << size << ") use" << std::endl;
    }

    MyString(const char* c_str) 
    {
        m_str = c_str;
        std::cout << "MyString(const char*) use" << std::endl;
    }
    
    void print() const 
    {
        std::cout << "len =  " << m_str.length() << "  " << std::endl;
    }

private:
    std::string m_str;
};

void processString(const MyString& s) 
{
    s.print();
}

int main() 
{
    MyString s1(10); 
    processString(s1);

    MyString s2 = MyString(20);
    processString(s2);

    // 隐式转换 - 由于 explicit，这行代码会编译失败
    // MyString s3 = 5; // 错误：无法从 "int" 转换为 "MyString"
    
    // 在函数调用时进行隐式转换 - 同样会编译失败
    // processString(15); // 错误：没有可用的转换

    // 但是，从 const char* 的转换是允许的，因为那个构造函数没有 explicit
    MyString s4 = "hello"; 
    processString(s4);       
    processString("world");  

    return 0;
}
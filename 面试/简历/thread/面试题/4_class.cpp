#include <bits/stdc++.h>

// 1.1
//  只在堆上创建不在栈上创建
//  构造函数私有化
//  禁止拷贝构造 禁用赋值
//  class Demo1
//  {
//  public:
//      ~Demo1() = default;
//      static Demo1 *Create()
//      {
//          return new Demo1(); // 静态变量函数创建对象
//      }
//      Demo1(const Demo1 &) = delete;            // 禁止拷贝构造
//      Demo1 &operator=(const Demo1 &) = delete; // 禁止拷贝
//  private:
//      Demo1() = default; // 私有构造函数,禁止在栈上创建对象
//  };
// 私有析构
//  class Demo2
//  {
//  public:
//      Demo2() = default;
//      void Destory()
//      {
//          delete this;
//      }
//  private:
//      ~Demo2() = default;
//  };

// 最佳实践

class Demo3
{
public:
    static Demo3 *Create()
    {
        return new Demo3();
    }
    Demo3(const Demo3 &) = delete;            // 禁止拷贝构造
    Demo3 &operator=(const Demo3 &) = delete; // 禁止拷贝
    void Destory()
    {
        delete this;
    }

private:
    Demo3() = default;
    ~Demo3() = default;
};

// 1.1
//  只在栈上创建不在堆上创建
class StackOnly
{
public:
    StackOnly() = default;
    ~StackOnly() = default;
    void *operator new(size_t) = delete;
    void *operator new[](size_t) = delete;
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // 1.1
    // Demo1 d1;
    // Demo1 *d = Demo1::Create();
    // Demo1 dd = *d;
    // 1.2
    // Demo1 d1;
    // Demo1 *d = Demo1::Create();
    // Demo1 dd = *d;

    // 1.3
    //  Demo3 * d = Demo3::Create();
    //  d->Destory();

    // 2.0
    StackOnly obj;
    // StackOnly obj1 = new StackOnly();
    return 0;
}
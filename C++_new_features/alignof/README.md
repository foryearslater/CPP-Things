
#  C++ 结构体内存对齐、`alignof` 和 `alignas`

内存对齐是计算机体系结构中一个重要的概念，它影响着程序性能和内存使用。在 C++ 中，结构体（struct）和类（class）的成员变量在内存中的布局遵循一定的对齐规则。理解这些规则以及如何使用 `alignof` 和 `alignas` 关键字可以帮助开发者编写更高效、更可靠的代码。

## 什么是内存对齐？

内存对齐是指数据在内存中的存储地址必须是其大小（或其类型的特定对齐要求）的整数倍。例如，一个 4 字节的 `int` 类型变量如果要求 4 字节对齐，那么它在内存中的地址就必须是 4 的倍数（0x0, 0x4, 0x8 等）。

### 为什么需要内存对齐？

1. **CPU 访问效率：** 许多 CPU 在访问内存时，会以字（word）为单位进行读取。如果数据没有对齐，CPU 可能需要进行多次内存访问，甚至需要特殊的硬件处理，这会大大降低数据访问速度。对齐的数据可以一次性高效地读取。
2. **硬件限制：** 某些硬件平台要求特定类型的数据必须对齐，否则可能导致程序崩溃或未定义行为。
3. **原子操作：** 在多线程编程中，原子操作通常要求数据是对齐的，以确保操作的正确性和一致性。

### 结构体内存对齐规则

C++ 编译器通常会为结构体或类中的成员变量进行内存对齐，遵循以下基本规则：

1. **成员变量对齐：** 每个成员变量会按照其自身类型的大小（或其平台特定的对齐要求）进行对齐。例如，一个 `char` 占用 1 字节，通常 1 字节对齐；一个 `int` 占用 4 字节，通常 4 字节对齐；一个 `double` 占用 8 字节，通常 8 字节对齐。
2. **结构体总大小对齐：** 整个结构体的大小必须是其**最大成员变量对齐值**的整数倍。如果不是，编译器会在结构体的末尾填充字节（padding）。
3. **成员顺序对齐：** 成员变量按照它们在结构体中声明的顺序依次分配内存。

**示例：**

```cpp
struct MyStruct {
    char c;    // 1字节
    int i;     // 4字节
    short s;   // 2字节
    double d;  // 8字节
};
```

**假设在 64 位系统上，默认对齐值是 8 字节。**

* **c** **(char): 偏移量 0，占用 1 字节。**
* **i** **(int): 偏移量需要是 4 的倍数。当前偏移量是 1，所以填充 3 字节，**i **的偏移量变为 4，占用 4 字节。**
* **s** **(short): 偏移量需要是 2 的倍数。当前偏移量是 8，**s **的偏移量变为 8，占用 2 字节。**
* **d** **(double): 偏移量需要是 8 的倍数。当前偏移量是 10，所以填充 6 字节，**d **的偏移量变为 16，占用 8 字节。**

**结构体总大小：16 (d 的起始) + 8 (d 的大小) = 24 字节。**
最大成员对齐值是 **double** **的 8 字节。24 是 8 的倍数，所以不需要在末尾填充。**
sizeof(MyStruct) **将是 24。**

## alignof **关键字**

**alignof** **是一个一元运算符，它返回一个** **std::size_t** **类型的值，表示给定类型或表达式的对齐要求（以字节为单位）。它是一个编译时常量。**

### 语法

**code**C++

```
alignof(type-id)
```

### 用途

* **查询对齐值：** **允许你查询任何类型的对齐要求，包括基本类型、结构体、类等。**
* **诊断和调试：** **在理解内存布局和对齐问题时非常有用。**

### 示例

**code**C++

```
#include <iostream>

struct MyData {
    char a;
    int b;
    double c;
};

int main() {
    std::cout << "Alignment of char: " << alignof(char) << std::endl;        // 通常为 1
    std::cout << "Alignment of int: " << alignof(int) << std::endl;         // 通常为 4
    std::cout << "Alignment of double: " << alignof(double) << std::endl;   // 通常为 8
    std::cout << "Alignment of MyData: " << alignof(MyData) << std::endl;   // 通常为 8 (取决于最大成员)
  
    // 查询变量的对齐值
    int x;
    std::cout << "Alignment of x: " << alignof(x) << std::endl;
  
    return 0;
}
```

## alignas **关键字**

**alignas** **是一个类型说明符，用于指定变量、结构体或类的对齐要求。它可以强制编译器为数据分配更大的对齐空间。**

### 语法

**code**C++

```
alignas(alignment_value) type-id;
alignas(type-id) type-id; // 使用另一个类型的对齐值
```

**其中** **alignment_value** **必须是一个等于 2 的幂的整数常量表达式，表示所需的字节对齐。**

### 用途

* **强制对齐：** **当需要特定的对齐时，例如为了与某些硬件接口或 SIMD 指令集（如 SSE/AVX 要求 16 字节或 32 字节对齐）兼容时。**
* **性能优化：** **在某些情况下，强制更高的对齐可以提高缓存效率。**
* **避免伪共享（False Sharing）：** **在多线程环境中，如果不同线程修改的变量恰好在同一个缓存行中，即使它们在内存中不相邻，也可能导致性能下降。通过** **alignas** **将这些变量放置在不同的缓存行中可以避免伪共享。**

### 示例

**code**C++

```
#include <iostream>

// 强制 MyAlignedStruct 16 字节对齐
struct alignas(16) MyAlignedStruct {
    int data[4]; // 16 字节
};

// 使用 double 的对齐值来对齐 MyAnotherStruct
struct alignas(double) MyAnotherStruct {
    char c;
    int i;
};

int main() {
    std::cout << "Alignment of MyAlignedStruct: " << alignof(MyAlignedStruct) << std::endl; // 输出 16
    std::cout << "Size of MyAlignedStruct: " << sizeof(MyAlignedStruct) << std::endl;     // 输出 16
  
    std::cout << "Alignment of MyAnotherStruct: " << alignof(MyAnotherStruct) << std::endl; // 通常为 8 (double 的对齐值)
    std::cout << "Size of MyAnotherStruct: " << sizeof(MyAnotherStruct) << std::endl;     // 通常为 8 (char 1 + padding 3 + int 4 = 8)

    // 强制单个变量对齐
    alignas(32) int aligned_int_array[8];
    std::cout << "Alignment of aligned_int_array: " << alignof(aligned_int_array) << std::endl; // 输出 32
  
    return 0;
}
```

### 注意事项

* **alignas** **只能**增加**对齐要求，不能减少。如果指定的对齐值小于类型默认的对齐值，**alignas **将被忽略，使用默认对齐。**
* **过度对齐可能会导致内存浪费。**
* **alignas** **不能用于函数参数或非静态数据成员的位域。**

## 总结

* **内存对齐** **是为了提高 CPU 访问效率和满足硬件要求。**
* **alignof** **用于查询类型或变量的对齐要求。**
* **alignas** **用于强制指定类型或变量的对齐要求，常用于性能优化和与硬件兼容。**

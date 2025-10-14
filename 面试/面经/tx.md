C++ 基础

1.构造函数可以是虚函数吗？为什么？

答案：不可以。原因如下：

构造对象的时候，必须知道对象的实际类型。而虚函数行为是在运行期间确定实际类型的，在构造对象时，对象还没有构造成功，编译器无法知道对象的实际类型是该类本身还是其派生类。
虚函数的运行依赖于虚函数指针，而虚函数指针在构造函数中进行初始化，让它指向正确的虚函数表。在对象构造期间，虚函数指针还未构造完成。
2.C++ 虚函数原理

答案：虚函数依赖于虚函数指针实现。每个拥有虚函数的类都有一个虚表，类的对象存在一个虚函数指针，指向实际类型的虚表。虚函数运行的时候，会根据虚函数指针找到正确的虚表，从而执行正确的虚函数。

3.C++ 多态的实现

答案：多态分为运行时的多态和编译时的多态。

运行时多态（动态绑定）：由虚函数来实现。当通过基类指针或引用调用虚函数时，会根据对象的实际类型来决定调用哪个虚函数版本。
编译时多态（静态绑定）：由函数重载来实现。在编译阶段，编译器根据函数调用时的参数类型和个数来确定调用哪个函数版本。
4.C++ vector 和 list 的区别

答案：

数据结构：vector 是动态数组，它会动态进行分配内存，进行扩容操作；list 是双向链表。
内存分配：vector 的内存是连续的，适合随机访问；list 的内存是不连续的，通过指针链接各个节点，不适合随机访问，但在插入和删除操作上更高效。
迭代器：对 vector 的修改（如插入、删除元素）可能导致 vector 的迭代器失效；list 因为是双向链表，在插入和删除元素时，只要操作的不是迭代器指向的节点，迭代器就不会失效。
5.C++ vector 的底层实现原理

答案：vector 底层基于动态数组实现。它维护一个连续的内存空间来存储元素，当元素数量超过当前容量时，会重新分配一块更大的内存空间，将原有的元素复制到新空间中，然后释放旧空间。同时，vector 还记录了当前的元素个数和容量信息。

6.C++ map 的底层实现

答案：map 的底层实现是基于红黑树。红黑树是一种自平衡的二叉搜索树，它保证了在最坏情况下，插入、删除和查找操作的时间复杂度都是 O (log n)。map 通过红黑树来存储键值对，根据键的大小进行排序，从而实现高效的查找操作。

7.红黑树的特点以及常见的二叉平衡树

答案：

红黑树特点：

节点是红色或黑色。
根节点是黑色。
每个叶节点（NIL 节点，空节点）是黑色的。
如果一个节点是红色的，则它的两个子节点都是黑色的（从每个叶子到根的所有路径上不能有两个连续的红色节点）。
从任一节点到其每个叶子的所有路径都包含相同数目的黑色节点。
红黑树性能比较高，插入删除时间复杂度保持在 O (log n)。和 AVL 树相比，它的平衡要求不是那么严格，它只要求到叶节点的最长路径不超过最短路径的两倍。相比之下，AVL 树要求左右子树相差高度不超过一，简单的插入或者删除都会导致树的不平衡，需要旋转操作。
常见二叉平衡树：除了红黑树，常见的二叉平衡树还有 AVL 树、Splay 树等。

8.C++ 空类的 sizeof 大小

答案：C++ 空类的大小为 1。这是因为 C++ 要求即使是空类，对象也要有存储空间，以便在内存中能够区分不同的对象实例。如果空类含有虚函数，那么其大小为指针的大小，在 32 位系统中指针大小是 4 字节，在 64 位系统中指针大小是 8 字节，这是因为对象需要一个虚函数指针来指向虚函数表。

9.快速排序的时间复杂度

答案：快速排序平均时间复杂度为 O (n log n)，在最坏情况下（如数组已经有序，每次选择的基准元素都是最小或最大元素），时间复杂度为 O (n^2)。

10.n log n 是排序最好的时间复杂度吗？

答案：不是，还有 O (n) 的算法，比如基数排序。但基数排序有其适用场景和局限性，它对数据的格式有一定要求，并且在处理负数等情况时相对复杂。

11.简述基数排序的原理以及应用

答案：

原理：基数排序根据一个数的高低位进行排序。它从最低位开始，依次对每一位进行排序，每一轮排序都将数据分配到不同的桶中，然后再按顺序收集起来，直到最高位排序完成。例如，对于十进制数，先按个位进行排序，再按十位、百位等依次排序。
应用：基数排序常用于对整数类型数据进行排序，特别是在数据量较大且数据范围相对较小的情况下，能发挥出其高效的优势。例如，在一些数据库系统中，对整数类型的索引进行排序时可能会用到基数排序。不过，它对负数的处理不太好，需要额外的处理逻辑。
12.解释线程安全和可重入函数

答案：

线程安全：当多个线程访问一个对象时，如果不用考虑这些线程在运行时环境下的调度和交替执行，也不需要进行额外的同步，或者在调用方进行任何其他的协调操作，调用这个对象的行为都可以获得正确的结果，那么这个对象是线程安全的。例如，一个函数中只操作局部变量，不涉及共享资源，那么它通常是线程安全的。
可重入函数：一个可重入函数被称为可重入的，表明该函数被重入之后，不会产生任何不良后果。一个函数被重入，表示这个函数没有执行完成，由于内部原因（如函数内部调用了自身，即递归调用）或外部原因（如在函数执行过程中被中断，然后在中断处理程序中又被调用）再次进入该函数执行。可重入函数不能依赖于静态或全局变量等在多次调用之间保持状态的资源，除非对这些资源进行了适当的同步保护。例如，标准 C 库中的 strcpy 函数就是可重入函数，而一些使用了静态缓冲区的函数（如 gets 函数）就不是可重入的。
13.define 和 inline 区别

答案：

处理阶段：define 是在预处理阶段进行文本替换，它只是简单地将代码中的宏名替换为定义的文本内容；inline 函数是在编译阶段进行处理，编译器会尝试将函数体代码直接嵌入到调用处，以减少函数调用的开销。
类型检查：define 没有类型检查，它只是机械地替换文本，容易出现一些由于类型不匹配等原因导致的错误；inline 函数具有类型检查功能，编译器会对函数参数和返回值进行类型检查，提高了代码的安全性。
代码膨胀：如果宏定义的内容比较复杂，在多处使用时可能会导致代码膨胀，因为每次替换都会复制一份代码；inline 函数虽然也会在调用处嵌入代码，但编译器会根据实际情况进行优化，不一定会导致明显的代码膨胀，并且对于短小的函数，使用 inline 可以提高效率。
作用域：define 定义的宏没有作用域限制（除非用 #undef 取消定义），在整个预处理过程中都有效；inline 函数具有普通函数的作用域规则，只在其定义所在的作用域内有效。
14.定义常量指针和指针常量

答案：

常量指针：指向常量的指针，即指针所指向的对象的值不能通过该指针修改，但指针本身可以指向其他对象。定义形式为：const int *p; 或 int const *p;。例如：
1
2
3
4
5
int a = 10;
int b = 20;
const int *p = &a;
// *p = 20;  // 错误，不能通过常量指针修改所指向对象的值
p = &b;     // 正确，可以改变指针的指向
指针常量：指针本身是常量，一旦初始化后，指针就不能再指向其他对象，但所指向对象的值可以修改。定义形式为：int * const p;。例如：
1
2
3
4
5
int a = 10;
int b = 20;
int * const p = &a;
*p = 20;     // 正确，可以修改所指向对象的值
// p = &b;  // 错误，指针常量不能改变指向
15.解释 explicit 关键字的作用

答案：explicit 关键字用于修饰类的构造函数，防止在进行隐式类型转换时调用该构造函数。当构造函数被声明为 explicit 时，只有在显式调用构造函数时才会进行类型转换，避免了一些意外的隐式类型转换带来的问题。例如：

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
class MyClass {
public:
    explicit MyClass(int value) : data(value) {}
    int data;
};

void func(MyClass obj) {
    // 一些操作
}

int main() {
    MyClass obj1(10); // 显式调用构造函数，正确
    // MyClass obj2 = 20; // 错误，因为构造函数是explicit，不能进行隐式类型转换
    func(MyClass(20)); // 显式调用构造函数进行类型转换，正确
    return 0;
}
16.谈谈对智能指针的理解

答案：智能指针是 C++ 中用于自动管理动态内存的工具，它能够有效避免内存泄漏和悬空指针等问题。C++ 标准库提供了几种智能指针，如std::unique_ptr、std::shared_ptr和std::weak_ptr。

std::unique_ptr：拥有对对象的唯一所有权，当std::unique_ptr离开其作用域时，它所指向的对象会被自动释放。它不能被复制，但可以转移所有权。例如：
1
2
std::unique_ptr`<int>` ptr1(new int(10));
std::unique_ptr`<int>` ptr2 = std::move(ptr1); // 转移所有权，ptr1变为空指针
std::shared_ptr：允许多个std::shared_ptr对象共享同一个对象的所有权。通过引用计数来管理对象的生命周期，当引用计数为 0 时，对象会被自动释放。例如：
1
2
3
4
5
6
std::shared_ptr`<int>` ptr1(new int(10));
std::shared_ptr`<int>` ptr2 = ptr1; // ptr1和ptr2共享同一个对象，引用计数增加
{
    std::shared_ptr`<int>` ptr3 = ptr1; // 引用计数进一步增加
} // ptr3离开作用域，引用计数减1
// 当ptr1和ptr2都离开作用域时，引用计数变为0，对象被释放
std::weak_ptr：它是一种弱引用，不增加对象的引用计数，主要用于解决std::shared_ptr的循环引用问题。std::weak_ptr可以通过lock方法尝试获取对应的std::shared_ptr对象，如果对象已经被释放，lock方法将返回一个空的std::shared_ptr。例如：
1
2
3
std::shared_ptr`<int>` ptr1(new int(10));
std::weak_ptr`<int>` weakPtr = ptr1;
std::shared_ptr`<int>` ptr2 = weakPtr.lock(); // 如果ptr1未被释放，ptr2将指向相同对象
17.说说四种类型转换（static_cast、dynamic_cast、const_cast、reinterpret_cast）的作用和使用场景

答案：

static_cast：用于具有明确定义的类型转换，通常用于基本数据类型之间的转换（如int到double）以及有继承关系的类之间的转换（如派生类指针到基类指针的转换，但不能用于运行时类型检查）。例如：
1
2
3
4
5
6
7
int num = 10;
double d = static_cast`<double>`(num); // 基本数据类型转换

class Base {};
class Derived : public Base {};
Derived* derivedPtr = new Derived();
Base* basePtr = static_cast<Base*>(derivedPtr); // 派生类指针到基类指针的转换
dynamic_cast：主要用于有继承关系的类之间的安全向下转型（从基类指针或引用到派生类指针或引用），它会在运行时进行类型检查。如果转换失败，对于指针类型会返回nullptr，对于引用类型会抛出std::bad_cast异常。例如：
1
2
3
4
5
6
7
Base* basePtr = new Derived();
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // 安全向下转型
if (derivedPtr) {
    // 转换成功
} else {
    // 转换失败
}
const_cast：用于去除对象的常量性或添加常量性。例如，将const对象转换为非const对象，以便进行修改（前提是对象本身不是真正的常量）。例如：
1
2
const int num = 10;
int* nonConstPtr = const_cast<int*>(&num); // 去除常量性，但这样做可能导致未定义行为
reinterpret_cast：用于进行底层的位模式重新解释，它可以将任何指针类型转换为其他指针类型，或者将整数类型转换为指针类型等，这种转换是非常危险的，因为它绕过了正常的类型检查，可能导致未定义行为。例如：
1
2
3
int num = 10;
int* ptr = #
char* charPtr = reinterpret_cast<char*>(ptr); // 位模式重新解释
18.谈谈对模板的理解，函数模板与类模板有什么区别

答案：

模板的理解：模板是 C++ 提供的一种泛型编程机制，它允许我们编写与类型无关的代码。通过模板，可以定义函数模板和类模板，使代码能够适应多种数据类型，提高代码的复用性。例如，我们可以编写一个通用的排序函数模板，它可以对不同类型的数组进行排序。

函数模板与类模板的区别：

定义形式：函数模板的定义以template`<typename T>`或template`<class T>`开头，后面跟着函数声明和定义；类模板的定义同样以template`<typename T>`或template`<class T>`开头，但后面跟着类的声明和定义。例如：
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
// 函数模板
template`<typename T>`
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// 类模板
template`<typename T>`
class Stack {
private:
    T* data;
    int top;
    int capacity;
public:
    Stack(int cap) : capacity(cap), top(-1) {
        data = new T[capacity];
    }
    // 其他成员函数
};
实例化方式：函数模板在调用时会根据传入的参数类型自动实例化；类模板需要显式指定模板参数来实例化。例如：
1
2
3
4
int a = 10, b = 20;
swap(a, b); // 自动实例化函数模板swap`<int>`

Stack`<int>` intStack(10); // 显式实例化类模板Stack`<int>`
作用范围：函数模板主要用于创建通用的函数；类模板用于创建通用的类，该类的成员函数和成员变量的类型都可以是模板参数类型。
19.异常机制是怎么回事？在 C++ 中如何使用异常处理？

答案：异常机制是 C++ 提供的一种处理错误和异常情况的方式。当程序执行过程中遇到无法正常处理的错误时，可以抛出异常，然后由调用栈中合适的异常处理代码来捕获并处理这个异常。这样可以将错误处理代码和正常业务逻辑代码分离，提高代码的可读性和可维护性。

20.C++中new和malloc的区别？

答案：

所属层面：new是C++中的运算符，属于面向对象层面的内存分配方式；malloc是C标准库中的函数，属于过程式编程层面的内存分配函数。

类型检查：new在分配内存时会自动匹配对象的类型，无需显式指定内存大小（编译器会根据对象类型计算），且会自动调用对象的构造函数初始化对象；malloc需要显式指定内存分配的字节数，不进行类型检查，也不会调用构造函数，分配的内存是“原始”的、未初始化的。

返回值类型：new返回的是对应对象类型的指针，无需强制类型转换；malloc返回的是 `void*`类型指针，使用时需要强制转换为目标类型指针。

内存不足处理：当内存分配失败时，new会抛出std::bad_alloc异常（在默认情况下）；malloc会返回NULL指针，需要通过判断返回值是否为NULL来处理分配失败的情况。

释放方式：使用new分配的内存需要使用delete运算符释放（对于数组则使用delete[]），delete会自动调用对象的析构函数；使用malloc分配的内存需要使用free函数释放，free不调用析构函数，仅释放内存空间。

示例：

1
2
3
4
5
6
7
8
9
10
11
12
13
14
// new的使用
 int* p1 = new int(10); // 分配int类型内存并初始化为10，调用int的构造函数（内置类型构造函数无实际操作）
 delete p1; // 释放内存，调用int的析构函数

 class MyClass { /* ... */ };
 MyClass* p2 = new MyClass(); // 分配MyClass对象内存，调用MyClass构造函数
 delete p2; // 释放内存，调用MyClass析构函数

 // malloc的使用
 int* p3 = (int*)malloc(sizeof(int)); // 显式指定大小，强制类型转换
 if (p3 != NULL) {
     *p3 = 10; // 手动初始化
     free(p3); // 释放内存
 }
校招想进大厂的同学不知道学什么？不知道做什么项目？可以参考下面这个视频的讲解

校招互联网大厂C++学习路线和项目推荐

Linux 系统编程

1.Linux 下进程和线程的区别

答案：

资源分配：进程是操作系统进行资源分配的基本单位，每个进程拥有独立的地址空间（包括代码段、数据段、堆栈段）、文件描述符表、进程控制块（PCB）等资源；线程是操作系统进行调度和执行的基本单位，线程属于进程，共享进程的地址空间、文件描述符表等大部分资源，仅拥有独立的线程控制块（TCB）、程序计数器（PC）、寄存器集合和栈空间。
上下文切换开销：进程上下文切换时，需要保存和恢复整个进程的地址空间、寄存器状态等大量信息，开销较大；线程上下文切换时，由于共享进程资源，仅需保存和恢复线程自身的寄存器、PC 和栈等少量信息，开销远小于进程上下文切换。
通信方式：进程间通信（IPC）方式复杂，需要借助操作系统提供的机制，如管道（pipe）、命名管道（FIFO）、消息队列、共享内存、信号量、套接字（socket）等；线程间通信相对简单，可直接通过共享进程内的全局变量、静态变量等实现（但需注意同步与互斥，避免数据竞争），也可使用线程特有机制如 pthread 库中的条件变量、信号量等。
独立性与稳定性：进程间相互独立，一个进程的崩溃通常不会影响其他进程（除非涉及共享资源且未正确处理）；线程属于同一进程，一个线程的崩溃可能导致整个进程崩溃（如线程访问非法内存地址，会触发进程的段错误信号）。
创建与销毁开销：创建进程需要分配独立的资源，销毁进程需要回收所有资源，开销较大；创建线程仅需分配少量独立资源，销毁时回收资源也较少，开销远低于进程。
2.Linux 下创建进程的系统调用有哪些？简述 fork 函数的原理和特点

答案：

创建进程的系统调用：主要有fork()、vfork()、clone()（clone()更灵活，可用于创建进程或线程， pthread 库创建线程底层依赖clone()）。

fork 函数原理：fork()函数用于创建一个新进程（子进程），新进程是原进程（父进程）的副本。调用fork()后，操作系统会为子进程分配新的 PCB，并复制父进程的地址空间（早期 Linux 使用 “写时复制”（Copy-On-Write，COW）机制优化：初始时子进程共享父进程的地址空间，仅当父进程或子进程对内存进行写操作时，才会复制对应的内存页，从而减少内存开销和创建时间）。

fork 函数特点：

返回值：fork()函数在父进程中返回子进程的进程 ID（PID），在子进程中返回 0，若创建失败则返回 - 1（并设置errno表示错误原因）。这是区分父进程和子进程的关键。
执行顺序：fork()后，父进程和子进程的执行顺序由操作系统的调度算法决定，无法预知哪个进程先执行。
资源共享与复制：子进程复制父进程的文件描述符表、信号处理方式（除了SIGCHLD信号的默认处理方式可能改变）、当前工作目录等，但进程 ID、父进程 ID（PPID）、内存使用计数器等是独立的。
写时复制优化：如原理中所述，避免了创建子进程时立即复制大量内存的开销，提高了fork()的效率。
示例：
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // 子进程逻辑
        printf("子进程：PID=%d，PPID=%d\n", getpid(), getppid());
    } else {
        // 父进程逻辑
        printf("父进程：PID=%d，子进程PID=%d\n", getpid(), pid);
        wait(NULL); // 等待子进程结束，避免子进程成为僵尸进程
    }
    return 0;
}
3.Linux 下僵尸进程和孤儿进程是什么？如何避免僵尸进程？

答案：

僵尸进程（Zombie Process）：当子进程执行结束后，其 PCB 信息（如进程 ID、退出状态、CPU 使用时间等）仍会保留在系统中，等待父进程通过wait()或waitpid()等函数获取其退出状态并回收资源。若父进程未及时回收子进程资源，子进程就会成为僵尸进程。僵尸进程会占用系统的进程 ID 等资源，若大量存在，会导致系统无法创建新进程。

孤儿进程（Orphan Process）：当父进程在子进程之前退出，子进程就会成为孤儿进程。此时，孤儿进程会被操作系统的 init 进程（或 systemd 进程，在现代 Linux 系统中）收养，init 进程会负责等待孤儿进程结束，并回收其资源，因此孤儿进程通常不会对系统造成负面影响。

避免僵尸进程的方法：

父进程主动回收：父进程在创建子进程后，通过wait()函数（阻塞等待任意一个子进程结束）或waitpid()函数（可指定等待的子进程，支持非阻塞模式）主动获取子进程的退出状态，回收子进程资源。例如：
1
2
3
4
5
6
7
8
9
10
11
pid_t pid = fork();
if (pid == 0) {
    // 子进程逻辑
    exit(0);
} else if (pid > 0) {
    int status;
    waitpid(pid, &status, 0); // 阻塞等待指定子进程结束
    if (WIFEXITED(status)) {
        printf("子进程正常退出，退出码：%d\n", WEXITSTATUS(status));
    }
}
注册 SIGCHLD 信号处理函数：当子进程结束时，操作系统会向父进程发送SIGCHLD信号。父进程可以注册SIGCHLD信号的处理函数，在处理函数中调用waitpid()回收子进程资源（需注意waitpid()使用非阻塞模式，避免信号中断导致的问题）。例如：
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
void sigchld_handler(int signo) {
    pid_t pid;
    int status;
    // WNOHANG表示非阻塞，若没有子进程退出则立即返回
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        if (WIFEXITED(status)) {
            printf("子进程%d正常退出，退出码：%d\n", pid, WEXITSTATUS(status));
        }
    }
}

int main() {
    // 注册SIGCHLD信号处理函数
    signal(SIGCHLD, sigchld_handler);
    pid_t pid = fork();
    // ... 后续逻辑
}
父进程先于子进程退出：若父进程在子进程之前退出，子进程会成为孤儿进程并被 init 进程收养，init 进程会自动回收孤儿进程的资源，从而避免僵尸进程产生（但此方法需根据业务场景判断是否适用，并非主动控制的方式）。
4.Linux 下线程同步的方式有哪些？简述互斥锁（pthread_mutex_t）的使用流程

答案：

Linux 线程同步方式：主要包括互斥锁（pthread_mutex_t）、条件变量（pthread_cond_t）、信号量（sem_t，可用于线程同步或进程同步）、读写锁（pthread_rwlock_t）、屏障（pthread_barrier_t）等。

互斥锁（pthread_mutex_t）使用流程：互斥锁用于保证多个线程对共享资源的 “互斥访问”，即同一时间仅允许一个线程持有互斥锁并访问共享资源，其他试图获取互斥锁的线程会被阻塞，直到互斥锁被释放。其核心使用流程如下：

初始化互斥锁：使用pthread_mutex_init()函数初始化互斥锁，可指定互斥锁的属性（如是否为递归锁、进程共享属性等，默认属性通常满足大部分场景）。
获取互斥锁（加锁）：使用pthread_mutex_lock()函数获取互斥锁。若互斥锁当前未被持有，则当前线程成功获取锁并继续执行；若互斥锁已被其他线程持有，则当前线程会被阻塞，直到锁被释放。此外，pthread_mutex_trylock()函数会尝试获取锁，若获取失败则立即返回错误码，不会阻塞线程。
访问共享资源：在成功获取互斥锁后，线程可以安全地访问共享资源（如全局变量、静态变量等）。
释放互斥锁（解锁）：使用pthread_mutex_unlock()函数释放互斥锁，释放后其他被阻塞的线程可以竞争获取该锁。
销毁互斥锁：当互斥锁不再使用时，使用pthread_mutex_destroy()函数销毁互斥锁，释放其占用的资源。
示例：

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex; // 定义互斥锁
int shared_data = 0; // 共享资源

void* thread_func(void* arg) {
    for (int i = 0; i < 10000; i++) {
        // 1. 获取互斥锁
        pthread_mutex_lock(&mutex);
        // 2. 访问共享资源
        shared_data++;
        // 3. 释放互斥锁
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    // 初始化互斥锁（默认属性）
    pthread_mutex_init(&mutex, NULL);

    // 创建两个线程
    pthread_create(&tid1, NULL, thread_func, NULL);
    pthread_create(&tid2, NULL, thread_func, NULL);

    // 等待线程结束
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // 销毁互斥锁
    pthread_mutex_destroy(&mutex);

    printf("共享资源最终值：%d（预期为20000）\n", shared_data);
    return 0;
}
注意事项：互斥锁必须成对使用（加锁后必须解锁），避免出现死锁（如线程 A 持有锁等待线程 B 的锁，线程 B 持有锁等待线程 A 的锁）；不要在持有互斥锁的情况下调用可能阻塞的函数（如sleep()、read()等，除非业务逻辑允许），以免导致其他线程长时间等待；递归锁（PTHREAD_MUTEX_RECURSIVE属性）允许同一线程多次获取锁，但需对应次数的解锁，普通互斥锁不允许同一线程重复加锁。

Linux 下文件描述符是什么？简述常见的文件描述符及其作用

答案：

文件描述符（File Descriptor，FD）：在 Linux 系统中，文件描述符是一个非负整数，用于标识进程打开的文件（包括普通文件、目录、管道、设备文件、套接字等）。Linux 系统为每个进程维护一个 “文件描述符表”，记录该进程打开的文件描述符与对应的内核文件对象（struct file）的映射关系。当进程打开一个文件时，内核会创建一个struct file对象，为进程分配一个未使用的最小文件描述符，并将两者关联后返回给进程；进程后续对文件的读写、关闭等操作，均通过该文件描述符完成。

常见文件描述符及其作用：Linux 系统在进程启动时，会默认打开三个标准文件描述符，其默认值固定：

0（STDIN_FILENO）：标准输入文件描述符，对应进程的输入源（默认是键盘）。进程通过read(0, ...)函数从标准输入读取数据（如scanf()、getchar()等函数底层依赖该描述符）。
1（STDOUT_FILENO）：标准输出文件描述符，对应进程的输出目标（默认是终端屏幕）。进程通过write(1, ...)函数向标准输出写入数据（如printf()、puts()等函数底层依赖该描述符）。
2（STDERR_FILENO）：标准错误文件描述符，对应进程的错误输出目标（默认是终端屏幕）。进程通过write(2, ...)函数向标准错误输出错误信息（如perror()函数底层依赖该描述符），标准错误输出通常不经过缓冲区，确保错误信息能及时显示。
文件描述符的特点：

文件描述符是进程私有的，不同进程的相同文件描述符可能对应不同的文件（除非通过进程间通信传递文件描述符）。
当进程关闭文件描述符（调用close()函数）时，内核会解除该描述符与struct file对象的关联；若没有其他进程使用该struct file对象，内核会销毁该对象并释放相关资源。
进程可打开的文件描述符数量存在限制（分为系统级限制和进程级限制），可通过ulimit -n命令查看进程级默认限制，通过修改/etc/security/limits.conf配置文件调整限制。
示例（文件描述符操作）：

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    // 打开文件，获取文件描述符（O_RDONLY表示只读模式）
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("open file failed");
        return 1;
    }
    printf("打开文件的描述符：%d\n", fd); // 通常为3（前3个为标准描述符）

    char buf[1024];
    ssize_t n = read(fd, buf, sizeof(buf)-1); // 读取文件内容
    if (n > 0) {
        buf[n] = '\0';
        printf("读取到的内容：%s\n", buf);
    }

    close(fd); // 关闭文件描述符
    return 0;
}
6.Linux 下进程间通信（IPC）有哪些方式？简述共享内存（Shared Memory）的实现原理和使用流程

答案：

常见 IPC 方式：Linux 下进程间通信方式主要包括管道（Pipe）、命名管道（FIFO）、消息队列（Message Queue）、共享内存（Shared Memory）、信号量（Semaphore）、信号（Signal）、套接字（Socket，支持跨主机通信）等。

共享内存（Shared Memory）原理：共享内存是所有 IPC 方式中效率最高的一种，其核心原理是：内核在物理内存中开辟一块连续的内存区域，让多个进程通过 “内存映射” 的方式，将这块物理内存映射到各自的虚拟地址空间中。此后，进程对自身虚拟地址空间中该映射区域的读写操作，会直接反映到物理内存中，其他共享该内存的进程也能立即看到修改结果，无需内核参与数据拷贝（这是其效率高的关键）。

共享内存使用流程（基于 System V 共享内存 API）：

创建 / 获取共享内存：使用shmget()函数创建新的共享内存段，或获取已存在的共享内存段。该函数需要指定 “键值”（用于标识共享内存段，多个进程通过相同键值访问同一共享内存）、内存大小、权限标志等参数，成功时返回共享内存标识符（shmid）。
将共享内存映射到进程虚拟地址空间：使用shmat()函数将共享内存段映射到当前进程的虚拟地址空间，返回映射后的虚拟地址指针。后续进程通过该指针操作共享内存。
进程间通过共享内存通信：多个进程通过各自映射得到的虚拟地址指针，对共享内存进行读写操作（需配合信号量等同步机制，避免数据竞争）。
解除共享内存映射：当进程不再使用共享内存时，使用shmdt()函数解除共享内存与进程虚拟地址空间的映射（仅断开映射关系，不删除共享内存段）。
删除共享内存段：使用shmctl()函数（指定IPC_RMID命令）删除内核中的共享内存段，释放物理内存资源（通常由最后一个使用共享内存的进程执行）。
示例（共享内存通信）：

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
// 写进程：向共享内存写入数据
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

#define SHM_KEY 0x123456 // 共享内存键值
#define SHM_SIZE 1024    // 共享内存大小

int main() {
    // 1. 创建/获取共享内存
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget failed");
        return 1;
    }

    // 2. 映射共享内存到虚拟地址空间
    char* shm_ptr = (char*)shmat(shmid, NULL, 0);
    if (shm_ptr == (char*)-1) {
        perror("shmat failed");
        return 1;
    }

    // 3. 向共享内存写入数据
    const char* msg = "Hello from shared memory!";
    strncpy(shm_ptr, msg, SHM_SIZE-1);
    printf("已向共享内存写入：%s\n", msg);

    // 等待读进程读取（实际场景需用同步机制）
    getchar();

    // 4. 解除映射
    shmdt(shm_ptr);

    // 5. 删除共享内存（此处仅示例，实际由最后一个进程执行）
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}

// 读进程：从共享内存读取数据
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define SHM_KEY 0x123456 // 与写进程相同的键值
#define SHM_SIZE 1024

int main() {
    // 1. 获取共享内存（无需创建，使用已有段）
    int shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shmid == -1) {
        perror("shmget failed");
        return 1;
    }

    // 2. 映射共享内存
    char* shm_ptr = (char*)shmat(shmid, NULL, 0);
    if (shm_ptr == (char*)-1) {
        perror("shmat failed");
        return 1;
    }

    // 3. 从共享内存读取数据
    printf("从共享内存读取到：%s\n", shm_ptr);

    // 4. 解除映射
    shmdt(shm_ptr);
    return 0;
}
注意事项：共享内存本身不提供同步机制，多个进程并发读写时可能出现数据错乱，需配合信号量、互斥锁等同步手段；共享内存中的数据不会随进程退出而自动清除，需显式调用shmctl(IPC_RMID)删除，否则会残留在内核中（可通过ipcs -m命令查看残留的共享内存段）。

更多大厂面试真题：C++技术面试：从200+道真实面经中发现的求职真相

计算机网络

1.TCP 和 UDP 的区别

答案：TCP（传输控制协议）和 UDP（用户数据报协议）是 TCP/IP 协议族中传输层的核心协议，二者区别主要体现在可靠性、连接性、传输效率等方面：

2.TCP 三次握手和四次挥手的过程

答案：

TCP 三次握手（建立连接）：目的是确保客户端和服务器端都能正常发送和接收数据，避免 “失效的连接请求” 导致资源浪费。过程如下：

第一次握手（客户端→服务器）：客户端处于SYN_SENT状态，向服务器发送SYN（同步）报文段，报文包含客户端的初始序列号seq = x，请求建立连接。
第二次握手（服务器→客户端）：服务器收到SYN报文后，处于SYN_RCVD状态，向客户端发送SYN+ACK（同步 + 确认）报文段。报文包含服务器的初始序列号seq = y，以及对客户端SYN的确认号ack = x + 1。
第三次握手（客户端→服务器）：客户端收到SYN+ACK报文后，处于ESTABLISHED（连接建立）状态，向服务器发送ACK（确认）报文段。报文包含确认号ack = y + 1，以及客户端的序列号seq = x + 1。服务器收到ACK后，也进入ESTABLISHED状态，连接正式建立，双方可开始传输数据。
为什么需要三次握手？：若采用两次握手，服务器收到客户端的SYN后立即建立连接并发送SYN+ACK，但如果客户端的SYN报文是 “失效的旧报文”（如网络延迟导致的滞留报文），服务器会误认为是新连接请求，建立无效连接并占用资源；三次握手中，客户端通过第三次ACK确认服务器已收到自己的响应，可避免此类问题。

TCP 四次挥手（关闭连接）：TCP 是全双工通信，关闭连接需双方分别关闭各自的发送通道，因此需要四次交互。过程如下（假设客户端先发起关闭请求）：

第一次挥手（客户端→服务器）：客户端无数据发送，处于FIN_WAIT_1状态，向服务器发送FIN（结束）报文段，报文包含客户端序列号seq = u，表示客户端不再发送数据。
第二次挥手（服务器→客户端）：服务器收到FIN后，处于CLOSE_WAIT状态，向客户端发送ACK（确认）报文段，确认号ack = u + 1，序列号seq = v。此时客户端到服务器的发送通道关闭，客户端进入FIN_WAIT_2状态，等待服务器发送剩余数据。
第三次挥手（服务器→客户端）：服务器发送完所有剩余数据后，无数据再发送，处于LAST_ACK状态，向客户端发送FIN+ACK报文段，序列号seq = w，确认号ack = u + 1，表示服务器不再发送数据。
第四次挥手（客户端→服务器）：客户端收到FIN+ACK后，处于TIME_WAIT状态，向服务器发送ACK报文段，确认号ack = w + 1，序列号seq = u + 1。服务器收到ACK后，处于CLOSED状态，关闭连接；客户端等待2MSL（报文段最大生存时间，通常为 2 分钟）后，确认服务器已收到ACK，也进入CLOSED状态，连接彻底关闭。
为什么需要四次挥手？：全双工通信中，双方的发送通道需分别关闭。服务器收到客户端的FIN后，可能仍有数据未发送，需先发送ACK确认 “收到关闭请求”，待数据发送完成后再发送FIN关闭自己的发送通道，因此需分两次挥手（第二次和第三次），最终形成四次交互。

为什么客户端需要 TIME_WAIT 状态？：① 确保服务器能收到客户端的最后一个ACK（若ACK丢失，服务器会重发FIN，客户端在TIME_WAIT内可重新发送ACK）；② 避免客户端关闭后，旧的滞留报文段干扰新连接（2MSL内旧报文段会从网络中消失）。

3.TCP 的滑动窗口机制是什么？作用是什么？

答案：

滑动窗口机制定义：滑动窗口是 TCP 实现流量控制和可靠传输的核心机制，它允许发送方在未收到接收方确认的情况下，连续发送多个数据报文段，从而提高传输效率。窗口本质上是发送方和接收方之间约定的 “可连续发送的最大数据量”，用字节数表示。

核心原理：

接收方窗口（rwnd）：接收方根据自身缓冲区剩余空间大小，在确认报文（ACK）中告知发送方 “当前可接收的最大字节数”（即rwnd）。若接收方缓冲区已满，rwnd = 0，发送方会停止发送（或发送小的探测报文），直到接收方缓冲区有空闲空间并更新rwnd。
发送方窗口：发送方的窗口大小由 “接收方窗口（rwnd）” 和 “拥塞窗口（cwnd，由拥塞控制算法计算，反映网络拥塞程度）” 中的较小值决定（即swnd = min(rwnd, cwnd)）。发送方可连续发送不超过swnd字节的数据，无需等待每个报文的确认。
窗口滑动：发送方每收到一个接收方的确认报文（ACK），会将窗口的 “起始位置” 向后滑动，滑动的字节数等于已确认的数据长度，从而允许发送新的数据；接收方则在缓冲区数据被应用层读取后，更新rwnd并通过ACK告知发送方，触发发送方窗口进一步滑动。
作用：

实现流量控制：通过rwnd限制发送方的发送速率，避免接收方缓冲区溢出（接收方处理速度跟不上发送方发送速度时，rwnd减小，发送方减缓发送）。
提高传输效率：允许发送方批量发送数据，减少确认报文的数量，降低网络交互开销（相比 “停 - 等协议”，滑动窗口大幅提升吞吐量）。
辅助可靠传输：结合确认机制，未被确认的数据会保留在发送窗口中，若超时未收到确认则触发重传，确保数据不丢失。
4.HTTP 和 HTTPS 的区别

答案：HTTP（超文本传输协议）和 HTTPS（超文本传输安全协议）是应用层协议，核心区别在于安全性，具体对比如下：

5.HTTPS 的 SSL/TLS 握手过程

答案：SSL/TLS 握手是 HTTPS 建立安全连接的核心步骤，目的是协商加密算法、交换会话密钥、验证服务器身份，确保后续数据传输的安全性。以 TLS 1.2 为例，握手过程（简化版）如下：

客户端 Hello：客户端向服务器发送 “客户端 Hello” 报文，包含：

客户端支持的 SSL/TLS 版本（如 TLS 1.2）、加密套件列表（如 RSA+AES-256-GCM）；
客户端生成的随机数（Client Random），用于后续计算会话密钥；
支持的压缩算法等信息。
服务器 Hello：服务器收到 “客户端 Hello” 后，发送 “服务器 Hello” 报文，确认：

双方最终使用的 SSL/TLS 版本、加密套件（从客户端列表中选择）；
服务器生成的随机数（Server Random），与Client Random共同用于生成会话密钥；
服务器证书（包含服务器公钥、证书颁发机构 CA 签名等信息）。
客户端验证服务器证书：客户端收到服务器证书后，通过内置的 CA 根证书验证证书有效性（检查签名是否合法、证书是否过期、域名是否匹配等）：

若证书验证失败，客户端会提示 “安全风险” 并终止连接；
若证书验证成功，客户端从证书中提取服务器公钥。
客户端发送预主密钥（Pre-Master Secret）：客户端生成一个随机的 “预主密钥（PMS）”，使用服务器公钥对其加密后，发送给服务器（仅服务器能通过私钥解密）。

服务器解密获取预主密钥：服务器使用自身私钥解密客户端发送的加密 PMS，得到原始预主密钥。

双方生成会话密钥：客户端和服务器分别使用Client Random、Server Random、PMS 作为输入，通过相同的密钥派生算法（如 PRF）生成 “会话密钥”（包含对称加密密钥、MAC 校验密钥等）。后续数据传输将使用该会话密钥进行对称加密（对称加密效率高于非对称加密）。

客户端发送 Finished 报文：客户端使用会话密钥对 “之前所有握手报文的哈希值” 加密，生成 “Finished” 报文发送给服务器，用于验证握手过程是否被篡改。

服务器发送 Finished 报文：服务器同样使用会话密钥对 “之前所有握手报文的哈希值” 加密，生成 “Finished” 报文发送给客户端。客户端验证通过后，SSL/TLS 握手完成，后续 HTTP 数据将通过会话密钥加密传输。

优化机制：为减少握手开销，TLS 支持 “会话复用”（如会话 ID、会话票据），后续重连时可跳过证书验证和密钥交换步骤，直接使用历史会话密钥或快速协商新密钥。

6.DNS 的作用是什么？DNS 查询过程（从输入网址到获取 IP 地址）

答案：

DNS 作用：DNS（域名系统）是互联网的 “地址簿”，负责将人类易记的域名（如www.qq.com）解析为计算机可识别的 IP 地址（如183.3.226.35），实现域名到 IP 的映射。

DNS 查询过程（以递归查询 + 迭代查询为例）：

本地 DNS 缓存查询：用户在浏览器输入www.qq.com后，操作系统首先检查本地 DNS 缓存（如浏览器缓存、系统缓存），若存在该域名的 IP 映射，直接返回 IP，查询结束；若缓存未命中，进入下一步。
本地 DNS 服务器查询：操作系统将查询请求发送给 “本地 DNS 服务器”（通常由 ISP 提供，如电信、联通的 DNS 服务器）。本地 DNS 服务器先检查自身缓存，若有记录则返回 IP；若无，进入迭代查询阶段。
根 DNS 服务器查询：本地 DNS 服务器向 “根 DNS 服务器”（全球共 13 组）发送查询请求。根 DNS 服务器不直接存储域名的 IP，仅告知本地 DNS 服务器 “.com顶级域对应的顶级 DNS 服务器地址”。
顶级 DNS 服务器查询：本地 DNS 服务器向.com顶级 DNS 服务器发送查询请求。顶级 DNS 服务器同样不存储具体域名 IP，仅告知本地 DNS 服务器 “qq.com二级域对应的权威 DNS 服务器地址”。
权威 DNS 服务器查询：本地 DNS 服务器向qq.com的权威 DNS 服务器（由腾讯管理）发送查询请求。权威 DNS 服务器存储www.qq.com的域名解析记录，直接返回对应的 IP 地址给本地 DNS 服务器。
结果返回与缓存：本地 DNS 服务器将获取到的 IP 地址返回给用户操作系统，并将该域名 - IP 映射存入自身缓存（设置过期时间 TTL），方便后续其他用户查询。操作系统收到 IP 后，也存入本地缓存，最终浏览器使用该 IP 与服务器建立 TCP 连接，发起 HTTP 请求。
查询类型：DNS 查询分为 A 记录（IPv4 地址映射）、AAAA 记录（IPv6 地址映射）、CNAME 记录（域名别名，如www.qq.com指向qq.com.w.kunlunar.com）、MX 记录（邮件服务器地址）等。

数据结构与算法（腾讯高频考点）

1.红黑树与 AVL 树的区别

答案：红黑树和 AVL 树均为自平衡二叉搜索树，通过旋转操作维持树的平衡，确保插入、删除、查找的时间复杂度为 O (log n)，但二者平衡策略和适用场景不同：

2.哈希表的原理是什么？哈希冲突的解决方法

答案：

哈希表原理：哈希表（Hash Table）是一种 “键 - 值（Key-Value）” 映射数据结构，通过 “哈希函数” 将 Key 转换为数组的索引（哈希地址），直接通过索引访问数组中的 Value，实现 O (1) 平均时间复杂度的插入、删除、查找。核心是 “将 Key 空间映射到数组索引空间”，减少查询时的比较次数。

哈希函数设计原则：

确定性：同一 Key 必须映射到同一哈希地址；
均匀性：不同 Key 尽可能映射到不同地址，减少冲突；
高效性：哈希函数计算速度快，避免耗时操作。
哈希冲突解决方法（当两个不同 Key 通过哈希函数得到相同哈希地址时，称为哈希冲突）：

1.开放定址法：当发生冲突时，通过某种 “探测策略” 寻找数组中其他空闲位置存储数据，常见探测方式：

线性探测：冲突后依次检查下一个地址（hash(key) + i，i=1,2,...），优点是简单，缺点是容易产生 “聚集效应”（多个冲突数据集中在某一区域）；
二次探测：冲突后检查hash(key) + i²或hash(key) - i²的地址，减少聚集效应；
双重哈希：使用两个不同的哈希函数，若第一个函数冲突，用第二个函数计算探测步长（如hash2(key)），探测地址为hash(key) + i*hash2(key)，冲突率最低，但实现复杂。
2.链地址法（拉链法）：数组的每个元素对应一个链表（或红黑树），当发生冲突时，将冲突的 Key-Value 对插入对应链表的尾部（或树中）。查询时，先通过哈希函数找到链表，再遍历链表比较 Key 找到 Value。

优点：冲突处理简单，不会产生聚集效应，扩容时无需重新计算所有 Key 的哈希地址（仅需迁移部分数据）；
缺点：链表遍历存在开销（若链表过长，可将链表转为红黑树，如 JDK 1.8 的HashMap）。
3.再哈希法：当发生冲突时，使用另一个不同的哈希函数重新计算哈希地址，直到找到空闲位置。优点是冲突率低，缺点是可能出现多次哈希计算，且无法保证一定能找到空闲位置（需处理溢出）。

4.公共溢出区法：将哈希表分为 “基本表” 和 “溢出表”，所有冲突的 Key-Value 对统一存入溢出表。查询时，先查基本表，若未找到再查溢出表。优点是实现简单，缺点是溢出表可能成为性能瓶颈（冲突数据过多时，溢出表查询效率低）。

C++ 中的应用：C++11 引入的unordered_map/unordered_set底层采用 “链地址法” 实现哈希表，哈希函数默认使用std::hash，冲突时通过链表存储，当链表长度超过阈值（通常为 8）时，会自动转为红黑树以提升查询效率。

3.手写快速排序（要求时间复杂度分析、优化思路）

答案：

快速排序核心思想：分治法（Divide and Conquer），选择一个 “基准元素（pivot）”，将数组分为两部分：左部分元素均小于基准，右部分元素均大于基准（分区过程），然后递归对左右两部分执行相同操作，直至数组有序。

C++ 实现代码（以升序排序为例）：

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
#include `<vector>`
#include `<algorithm>` // 用于swap

// 分区函数：选择最右元素为基准，返回基准最终位置
int partition(std::vector`<int>`& arr, int left, int right) {
    int pivot = arr[right]; // 选择最右元素为基准
    int i = left - 1;       // i指向“小于基准区域”的最后一个元素

    // 遍历[left, right-1]，将小于基准的元素交换到左侧
    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    // 将基准元素放到最终位置（i+1），左侧均小于基准，右侧均大于基准
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

// 快速排序递归函数
void quickSort(std::vector`<int>`& arr, int left, int right) {
    if (left < right) { // 递归终止条件：区间长度为1或0
        int pivotIdx = partition(arr, left, right); // 分区，获取基准位置
        quickSort(arr, left, pivotIdx - 1);        // 递归排序左区间
        quickSort(arr, pivotIdx + 1, right);       // 递归排序右区间
    }
}

// 对外接口：简化调用
void quickSort(std::vector`<int>`& arr) {
    if (arr.empty()) return;
    quickSort(arr, 0, arr.size() - 1);
}
时间复杂度分析：

平均时间复杂度：O (n log n)。每次分区将数组分为两部分，递归深度为 O (log n)（理想情况下，每次分区后左右区间长度接近相等），每层分区操作的时间复杂度为 O (n)（遍历数组），总复杂度为 O (n log n)。
最坏时间复杂度：O (n²)。当数组已有序（或逆序），且选择最左 / 最右元素为基准时，每次分区仅将数组分为 “1 个元素” 和 “n-1 个元素” 两部分，递归深度为 O (n)，每层分区操作 O (n)，总复杂度为 O (n²)。
空间复杂度：O (log n) ~ O (n)。递归调用栈的空间开销，理想情况下递归深度 O (log n)，空间复杂度 O (log n)；最坏情况下递归深度 O (n)，空间复杂度 O (n)（可通过迭代实现将空间复杂度优化为 O (1)）。
优化思路：

1.基准元素优化：避免选择最左 / 最右元素，改用 “三数取中”（选择左、中、右三个位置元素的中位数作为基准）或 “随机选择基准”，减少最坏情况发生概率。

1
2
3
4
5
6
7
8
9
10
11
// 三数取中优化分区函数
int partitionOptimized(std::vector`<int>`& arr, int left, int right) {
    // 三数取中：选择left、mid、right的中位数作为基准
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid]) std::swap(arr[left], arr[mid]);
    if (arr[left] > arr[right]) std::swap(arr[left], arr[right]);
    if (arr[mid] > arr[right]) std::swap(arr[mid], arr[right]);
    // 将基准元素（mid）交换到right位置，复用原有分区逻辑
    std::swap(arr[mid], arr[right]);
    return partition(arr, left, right); // 调用原分区函数
}
2.小数组优化：当数组区间长度较小时（如 n ≤ 10），改用插入排序（插入排序在小数组上性能优于快速排序，减少递归开销）。

3.尾递归优化：通过循环替代递归，减少递归调用栈深度（如对较小的区间递归，较大的区间循环处理），避免栈溢出。

4.处理重复元素优化：当数组中存在大量重复元素时，使用 “三路快排”（将数组分为 “小于基准”“等于基准”“大于基准” 三部分），避免重复元素参与递归，提升效率。

4.手写 LRU 缓存（要求 O (1) 时间复杂度的 get 和 put 操作）

答案：

LRU 定义：LRU（最近最少使用）是一种缓存淘汰策略，当缓存容量达到上限时，优先淘汰 “最近最少使用” 的缓存项，为新数据腾出空间。
O (1) 复杂度实现思路：需结合两种数据结构：
哈希表（unordered_map）：实现 Key 到 “缓存节点” 的快速查找（O (1) get），存储 Key 和节点指针（或迭代器）。
双向链表：维护缓存项的 “使用顺序”，头部存储 “最近使用” 的节点，尾部存储 “最少使用” 的节点。支持 O (1) 时间的节点插入（头部）、删除（任意位置）、移动（尾部到头部）。
C++ 实现代码：

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
#include <unordered_map>
#include `<list>`
#include `<utility>` // 用于pair

template <typename K, typename V>
class LRUCache {
private:
    using Node = std::pair<K, V>; // 双向链表节点类型：存储Key-Value
    std::list`<Node>` cacheList;    // 双向链表：头部=最近使用，尾部=最少使用
    std::unordered_map<K, typename std::list`<Node>`::iterator> cacheMap; // Key到链表迭代器的映射
    int capacity;                 // 缓存最大容量

    // 辅助函数：将节点移动到链表头部（标记为最近使用）
    void moveToHead(typename std::list`<Node>`::iterator it) {
        if (it != cacheList.begin()) {
            Node node = *it;
            cacheList.erase(it);    // 删除原位置节点
            cacheList.push_front(node); // 插入头部
            cacheMap[node.first] = cacheList.begin(); // 更新哈希表映射
        }
    }

public:
    LRUCache(int cap) : capacity(cap) {}

    // 获取Key对应的Value，若不存在返回默认值（此处假设V可默认构造）`</doubaocanvas>`
V get (const K& key) {
auto mapIt = cacheMap.find (key);
if (mapIt == cacheMap.end ()) {
return V (); // 不存在返回默认值（实际场景可抛异常或用 optional）
}
// 找到节点，将其移动到头部（标记为最近使用）
auto listIt = mapIt->second;
moveToHead (listIt);
return listIt->second; // 返回 Value
}
// 插入或更新缓存项，若容量超限则淘汰最少使用项
void put (const K& key, const V& value) {
auto mapIt = cacheMap.find (key);
if (mapIt != cacheMap.end ()) {
// 缓存项已存在：更新 Value 并移动到头部
auto listIt = mapIt->second;
listIt->second = value; // 更新 Value
moveToHead (listIt);
return;
}
// 缓存项不存在：检查容量
if (cacheList.size () >= capacity) {
// 容量超限：删除尾部最少使用项
Node leastUsed = cacheList.back ();
cacheList.pop_back (); // 从链表删除
cacheMap.erase (leastUsed.first); // 从哈希表删除
}
// 插入新缓存项到头部
cacheList.push_front ({key, value});
cacheMap [key] = cacheList.begin (); // 哈希表记录映射
}
// 辅助函数：获取缓存当前大小（可选）
size_t size () const {
return cacheList.size ();
}
};
测试示例

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
#include `<iostream>`
int main () {
LRUCache<int, std::string> cache (2); // 容量为 2 的 LRU 缓存

cache.put (1, "a");
cache.put (2, "b");
std::cout << cache.get (1) << std::endl; // 输出 "a"，1 被标记为最近使用
cache.put (3, "c"); // 容量超限，淘汰最少使用的 2
std::cout << cache.get (2) << std::endl; // 输出空字符串（2 已被淘汰）
cache.put (4, "d"); // 容量超限，淘汰最少使用的 1
std::cout << cache.get (1) << std::endl; // 输出空字符串（1 已被淘汰）
std::cout << cache.get (3) << std::endl; // 输出 "c"
std::cout << cache.get (4) << std::endl; // 输出 "d"
return 0;
}
复杂度分析：get和put操作中，哈希表查找（find/erase/insert）为O(1)，双向链表操作（push_front/pop_back/erase）为O(1)，整体时间复杂度为O(1)，满足需求。

注意事项：实际项目中需处理线程安全（如加互斥锁）、Value的默认构造问题（可改用std::optional`<V>`）、缓存项过期策略（可扩展节点存储过期时间，get时检查）等。

5.如何判断链表是否有环？如何找到环的入口点？（手写代码）

答案:

判断链表有环的方法

1.哈希表法：遍历链表，用哈希表（如unordered_set）存储已访问的节点指针。若遍历到的节点已在哈希表中，说明有环；若遍历到nullptr，说明无环。时间复杂度O(n)，空间复杂度O(n)。

2. 快慢指针法（Floyd算法）：定义两个指针，slow（慢指针）每次走1步，fast（快指针）每次走2步。若链表有环，fast会追上slow（二者指向同一节点）；若fast先到nullptr，说明无环。时间复杂度O(n)，空间复杂度O(1)（推荐）。

找到环的入口点：基于快慢指针法，当slow和fast相遇后，将slow指针重置到链表头，fast指针保持在相遇点，然后两者均每次走1步，最终相遇的节点即为环的入口点。

原理：设链表头到环入口的距离为L，环入口到相遇点的距离为X，环的长度为C。slow走的距离为L + X，fast走的距离为L + X + k*C（k为fast绕环次数）。因fast速度是slow的2倍，故2*(L + X) = L + X + k*C，化简得L = k*C - X。此时slow从表头走L步到入口，fast从相遇点走k*C - X步（即绕环k圈后再退X步），也到达入口，二者相遇。

C++实现代码

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
#include `<iostream>`
#include <unordered_set>

// 链表节点定义
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 方法1：哈希表法判断有环
bool hasCycleHash(ListNode* head) {
    std::unordered_set<ListNode*> visited;
    ListNode* curr = head;
    while (curr != nullptr) {
        if (visited.count(curr)) {
            return true; // 节点已访问，有环
        }
        visited.insert(curr);
        curr = curr->next;
    }
    return false; // 无环
}

// 方法2：快慢指针法判断有环，并返回相遇点（无环返回nullptr）
ListNode* hasCycleSlowFast(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr; // 空链表或单节点，无环
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;       // 慢指针走1步
        fast = fast->next->next; // 快指针走2步
        if (slow == fast) {
            return slow; // 相遇，有环，返回相遇点
        }
    }
    return nullptr; // 无环
}

// 找到环的入口点（无环返回nullptr）
ListNode* findCycleEntry(ListNode* head) {
    ListNode* meetNode = hasCycleSlowFast(head);
    if (meetNode == nullptr) {
        return nullptr; // 无环
    }
    // 重置slow到表头，fast在相遇点，两者同速前进
    ListNode* slow = head;
    ListNode* fast = meetNode;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow; // 相遇点即为入口
}

// 测试示例
int main() {
    // 构建有环链表：1 -> 2 -> 3 -> 4 -> 2（环入口为2）
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // 4指向2，形成环

    std::cout << "哈希表法判断有环：" << (hasCycleHash(head) ? "是" : "否") << std::endl;
    std::cout << "快慢指针法判断有环：" << (hasCycleSlowFast(head) != nullptr ? "是" : "否") << std::endl;
    ListNode* entry = findCycleEntry(head);
    if (entry != nullptr) {
        std::cout << "环的入口点值：" << entry->val << std::endl; // 输出2
    }

    // 释放内存（有环链表需手动处理，避免内存泄漏）
    ListNode* entryNode = findCycleEntry(head);
    ListNode* curr = entryNode;
    while (curr->next != entryNode) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete curr;
    delete head; // head（1）未在环内，单独删除
    return 0;
}
项目工程实践与性能优化（腾讯重点考察）

1.C++ 项目中如何检测和解决内存泄漏？

答案：内存泄漏是 C++ 项目的常见隐患（如裸指针未释放、智能指针循环引用），需结合工具检测与代码规范双重保障：

工具检测方案：

Valgrind（Linux）：通过memcheck模块监控内存分配 / 释放，命令：valgrind --leak-check=full ./program。可定位泄漏内存的大小、分配位置（代码行号），支持检测野指针、数组越界等问题。
AddressSanitizer（ASAN）：编译器内置工具（GCC 4.8+、Clang 3.1+），编译时添加-fsanitize=address -g，运行时自动捕获内存泄漏并输出调用栈，检测效率高于 Valgrind，适合开发阶段实时监控。
Visual Leak Detector（VLD，Windows）：Visual Studio 插件，调试时在输出窗口显示泄漏信息（内存地址、分配文件 / 行号），无需修改代码。
代码层面解决策略：

优先使用智能指针：用std::unique_ptr（独占所有权）、std::shared_ptr（共享所有权）替代裸指针，避免手动delete。注意std::shared_ptr循环引用问题，可通过std::weak_ptr打破（如双向链表节点、父子对象引用）。
自定义内存分配器：重载operator new/operator delete，记录内存分配日志（分配地址、大小、文件 / 行号），程序退出时检查未释放内存。示例：
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
#include `<cstdlib>`
#include `<iostream>`
#include <unordered_map>

// 记录内存分配信息：地址 -> (大小, 文件名, 行号)
std::unordered_map<void*, std::tuple<size_t, const char*, int>> allocLogs;

// 重载operator new，记录分配信息
void* operator new(size_t size, const char* file, int line) {
    void* ptr = std::malloc(size);
    allocLogs[ptr] = {size, file, line};
    return ptr;
}

// 重载operator delete，删除分配记录
void operator delete(void* ptr) noexcept {
    if (ptr != nullptr) {
        allocLogs.erase(ptr);
        std::free(ptr);
    }
}

// 宏定义：自动传入文件名和行号
#define new new(__FILE__, __LINE__)

// 程序退出时检查泄漏
__attribute__((destructor)) void checkLeak() {
    if (!allocLogs.empty()) {
        std::cerr << "内存泄漏：共" << allocLogs.size() << "处" << std::endl;
        for (auto& [ptr, info] : allocLogs) {
            auto [size, file, line] = info;
            std::cerr << "地址：" << ptr << "，大小：" << size
                      << "，位置：" << file << ":" << line << std::endl;
        }
    }
}

// 测试：故意泄漏内存
int main() {
    int* p = new int(10); // 未delete，会被检测到
    return 0;
}
内存池技术：对频繁分配 / 释放的小内存（如网络数据包、链表节点），预先分配大块内存，按需拆分使用，减少new/malloc的系统调用开销，同时避免内存碎片化。
2.Linux 下如何优化程序的 CPU、内存、IO 性能？

答案：性能优化需先通过工具定位瓶颈（避免盲目优化），常用工具包括top/htop（CPU / 内存监控）、perf（性能分析）、iostat（IO 监控），优化方向如下：

CPU 优化：

1.减少计算开销：

替换低效算法（如 O (n²) 排序改为 O (n log n) 的快排 / 归并排序）；
避免冗余计算（循环内不变表达式提到循环外，如for(int i=0; i<strlen(s); i++)改为int len=strlen(s); for(...)）；
编译器优化（编译时加-O2/-O3，开启循环展开、常量传播、函数内联）。
2.利用 CPU 缓存：

数据对齐：用alignas(64)确保结构体按缓存行（通常 64 字节）对齐，减少缓存缺失；
局部性优化：连续访问数组（空间局部性），重复使用数据（时间局部性），避免随机访问链表。
3.多线程优化：

线程数匹配 CPU 核心数（避免过多上下文切换）；
减少同步开销：用无锁数据结构（如std::atomic）、读写锁（pthread_rwlock_t）替代互斥锁；
避免虚假共享：不同线程的数据不要放在同一缓存行（可通过填充字节隔离，如struct Data { int x; char pad[60]; };）。
内存优化：

1.减少内存占用：

数据结构优化：用std::vector替代std::list（减少指针开销），用std::bitset存储布尔值（1 位 / 元素）；
释放无用内存：std::vector调用shrink_to_fit()释放多余容量，避免内存浪费。
2.降低分配开销：

使用内存池：如前所述，减少小内存频繁分配的开销；
避免栈溢出：大数组（如超过 1MB）改用动态内存分配（堆内存），栈内存默认大小有限（通常 8MB）。
IO 优化：

1.磁盘 IO 优化：

批量读写：用fread/fwrite替代fgetc/fputc，减少 IO 次数；
内存映射：用mmap将文件映射到内存，避免用户态与内核态数据拷贝；
顺序 IO：磁盘顺序读写速度远高于随机读写，尽量避免随机写（如日志写入可先缓存，批量刷盘）。
2.网络 IO 优化：

IO 多路复用：用epoll（Linux）替代select/poll，单线程处理 thousands of 连接，减少线程开销；
减少数据包大小：合并小数据包（如 HTTP/2 的帧合并），避免 TCP 粘包 / 拆包；
TCP 优化：开启TCP_NODELAY禁用 Nagle 算法（减少延迟），调整TCP_WINDOW_SIZE提升吞吐量。
3.C++ 项目中如何保证代码质量？

答案：腾讯等大厂对代码质量要求极高，需从规范、工具、流程三方面入手：

编码规范：

遵循统一规范：如 Google C++ Style、腾讯内部编码规范，明确命名规则（变量用小写 + 下划线，类名首字母大写）、代码格式（4 空格缩进，左括号不换行）、注释要求（函数注释包含功能、参数、返回值，复杂逻辑加行注释）。
工具强制规范：用clang-format自动格式化代码（配置文件匹配团队规范），cpplint检查规范违规（如未使用的变量、多余的分号）。
静态代码分析：

用clang-tidy检测潜在问题（空指针、未初始化变量、内存泄漏风险）；
用Coverity/Cppcheck进行深度分析，检测逻辑错误（如数组越界、死循环）。
测试保障：

单元测试：用Google Test（GTest）为核心函数编写测试用例，覆盖率目标不低于 80%；
集成测试：验证模块间交互正确性，如网络模块与存储模块的联调；
性能测试：用Google Benchmark测试核心接口的 QPS、延迟，确保满足性能需求。
代码审查（Code Review）：

提交代码前需通过 Peer Review，重点检查逻辑正确性、性能隐患、规范符合性；
借助工具（如 Gerrit、GitLab MR）实现审查流程自动化，未通过审查的代码无法合并。

作者：某公司一颗钉子
链接：https://www.nowcoder.com/?type=11003_0
来源：牛客网

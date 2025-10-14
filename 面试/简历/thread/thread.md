this_thread是一个类，它有4个功能函数，具体如下：

| 函数        | 使用                                                  | 说明                       |
| ----------- | ----------------------------------------------------- | -------------------------- |
| get_id      | std::this_thread::get_id()                            | 获取线程id                 |
| yield       | std::this_thread::yield()                             | 放弃线程执行，回到就绪状态 |
| sleep_for   | std::this_thread::sleep_for(std::chrono::seconds(1)); | 暂停1秒                    |
| sleep_until | 如下                                                  | 一分钟后执行               |

## mutex

mutex头文件主要声明了与[互斥量](https://zhida.zhihu.com/search?content_id=224493987&content_type=Article&match_order=1&q=%E4%BA%92%E6%96%A5%E9%87%8F&zhida_source=entity)(mutex)相关的类。mutex提供了4种互斥类型，如下表所示。

| 类型                       | 说明                |
| -------------------------- | ------------------- |
| std::mutex                 | 最基本的 Mutex 类。 |
| std::recursive_mutex       | 递归 Mutex 类。     |
| std::time_mutex            | 定时 Mutex 类。     |
| std::recursive_timed_mutex | 定时递归 Mutex 类。 |

### lock与unlockmutex常用操作：

* lock()：资源上锁
* unlock()：解锁资源
* trylock()：查看是否上锁，它有下列3种类情况：

（1）未上锁返回false，并锁住；

（2）其他线程已经上锁，返回true；

（3）同一个线程已经对它上锁，将会产生死锁。

死锁：是指两个或两个以上的进程在执行过程中，由于竞争资源或者由于彼此通信而造成的一种阻塞的现象，若无外力作用，它们都将无法推进下去。此时称系统处于死锁状态或系统产生了死锁，这些永远在互相等待的进程称为死锁进程。

### [lock_guard](https://zhida.zhihu.com/search?content_id=224493987&content_type=Article&match_order=1&q=lock_guard&zhida_source=entity)

创建lock_guard对象时，它将尝试获取提供给它的互斥锁的所有权。当控制流离开lock_guard对象的作用域时，lock_guard析构并释放互斥量。lock_guard的特点：

* 创建即加锁，作用域结束自动析构并解锁，无需手工解锁
* 不能中途解锁，必须等作用域结束才解锁
* 不能复制

### [unique_lock](https://zhida.zhihu.com/search?content_id=224493987&content_type=Article&match_order=1&q=unique_lock&zhida_source=entity)

简单地讲，unique_lock 是 lock_guard 的升级加强版，它具有 lock_guard 的所有功能，同时又具有其他很多方法，使用起来更加灵活方便，能够应对更复杂的锁定需要。unique_lock的特点：

* 创建时可以不锁定（通过指定第二参数为std::defer_lock），而在需要时再锁定
* 可以随时加锁解锁
* 作用域规则同 lock_grard，析构时自动释放锁
* 不可复制，可移动
* 条件变量需要该类型的锁作为参数（此时必须使用unique_lock）

所有 lock_guard 能够做到的事情，都可以使用 unique_lock 做到，反之则不然。那么何时使lock_guard呢？很简单，需要使用锁的时候，首先考虑使用 lock_guard，因为lock_guard是最简单的锁。

## condition_variable

condition_variable头文件有两个variable类，一个是condition_variable，另一个是condition_variable_any。condition_variable必须结合unique_lock使用。condition_variable_any可以使用任何的锁。下面以condition_variable为例进行介绍。

condition_variable条件变量可以阻塞（wait、wait_for、wait_until）调用的线程直到使用（notify_one或notify_all）通知恢复为止。condition_variable是一个类，这个类既有构造函数也有析构函数，使用时需要构造对应的condition_variable对象，调用对象相应的函数来实现上面的功能。

| 类型               | 说明                                         |
| ------------------ | -------------------------------------------- |
| condition_variable | 构建对象                                     |
| 析构               | 删除                                         |
| wait               | Wait until notified                          |
| wait_for           | Wait for timeout or until notified           |
| wait_until         | Wait until notified or time point            |
| notify_one         | 解锁一个线程，如果有多个，则未知哪个线程执行 |
| notify_all         | 解锁所有线程                                 |
| cv_status          | 这是一个类，表示variable 的状态，如下所      |

### wait

当前线程调用 wait() 后将被阻塞(此时当前线程应该获得了锁（mutex），不妨设获得锁 lck)，直到另外某个线程调用 notify_* 唤醒了当前线程。在线程被阻塞时，该函数会自动调用 lck.unlock() 释放锁，使得其他被阻塞在锁竞争上的线程得以继续执行。另外，一旦当前线程获得通知(notified，通常是另外某个线程调用 notify_* 唤醒了当前线程)，wait()函数也是自动调用 lck.lock()，使得lck的状态和 wait 函数被调用时相同。

### wait_for

与std::condition_variable::wait() 类似，不过 wait_for可以指定一个时间段，在当前线程收到通知或者指定的时间 rel_time 超时之前，该线程都会处于阻塞状态。而一旦超时或者收到了其他线程的通知，wait_for返回，剩下的处理步骤和 wait()类似。

```text
template <class Rep, class Period>
  cv_status wait_for (unique_lock<mutex>& lck,
                      const chrono::duration<Rep,Period>& rel_time);
```

另外，wait_for 的重载版本的最后一个参数pred表示 wait_for的预测条件，只有当 pred条件为false时调用 wait()才会阻塞当前线程，并且在收到其他线程的通知后只有当 pred为 true时才会被解除阻塞。


# C++ 定时互斥量与锁超时 (Timed Mutex & Lock Timeout)

## 概述

本示例代码深入探讨了 C++ 并发编程中**定时互斥量 (`std::timed_mutex`)** 和**带超时机制的锁（`std::unique_lock` 的 `try_lock_for` 方法）**的使用。它演示了线程如何在尝试获取锁时设置一个最长等待时间，以及根据这个时间判断是否成功获取锁，而不是无限期地阻塞。

## 核心概念

1. **定时互斥量 (`std::timed_mutex`)**:

   * `std::timed_mutex` 是 `std::mutex` 的一个扩展，它提供了额外的带超时机制的锁定方法：`try_lock_for()` 和 `try_lock_until()`。
   * 这些方法允许线程在尝试获取锁时，指定一个最长的等待时间。如果在指定时间内无法获取锁，线程将放弃等待并继续执行，而不会永久阻塞。
2. **`std::unique_lock`**:

   * `std::unique_lock` 是一个灵活的 RAII (Resource Acquisition Is Initialization) 风格的锁管理类。
   * 它提供比 `std::lock_guard` 更丰富的功能，包括：
     * **延迟锁定 (`std::defer_lock`)**：在构造时创建 `unique_lock` 对象但不立即锁定互斥量。需要手动调用 `lock()` 方法。
     * **超时锁定 (`try_lock_for`, `try_lock_until`)**：与 `std::timed_mutex` 配合使用，尝试在指定时间内获取锁。
     * **所有权转移**：`unique_lock` 是可移动的，可以将其锁的所有权转移给另一个 `unique_lock` 对象。
     * **手动解锁**：可以手动调用 `unlock()` 方法提前释放锁。
3. **`std::this_thread::sleep_for`**:

   * 用于使当前线程暂停执行指定的时长，模拟耗时操作或等待。
4. **`std::jthread` (C++20)**:

   * C++20 引入的线程类型，其主要优点是对象析构时**自动 `join()`**，简化了线程的生命周期管理，避免了悬空线程问题。

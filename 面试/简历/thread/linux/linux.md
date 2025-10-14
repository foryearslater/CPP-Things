## 技术栈

### Linux 系统基础知识

#### **目录结构 :**

* **/bin: 存放所有用户都能使用的基本命令。[**[1](https://www.google.com/url?sa=E&q=https%3A%2F%2Fvertexaisearch.cloud.google.com%2Fgrounding-api-redirect%2FAUZIYQGInjfvTZANfeepZ7sKWAlNWZSELfUdQTM6lIY7n9qCVqvtUCwrdpuzaBEcI974kkcB1fs-tmbGDiBNQTm7dkHAea2HkLUQvm862hBDiQ_IIeJopRX0zBrish_FCzZwvDh9Df5cwl30q01AK7t9kBUOEwp_yfE%3D)]
* **/sbin: 存放只有系统管理员才能使用的系统管理命令。**
* **/boot: 存放启动 Linux 系统所需的核心文件。**
* **/dev: 存放设备文件。**
* **/etc: 存放系统的配置文件。**
* **/home: 普通用户的家目录。**
* **/root: 超级用户 (root) 的家目录。**
* **/lib: 存放系统最基本的动态链接共享库。**
* **/opt: 给主机额外安装软件所摆放的目录。**
* **/tmp: 存放一些临时文件。**
* **/usr: Unix Software Resource, 系统用户的应用程序和文件几乎都在这个目录下。**
* **/var: 存放着在不断扩充着的东西，比如各种日志文件。**
* **文件类型:**
  * **普通文件 (-):** 包括文本文件、二进制文件等。
  * **目录文件 (d):** 存储文件列表。
  * **链接文件 (l):** 软链接（符号链接），类似于 Windows 的快捷方式。
  * **设备文件 (b/c):** 块设备文件和字符设备文件。
  * **套接字文件 (s):** 用于进程间通信。
  * **管道文件 (p):** 用于进程间通信。
* **硬链接与软链接:**
  * **硬链接 (Hard Link):** 与原文件共享同一个 inode，删除原文件不影响硬链接的访问。不能对目录创建硬链接。
  * **软链接 (Symbolic Link):** 存储的是指向原文件的路径，是一个独立的文件，有自己的 inode。删除原文件后，软链接失效。[[3](https://www.google.com/url?sa=E&q=https%3A%2F%2Fvertexaisearch.cloud.google.com%2Fgrounding-api-redirect%2FAUZIYQHZlg3_ZqnljfTqwvVBOuncCMOjVfTh86lf7exT9pK02shDc3CORFoEt2j-ZNgaUxlEzVrNSmns2OnemYr01b1_JglnHrComloumv-GgxoEWc3SL0D4HIsw2oTTYdqnXoDlC7m_dbz-oh1b-UJk05G55sOliyAe9mkv9g%3D%3D)]

#### 常用核心命令

* **文件和目录操作:**
  * **ls: 列出目录内容。常用参数 -l (详细列表), -a (显示隐藏文件), -h (人类可读的格式)。**
  * **cd: 切换目录。cd ~ (回家目录), cd .. (上一级), cd - (上一个工作目录)。[**[3](https://www.google.com/url?sa=E&q=https%3A%2F%2Fvertexaisearch.cloud.google.com%2Fgrounding-api-redirect%2FAUZIYQHZlg3_ZqnljfTqwvVBOuncCMOjVfTh86lf7exT9pK02shDc3CORFoEt2j-ZNgaUxlEzVrNSmns2OnemYr01b1_JglnHrComloumv-GgxoEWc3SL0D4HIsw2oTTYdqnXoDlC7m_dbz-oh1b-UJk05G55sOliyAe9mkv9g%3D%3D)]
  * **pwd: 显示当前工作目录。**
  * **mkdir: 创建目录。-p 可以递归创建。**
  * **rmdir: 删除空目录。**
  * **rm: 删除文件或目录。-r (递归删除), -f (强制删除)。**
  * **cp: 复制文件或目录。-r 复制目录。**
  * **mv: 移动或重命名文件/目录。**
  * **touch: 创建空文件或更新文件时间戳。**
  * **cat: 查看文件内容。**
  * **more/less: 分页查看文件内容。**
  * **head/tail: 查看文件头部/尾部内容。-n 指定行数, tail -f 实时追踪文件更新。**
* **文本处理:**
  * **grep: 文本搜索工具。[**[4](https://www.google.com/url?sa=E&q=https%3A%2F%2Fvertexaisearch.cloud.google.com%2Fgrounding-api-redirect%2FAUZIYQHnDy8MDNTgEbkuXJkNXjZd3JHi2IbB1pgPJf74yKcFywr93FNt7JSx6epGhx_7g42hNhIccm0z8uTa13ggCyeGrPKkcjfkY4r4wKf7UU8oxbx3G0aj_jww7nJhDAZttbHu3_apf-LYvJT_fJ7ipvaA4MM%3D)]
  * **find: 在文件系统中查找文件。[**[4](https://www.google.com/url?sa=E&q=https%3A%2F%2Fvertexaisearch.cloud.google.com%2Fgrounding-api-redirect%2FAUZIYQHnDy8MDNTgEbkuXJkNXjZd3JHi2IbB1pgPJf74yKcFywr93FNt7JSx6epGhx_7g42hNhIccm0z8uTa13ggCyeGrPKkcjfkY4r4wKf7UU8oxbx3G0aj_jww7nJhDAZttbHu3_apf-LYvJT_fJ7ipvaA4MM%3D)]
  * **sed: 流编辑器，用于对文本进行替换、删除等操作。**
  * **awk: 强大的文本分析工具。**
* **系统管理与监控:**
  * **ps: 查看当前进程状态。常用 ps aux 或 ps -ef。**
  * **top/htop: 实时显示系统进程动态。**
  * **kill: 终止进程。[**[4](https://www.google.com/url?sa=E&q=https%3A%2F%2Fvertexaisearch.cloud.google.com%2Fgrounding-api-redirect%2FAUZIYQHnDy8MDNTgEbkuXJkNXjZd3JHi2IbB1pgPJf74yKcFywr93FNt7JSx6epGhx_7g42hNhIccm0z8uTa13ggCyeGrPKkcjfkY4r4wKf7UU8oxbx3G0aj_jww7nJhDAZttbHu3_apf-LYvJT_fJ7ipvaA4MM%3D)]
  * **df: 查看磁盘空间使用情况。-h 人类可读格式。**
  * **du: 查看文件或目录占用的磁盘空间。-sh 估算总大小。**
  * **free: 查看内存使用情况。-h 人类可读格式。**
* **用户与权限:**
  * **useradd/userdel/usermod: 用户增删改。**
  * **passwd: 修改用户密码。**
  * **su/sudo: 切换用户/以其他用户身份执行命令。**
  * **chmod: 修改文件权限。**
  * **chown: 修改文件所有者。**
  * **chgrp: 修改文件所属组。**

#### I/O 重定向与管道

* **标准输入、输出和错误:**
  * **stdin (文件描述符 0): 标准输入。**
  * **stdout (文件描述符 1): 标准输出。**
  * **stderr (文件描述符 2): 标准错误输出。**
* **重定向:**
  * > **: 将标准输出重定向到文件（覆盖）。**
    >
  * > **>: 将标准输出重定向到文件（追加）。**
    >
  * **<: 将文件内容作为命令的标准输入。**
  * **2>: 将标准错误输出重定向到文件。**
  * **&>: 将标准输出和标准错误输出都重定向到文件。**
* **管道 (|):**
  * **将前一个命令的标准输出作为后一个命令的标准输入。例如 ps aux | grep nginx。**

---

### CMake 与 Makefile 项目构建

#### 1. Makefile 基础

* **什么是 Makefile?**

  * **Makefile 定义了项目的编译规则，它告诉 make 命令如何去编译和链接程序。[**[5](https://www.google.com/url?sa=E&q=https%3A%2F%2Fvertexaisearch.cloud.google.com%2Fgrounding-api-redirect%2FAUZIYQFvZPs0J4iQBf-laOwHzZXgXfpjoeV3mgn4biZEa25fdB0Nd09ErfcIdSV12nRHMf_GjeMCLZ2jY6HI8xvUScEs-4Z7s7Zt4oP-gzp2tnbuNdC1gdbOHdNvbnxmvlcLTkv4fQD6)]
* **基本规则:**
  **codeMakefile**

  ```
  target: prerequisites
      command
  ```

  * **target: 目标文件，可以是可执行文件或中间文件。**
  * **prerequisites: 生成 target 所需要依赖的文件。**
  * **command: 生成 target 的命令（必须以 Tab 键开头）。**
* **变量:**

  * **使用 = 或 := 定义变量，通过 $(VAR_NAME) 使用。**
  * **预定义变量:** CC (C编译器), CXX (C++编译器), CFLAGS (C编译选项), CXXFLAGS (C++编译选项)。
  * **自动变量:** $@ (目标文件), $^ (所有依赖文件), $< (第一个依赖文件)。
* **伪目标 (.PHONY):**

  * **用于定义一个不代表实际文件名的目标，比如 clean, install。这可以防止和同名文件冲突，并且确保命令总是被执行。**

#### 2. CMake 基础

* **核心优势是 ****跨平台** 和 **语法简洁**。[[7](https://www.google.com/url?sa=E&q=https%3A%2F%2Fvertexaisearch.cloud.google.com%2Fgrounding-api-redirect%2FAUZIYQHY_xJY95xU44cIinlwqHdpKTekO66ZwOmbZeV5JSg-DeWFMreoibbSk48BpDHvi1eU6FOKmMdKV96HRNRFECKtkEHsgXP1zfvtcmzfui9xda1voV_ClX-UO3HWb7XVhxWjTfmQ)]
* **核心命令:**
  * **cmake_minimum_required(VERSION 3.10): 指定要求的 CMake 最低版本。**
  * **project(MyProject): 定义项目名称。**
  * **add_executable(target_name source1 source2 ...): 生成可执行文件。**
  * **add_library(library_name [STATIC|SHARED] source1 source2 ...): 生成库文件（静态库或动态库）。**
  * **target_link_libraries(target_name library1 library2 ...): 为目标链接所依赖的库。**
  * **include_directories(dir1 dir2 ...): 指定头文件搜索路径。**
  * **add_subdirectory(source_dir): 添加一个子目录进行构建。**
* **构建流程:**
  1. **在项目根目录创建 CMakeLists.txt。**
  2. **创建一个单独的构建目录（如 build）并进入。**
  3. **运行 cmake .. （.. 指向 CMakeLists.txt 所在目录），生成 Makefile。**
  4. **运行 make 进行编译。**
* **CMake 相比 Makefile 的优势:**
  * **跨平台:** 一份 CMakeLists.txt 可以在不同平台生成对应的构建文件。[[8](https://www.google.com/url?sa=E&q=https%3A%2F%2Fvertexaisearch.cloud.google.com%2Fgrounding-api-redirect%2FAUZIYQGe-oQqDih3kBZqYrShNgVU5yyXqxeXgcsgFOwX6BcySiNxPvALOPyEdz_X_gfkCtwp3ZVYHuOyRMQCS5EO0maOU5aiDwfuxx6kHSk5In4hykOgTZT3NNcwLEYMQPiY8rHs)]
  * **自动查找依赖:** 可以自动查找依赖的库和头文件。
  * **与 IDE 集成良好:** 能够生成多种 IDE 的项目文件。
  * **可维护性:** 语法更高级，对于大型复杂项目更易于管理。[[8](https://www.google.com/url?sa=E&q=https%3A%2F%2Fvertexaisearch.cloud.google.com%2Fgrounding-api-redirect%2FAUZIYQGe-oQqDih3kBZqYrShNgVU5yyXqxeXgcsgFOwX6BcySiNxPvALOPyEdz_X_gfkCtwp3ZVYHuOyRMQCS5EO0maOU5aiDwfuxx6kHSk5In4hykOgTZT3NNcwLEYMQPiY8rHs)]

---

### 使用 GDB 进行复杂程序调试

#### 1. GDB 简介与准备

**gcc -g -o myapp myapp.c**

* **启动 GDB:**
  * **gdb **`<program>`**: 启动 GDB 并加载程序。**
  * **gdb **`<program>`** <core_dump_file>: 调试 coredump 文件。**
  * **gdb --args **`<program>`**`<arg1>`**`<arg2>`**: 启动时传递命令行参数。**

#### 2. 核心调试命令

* **运行与断点:**
  * **run (或 r): 运行程序。**
  * **break **`<location>`** (或 b): 设置断点。**`<location>`** 可以是行号 (b 10), 函数名 (b main)。**
  * **info breakpoints (或 i b): 查看所有断点信息。**
  * **delete <breakpoint_id> (或 d): 删除断点。**
  * **disable/enable <breakpoint_id>: 禁用/启用断点。**
  * **condition <breakpoint_id> **`<expr>`**: 设置条件断点，当表达式 **`<expr>`** 为真时断点才生效。**
* **程序执行控制:**
  * **step (或 s): 单步执行，会进入函数内部。[**[10](https://www.google.com/url?sa=E&q=https%3A%2F%2Fvertexaisearch.cloud.google.com%2Fgrounding-api-redirect%2FAUZIYQHGjZGi7m4Wt8S6jG7wHJcT0SmfogYl13ehT3M6fP_UzY55fLQZPsXuqMxjN0JZ3UA2AWRDEmp05JGCluUxcNulPmEqqUgPBFATemdrxUkZPYGgWhgsgQ%3D%3D)]
  * **next (或 n): 单步执行，不会进入函数内部。**
  * **continue (或 c): 继续运行直到下一个断点或程序结束。**
  * **finish: 运行直到当前函数返回。[**[10](https://www.google.com/url?sa=E&q=https%3A%2F%2Fvertexaisearch.cloud.google.com%2Fgrounding-api-redirect%2FAUZIYQHGjZGi7m4Wt8S6jG7wHJcT0SmfogYl13ehT3M6fP_UzY55fLQZPsXuqMxjN0JZ3UA2AWRDEmp05JGCluUxcNulPmEqqUgPBFATemdrxUkZPYGgWhgsgQ%3D%3D)]
  * **until <line_number>: 运行直到指定行。**
* **查看数据:**
  * **print **`<what>`** (或 p): 打印变量或表达式的值。**
  * **whatis **`<expr>`**: 显示表达式的数据类型。**
  * **display **`<expr>`**: 设置每次程序暂停时都自动显示的表达式（自动打印变量）。**
  * **info locals: 显示当前栈帧的所有局部变量。**
  * **info args: 显示当前函数的参数。**
  * **backtrace (或 bt): 查看函数调用栈。**
  * **frame <frame_num> (或 f): 切换到指定的栈帧。**

#### 3. 复杂程序调试技巧

* **多线程调试:**
  * 
  * **info threads: 查看所有线程。**
  * **thread <thread_id>: 切换到指定线程。**
  * **break **`<location>`** thread <thread_id>: 为特定线程设置断点。**
  * **set scheduler-locking [on|off|step]: 锁定线程调度，调试时只有当前线程会执行。**
* **多进程调试:**
  * **GDB 默认只跟踪 fork 后的父进程。[**[11](https://www.google.com/url?sa=E&q=https%3A%2F%2Fvertexaisearch.cloud.google.com%2Fgrounding-api-redirect%2FAUZIYQFT_C_8nAjT2gkp2lFt4U6Gu9Kf1iis5Pc31yA6HaMSwj-irxZODTMivoV3LkP5LF3dfhjxB9rtem_e37MHHQ4FoNAi4fFsQABdY5Sfi0_JUdMMVlOsqNk9002GqLJnJvo9tbFSv6WnGnHi3XRE88gt)]
  * **set follow-fork-mode [parent|child]: 设置 fork 后 GDB 是跟踪父进程还是子进程。[**[11](https://www.google.com/url?sa=E&q=https%3A%2F%2Fvertexaisearch.cloud.google.com%2Fgrounding-api-redirect%2FAUZIYQFT_C_8nAjT2gkp2lFt4U6Gu9Kf1iis5Pc31yA6HaMSwj-irxZODTMivoV3LkP5LF3dfhjxB9rtem_e37MHHQ4FoNAi4fFsQABdY5Sfi0_JUdMMVlOsqNk9002GqLJnJvo9tbFSv6WnGnHi3XRE88gt)]
  * **attach **`<pid>`**: 附加到一个已经在运行的进程上进行调试。**
* **调试 Core Dump:**
  * **当程序崩溃时，操作系统可以生成一个 core dump 文件，记录了程序崩溃时的内存状态、寄存器状态和调用栈。**
  * **使用 gdb **`<executable>`** <core_file> 来加载 core dump 文件进行事后调试。**
  * **进入 GDB 后，常用 bt 命令来查看崩溃时的函数调用栈，定位问题。**
* **观察点 (Watchpoint):**
  * **watch **`<expr>`**: 当表达式 **`<expr>`** 的值发生改变时，程序暂停。**
  * **rwatch **`<expr>`**: 当表达式 **`<expr>`** 被读取时，程序暂停。**
  * **awatch **`<expr>`**: 当表达式 **`<expr>`** 被读取或写入时，程序暂停。**

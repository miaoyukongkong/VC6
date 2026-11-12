# VC6 — 自考代码练习库

> 建立：**2026-11-02**｜面向：**C++ 程序设计（04737/04738）· 数据结构（13003/13004）· Java（13215/13216）**
> 仓库：`https://github.com/miaoyukongkong/VC6`｜VC6 安装：**`D:\VC6Tool\`**（全英文路径）
> 🔴 **练习方式 = 按章节建 VC6 工程**（与实践课"上机闭卷"考核方式一致）

---

## 🔴 一、为什么必须建工程（而不是用命令行）

**自考实践课（04738 / 13004）是「上机闭卷」—— 考场环境就是 VC6 IDE。**

**考场流程必然是：新建工程 → 写代码 → Build → 运行**

> 🔴 **所以平时练习必须练这个流程本身。**
> **用命令行 `cl.exe` 虽然能"更快跑通一个 cpp"，但它绕过了考场要考的操作 —— 练不到真本事。**
> **（我曾做过一个 `cc.ps1` 绕过工程，已按用户反馈删除。）**

**VC6 IDE 里单独一个 .cpp 无法直接运行的原因（实测）：**
- `Ctrl+F7` 只编译成 .obj，**不链接、不生成 exe**
- `F7` Build 需要工程（.dsp）上下文

**→ 工程不是"多余的形式"，是 VC6 的运行前提，也是考场技能。**

---

## 二、🔴 每章一个工程的建立步骤

### 2.1 新建工程（每章做一次）

```
File → New → Projects 标签
  → 选 "Win32 Console Application"
  → Project name:   ch01        （用章号，等教材目录确认后可改）
  → Location:       D:\VC6\cpp
  → 🔴 选 "An empty project"   （不要选 simple application，避免 stdafx 干扰教材代码）
  → OK → Finish
```

> 🔴 **为什么选 "An empty project"：**
> 教材代码通常 `#include <iostream.h>` 直接开始，没有 `#include "stdafx.h"`。
> 选 empty 可以照抄教材代码不改一行。

### 2.2 新建源文件并加入工程

```
File → New → Files → C++ Source File
  → File name: p01_hello.cpp
  → ✅ 勾选 "Add to project" 并选中 ch01
  → OK
```

### 2.3 编译运行

| 操作 | 快捷键 |
|---|:--:|
| 编译（只编译当前文件）| `Ctrl+F7` |
| **Build（编译+链接整个工程）** | **`F7`** |
| 运行（窗口停留）| **`Ctrl+F5`** |
| 单步调试 | `F10` / `F11` |

> 🎯 **考场通常按 `F7` 再 `Ctrl+F5`。**

---

## 三、🔴 一个工程里做多道练习 —— 多 main 冲突怎么处理

**问题：一个工程里有多个 .cpp，每个都有 `main()` → 链接报错**
`LINK : fatal error LNK2005: _main already defined`

**三种解法，按推荐度排序：**

### 方案 A（推荐）：做完的练习移出工程

```
ch01\
├── ch01.dsw / ch01.dsp
├── main.cpp          ← 当前在做的那道题（唯一有 main）
└── done\             ← 做完的练习移到这里（不加入工程）
    ├── p01_hello.cpp
    └── p02_variable.cpp
```

**操作：做完一题 → 把内容复制到 `done\pXX_xxx.cpp` → 把当前文件改成下一题。**

**优点：`F7` 永远只需要一条命令，无冲突。缺点：历史代码不在工程里（但仍在 git 里）。**

### 方案 B：用 `#if 0` 包住不做的练习

```cpp
// p01_hello.cpp —— 当前在做
#include <iostream.h>
void main() { cout << "hello" << endl; }

#if 0
// p02 变量（暂时不参与编译）
void main() { int a = 1; cout << a << endl; }
#endif
```

**优点：一个文件看得到全部。缺点：手写 `#if 0` 麻烦。**

### 方案 C（最专业）：VC6 排除文件参与编译

**FileView 里右键某个 .cpp → Settings → 勾选 "Exclude file from build"**

**优点：不用改代码。缺点：每次切换要操作菜单，考场不实用。**

> 🎯 **结论：平时练习用方案 A（干净），想一次看多题用方案 B。**

---

## 四、目录结构

```
D:\VC6\
├── README.md
├── .gitignore
├── cpp\                         ← C++ 程序设计（04737 + 04738 实践）
│   ├── hello_VC6\               ← ✅ 已有的第一个工程（用户建的）
│   └── ch01\  ch02\ ...         ← 🔴 每章一个工程（等教材目录确认章名）
├── ds\                          ← 数据结构（13003 + 13004 实践）
│   └── ch01\  ch02\ ...         ← 同样每章一个工程
├── java\                        ← Java（13215 + 13216，2027-10 才用）
└── 实践课手写清单\
    ├── C++实践课-15项必练.md
    └── 数据结构实践课-30项必练.md
```

> 🔴 **章节子目录暂不建** —— **等教材目录到手，按书里的真实章节名建**。
> （曾按猜测建过 ch01-基础语法…ch09-IO流，已被指出"不是书中的章节结构"，全部删除。）

---

## 五、文件命名规范

**VC6 是 1998 年的产品，中文文件名编译会失败。目录可中文，文件名必须英文。**

| 前缀 | 含义 | 示例 |
|:--:|---|---|
| `p` | program（教材例题）| `p03_pointer.cpp` |
| `e` | exercise（课后习题）| `e03_pointer.cpp` |
| `t` | test（自测）| `t02_bubble.cpp` |
| `w` | wrong（踩坑留档）| `w01_missing_header.cpp` |

**建议带页码便于回查：`p_p68_ex3-2.cpp`**

---

## 六、编译产物隔离（.gitignore）

| 文件 | 入库？| 原因 |
|---|:--:|---|
| `.cpp` / `.h` | ✅ | 源代码（核心资产）|
| **`.dsp` / `.dsw`** | ✅ | **工程定义 —— 考场技能的一部分，必须留** |
| `.ncb` | ❌ | IntelliSense 库，可达几十 MB |
| `.opt` / `.plg` / `.aps` / `.clw` / `.suo` | ❌ | IDE 用户设置 |
| `.obj` / `.exe` / `.ilk` / `.pdb` / `.pch` / `.idb` / `.exp` / `.lib` | ❌ | 编译产物 |
| `Debug/` / `Release/` | ❌ | 输出目录 |

---

## 七、学习流程

```
1. 读教材 → 在 chNN 工程里新建 pXX_xxx.cpp（勾 Add to project）
2. F7 Build → Ctrl+F5 运行
3. 改参数/改逻辑 → 观察变化
4. 有意犯一个错 → 看懂报错（w 前缀留档）
5. 🔴 合上教材，从零重写一遍（不看原代码）
6. 做完 → 移到 done\，当前文件改成下一题
```

> 🔴 **第 5 步是核心** —— 实践课是**上机闭卷**，看着教材敲在考场等于不会。

---

## 八、VC++ 6.0 已知坑（12 条）

| # | 坑 | 应对 |
|:--:|---|---|
| **1** | **中文文件名编译失败** | 文件名严格英文 |
| 2 | 路径含空格报错 | `D:\VC6\`、`D:\VC6Tool\` 无空格 ✅ |
| **3** | 中文安装路径偶发 "cannot open file" | ✅ **已迁移到 `D:\VC6Tool\`（全英文）** |
| 4 | 默认不生成 Debug 信息 | 建工程选 `Win32 Console Application` |
| 5 | `F5` 窗口一闪而过 | 用 **`Ctrl+F5`**，或 main 末尾加 `getchar();` |
| **6** | **`.dsp` 存绝对路径** | **建工程时选相对路径**；若移动目录打不开，用记事本改 .dsp 里的路径 |
| 7 | 多工程同目录互相干扰 | 每章单独子目录 ✅ |
| **8** | **多 main 链接冲突** | 见 §三（done\ 移出 / `#if 0` / Exclude from build）|
| **9** | 🔴🔴 **`Add Files to Project...` 导致 VC6 闪退**（2026-11-05 实测）| 老式 Common Dialog 在 Win10/11 上崩。**改用 `File → New → Files → C++ Source File` 并勾「Add to project」**（不走文件选择器，不崩）；已有文件需加入时 → **手改 `.dsp`**（见 §十二）|
| **10** | 🔴 **打开 .dsw 前有多个 MSDEV 僵死进程** | 反复闪退会留僵尸（线程数=0，`taskkill` 报 Access denied）。**它们不影响重开**，重启电脑清掉 |
| **11** | 🔴 **`std::string` 是字节串，不是字符串**（2026-11-07 实测）| VC6 的 `string` 底层是 `char[]`，**GBK 下一个汉字 = 2 字节**。`s.size()` / `s.length()` 返回**字节数**（`"C++语言程序设计"` → **15**，不是 9）；`substr(pos,len)` 的 pos 和 len 也是**字节**，**下标落在汉字中间就会切出半个字 → 乱码**（`"J++语言程序设计".substr(4,6)` → `"镅猿绦"`）。**→ 中文不要用 `substr` 按字符切；要按字处理得自己按 2 字节步进，或改用 `wstring`** |
| **12** | 🔴 **`using namespace std;` 写进头文件 → `C2871`**（2026-11-10 实测）| 头文件里若 `using namespace std;` 出现在 `#include <iostream>` / `<string>` **之前**，`std` 还没被声明 → `error C2871: 'std' : does not exist or is not a namespace`。**规矩：头文件一律不写 `using namespace std;`**（`std::string` 全写限定也行），`using` 只放在 `.cpp` 里，且必须在 provide `std` 的 `#include` 之后 |

> 🔴 **坑 9 是本次最浪费时间的坑**：点一次崩一次，4 次之后才发现是对话框问题。

---

## 九、代码时代差异（VC6 vs 现代 C++）

| 项 | VC6/老教材 | 现代标准 |
|---|---|---|
| 头文件 | `#include <iostream.h>` | `#include <iostream>` + `using namespace std;` |
| main | 教材常写 `void main()` | 建议 `int main() { ... return 0; }` |
| 预编译头 | 建 "simple application" 会带 stdafx | **建 "empty project" 避免** |

> 🎯 **按教材写（考试对），但心里知道现代写法。**

---

## 十、当前状态

| 项 | 状态 |
|---|:--:|
| VC++ 6.0 安装 | 🟢 **`D:\VC6Tool\`**（2026-11-02 从中文路径迁入）|
| IDE 启动 | 🟢 已验证 —— 🔴 **必须用 `launch-vc6.bat` 启动**（见 §十一）|
| cl.exe | 🟢 已验证（12.00.8804）—— `Error spawning cl.exe` 已修复（见 §十一）|
| 第一个工程 | 🟢 `cpp\hello_VC6\`（用户已建并跑通）|
| **当前工程** | 🟢 `cpp\ch03\`（教材第 3 章）|
| **C++ 第 1 章进度** | 🟢 **第 1 章全部完成** —— 1.2 节 14 个程序（2026-11-07）＋ 习题 8 题（2026-11-09）|
| **C++ 第 2 章进度** | 🟢 **第 2 章全部完成**（2026-11-09 → 11-11）：8 个程序（2-1 ~ 2-8）＋ 习题 **10 题**（3.1 / 3.2 / 3.3 / 4.1 / 4.2 / 4.3 / 5.1 / 5.2 / 5.3 / 5.4）全部归档 |
| **C++ 第 3 章进度** | 🟡 **进行中**（2026-11-12 起）：3.1 构造函数 —— 程序 3-1-1（类 `Student` ＋ 两个构造函数、成员对象 `myDate`）已归档；`ch03` 工程编译 **0 error / 0 warning**（ch03.plg 08:44）|

### 10.1 学习进度台账

| 小节 | 程序 | 状态 | 归档文件 | 关键点 / 踩坑 |
|---|:--:|:--:|---|---|
| 1.2.1 | 1-1 输入输出 | 🟢 | `done/p1-1-input-output.cpp` | 曾错拼 `namespce`、变量名 `ontInt1` 笔误 |
| 1.2.2 | 1-2 强制类型转换 | 🟢 | `done/p1-2-type-casting.cpp` | 🔴 **`const_cast` 改真正的 const 对象 = 未定义行为**：`ca` 仍打印 30（常量折叠），`*p` 读 40 —— 同一地址两个值 |
| 1.2.3 | 1-3 带默认值的函数 | 🟢 | `done/p1-3-default-parameters.cpp` | 函数定义须在 `main` 之前（否则 `C2065: undeclared identifier`）；**默认值只能写一次** |
| 1.2.4 | 1-4 引用的定义和使用 | 🟢 | `done/p1-4-definition-and-usage-of-references.cpp` | |
| 1.2.4 | 1-5 引用初始化 | 🟢 | `done/p1-5-reference-initialization.cpp` | `int & r3=(int &)cInt;` 报 **C2440**（`cInt` 是 const）→ 改 `(int &)*(int *)&cInt` |
| 1.2.5 | 1-6 值传递与引用传递 | 🟢 | `done/p1-6-pass-by-value-and-pass-by-reference.cpp` | 值传递交换无效、引用传递生效 |
| 1.2.5 | 1-7 引用函数和指针函数 | 🟢 | `done/p1-7-function-returning-a-reference-or-a-pointer.cpp` | `pointValue(oneY)=40;` 是**双层类型错** → 正确写法 **`*pointValue(&oneY)=40;`**。🎯 **引用把 `*`/`&` 藏起来了，指针两个都得自己写** |
| 1.2.6 | 1-8 常量指针 | 🟢 | `done/p1-8-constant-pointer.cpp` | `const` 的位置决定谁不可改：`const int *p`（指向的不可改）/ `int * const p`（指针本身不可改）/ `const int * const p`（都不可改）|
| 1.2.7 | 内联函数 | 🟢 | `done/p1-8-7-inline-function.cpp` | 用 `QueryPerformanceCounter` 实测普通函数 vs `inline` 的调用开销；**`inline` 只是给编译器的建议，不保证内联** |
| 1.2.8 | 函数重载 | 🟢 | `done/p1-8-8-function-overloading.cpp` | 🎯 **返回类型不参与重载** —— `int f(int)` 和 `float f(int)` 不能共存；只有参数列表（个数/类型/顺序）能区分 |
| 1.2.9 | 指针和动态内存分配 | 🟢 | `done/p1-8-9-pointer-and-dynamic-memory-allocation.cpp` | `new` / `delete` 必须配对；**`delete p;` 之后 `p=0;`** —— 否则是悬空指针 |
| 1.2.10 | 1-8-10 `string` 的使用 | 🟢 | `done/p1-8-10-usage-of-string.cpp` | 默认构造的 `string` 是空串，`cout` 输出为空白（不是乱码）|
| 1.2.10 | 1-9 `string` 成员函数 1 | 🟢 | `done/p1-9-usage1-of-string-member-functions.cpp` | `empty()` / `length()` / `size()` |
| 1.2.10 | 1-10 `string` 成员函数 2 | 🟢 | `done/p1-10-usage2-of-string-member-functions.cpp` | 🔴 **`size()` 返回字节数不是字数**（中文 9 字符 = 15 字节）；**`substr` 的 pos/len 单位是字节**，会把汉字切半个 → 见 §八 坑 11 |
| 1.3 习题 | 习题 3.1 输出 590 | 🟢 | `done/c1-3.1-output-590.cpp` | 默认参数在**形参列表末尾**：`func(5,9)` → `a=5,b=9,c=0`，连续打印即 `590` |
| 1.3 习题 | 习题 3.2 输出 6 | 🟢 | `done/c1-3.2-output-6.cpp` | 🎯 `const int *p` 是「**指向常量的指针**」—— 不能改 `*p`，但**可以改 `p` 本身**（`p=&y` 合法，输出 6）|
| 1.3 习题 | 习题 3.3 圆的周长和面积 | 🟢 | `done/c1-3.3-circumference-and-area-of-circle.cpp` | `cin` 前不必 `endl` —— `cout` 与 `cin` 绑定，`cin` 会自动冲刷提示语。`r=5` → 周长 31.4159 / 面积 78.5397 |
| 1.4 习题 | 习题 4.1 重载输出 7 | 🟢 | `done/c1-4.1-function-overloading-output-7.cpp` | `6.0` 是 `double` → 走 `fun(double)` = `(int)6.0/2 = 3`；`2` 是 `int` → 走 `fun(int)` = `2*2 = 4`；和 = **7** |
| 1.4 习题 | 习题 4.2 引用与指针 | 🟢 | `done/c1-4.2-reference-and-pointer.cpp` | 🎯 **引用是别名，指针是地址**：`ref=2` 直接改 `oneInt`；`int *p=&ref` 取到同一地址，`*p=3` 让 `ref`/`oneInt` 一起变 3 —— 三者是同一块内存 |
| 1.4 习题 | 习题 4.3 输出 345 | 🟢 | `done/c1-4.3-function-output-345.cpp` | 🟡 **`main` 忘写 `return 0;`** → `warning C4508: function should return a value; 'void' return type assumed`（能跑但不规范）。输出 `3/4/5`：`b++`→1、`c++`→2、`f(i)=i+1+2` |
| 1.4 习题 | 习题 4.4 重载与二义性 | 🟢 | `done/c1-4.4-function-overloading-and-ambiguity.cpp` | `bigger(int,float)` 是**精确匹配** → `bigger(xI,yF)` 输出 40。🔴 **真正二义的是 `bigger(10, 60.0)`**：`double→int` 与 `double→float` 同属「转换」等级，编译器无法选择 |
| 1.5 习题 | 习题 5 `string` 综合应用 | 🟢 | `done/c1-5-string-array.cpp` | `new string[n]` 动态数组 ＋ `delete[] p; p=0;`。⚠️ `p[j].size()` 按**字节**比长短（中文串偏大）；未判 `n<=0`，`totalLength/n` 会除零 |

> 🎯 **速率标定：1 小节 ≈ 1h**（W45 周中回顾实测）。
> ✅ **1.2 节 2026-11-07 全部收口**：14 个程序，10 小时（08:10 ~ 21:03）。
> ✅ **第 1 章 2026-11-09 全部收口**：习题 8 题（3.1/3.2/3.3 ＋ 4.1/4.2/4.3/4.4 ＋ 5），全部编译 0 error、输出与教材一致。

**第 2 章（面向对象的基本概念）**

| 小节 | 程序 | 状态 | 归档文件 | 关键点 / 踩坑 |
|---|:--:|:--:|---|---|
| 2.1 | 程序2-1 定义日期类 `myDate` | 🟢 | `done/p2-1-definition-of-class-myDate.cpp` | 类声明（`.h`）与成员函数定义（`.cpp`）分离；`myDate()` 和 `myDate(int,int,int)` 是两个**重载的构造函数**（默认构造 + 带参构造）|
| 2.2 | 程序2-2 定义学生类 `Student` | 🟢 | `done/p2-2-definition-of-class-Student.cpp` | 🔴 **类外定义成员函数必须写 `类名::`**；`printStudent() const` 是**常成员函数**，只能读成员不能改 |
| 2.3 | 类声明与实现分离（重构） | 🟢 | 当前工程结构：`myDate.h`/`myDate.cpp`/`Student.h`/`Student.cpp`/`main.cpp` | 🔴 **头文件禁止写 `using namespace std;`** → 见 §八 坑 12（`C2871`）；`main.cpp` 只负责 `#include` + `main()`，类定义和成员函数定义已在 `.h`/`.cpp` 里，重复写会 `C2011` 重复定义 + `LNK2005` 符号重复 + 缺 `_main` |
| 2.3 | 程序2-2 分文件重构后运行 | 🟢 | 工程当前状态 | 输出：`姓名：张三	 生日：1998/1/15` / `getName() = 张三`；三文件编译+链接 **0 error** |
| 2.4 | 程序2-3 验证类功能的驱动程序 | 🟢 | `done/p2-3-class-feature-validation.cpp` | 直接对象调用 `ss.setStudent(name_, myDate(y,m,d))`；`cin>>name_>>y>>m>>d` 一次读四项 |
| 2.4 | 程序2-4 指针方式驱动程序 | 🟢 | `done/p2-4-member-access-through-pointer.cpp` | 🎯 `Student *sp=&ss;` 之后全用 `sp->` —— **取地址一次，箭头到底** |
| 2.4 | 程序2-5 引用方式驱动程序 | 🟢 | `done/p2-5-member-access-through-reference.cpp` | 🎯 `Student &sy=ss;` 之后 `sy.` 与 `ss.` 完全等价 —— **`&` 只出现一次，之后不用任何符号** |
| 2.5 | 程序2-6 类成员的访问示例1 | 🟢 | `done/p2-6-example1-of-member-access.cpp` | `public` 的 `box.length` 可直接赋值；`private` 的 `width` 只能经 `setWidth`/`getWidth`。⚠️ 输出串 `Length 0f box` 里的 `0f` 是**教材原文笔误**（应为 `of`），非代码错 |
| 2.6 | 程序2-7 类成员的访问示例2 | 🟢 | `done/p2-7-example2-of-member-access.cpp` | 成员全 `private`（`szName`/`salary`），只能经 4 个接口访问；🔴 `averageSalary(CEmployee el)` **按值传对象**（整体复制一份），输出 `aver=4250` |
| 2.7 | 程序2-8 作用域隐藏规则 | 🟢 | `done/p2-8-scope-hiding.cpp` | 🎯 内层 `int a=2` **隐藏**外层 `a`，内层结束外层仍是 1；而不带 `int` 的 `a=3` 改的是外层 → 输出 **1 2 1 3 3** |

**第 2 章习题（10 题全部归档，2026-11-11 收口）**

| 习题 | 内容 | 状态 | 归档文件 | 关键点 / 踩坑 |
|---|:--:|:--:|---|---|
| 3.1 | 输出 1020 | 🟢 | `done/c2-3.1-output-1020.cpp` | 带参构造函数 `Test(int,int)` 初始化 `x`/`y`；`cout<<mt.getx()` 与 `cout<<mt.gety()` 分两次输出，连起来就是 `1020` |
| 3.2 | 输出 1-10-2 | 🟢 | `done/c2-3.2-output-1-10-2.cpp` | 🔴 **`fun()` / `show()` 没写返回类型** —— VC6 只报 `warning C4183`（「看起来像构造函数」），因为 C++98 允许**隐式 int**；换成现代编译器这两行是硬错误。`if(y>0) cout<<",y="<<y;` 是第二行只输出 `x=2` 的原因 |
| 3.3 | 成员初始化 ＋ `getc` 改名 | 🟢 | `done/c2-3.3.cpp` | 🔴 **`int getc();` 不能作成员名** —— `getc` 是 `<stdio.h>` 的宏，经 `<iostream>` 间接引入后会被展开 → 改名 `getC()`。构造函数初始化列表 `A():a(0),b(0),c(0),d(0){}` **按成员声明顺序执行**，与列表书写顺序无关。输出 `0,0` |
| 4.1 | 双重指针 | 🟢 | `done/c2-4.1-double-pointer.cpp` | 🎯 `int* p=&a; int** pp=&p;` → `**pp` 直接取到 `a`；`**pp=99` 改的是最底层变量。输出 10 / 10 / 10 / 99 |
| 4.2 | 求最小值 | 🟢 | `done/c2-4.2-minimum.cpp` | 私有 `getmin()` 先取 `a,b` 较小值，公有 `GetMin()` 再与 `c` 比；`return (d = d<c ? d : c);` 在返回表达式里夹了赋值（能跑但不推荐）。`setValue(34,6,2)` → **2** |
| 4.3 | 指针与数组类型的类 | 🟢 | `done/c2-4.3-class-by-pointer-and-array.cpp` | 对象指针两种访问等价：`(*p).setx()` 与 `p->sety()`；`new MyClassType1` 后 `delete p; p=0;`；对象数组 `objArr[10]` 先初始化下标 0~4，再用 `p=&objArr[9]` 配合 `while(p>=&objArr[5])` 倒序改成 88/99 —— 只有后半段被覆盖 |
| 5.1 | 设计并实现类 `Course` | 🟢 | `done/c2-5.1-class-Course.cpp` | 两个枚举（课程类别／授课专业）＋ 私有辅助函数转中文；默认构造与带参构造都用初始化列表。🔴 **setter 踩坑**：参数名是 `cred`／`hrs`，函数体却写 `credits=(credits>0)?credits:0.0` —— 判断的是成员自己，等于**没赋新值**（应写 `cred`）|
| 5.2 | 设计并实现类 `Point` | 🟢 | `done/c2-5.2-class-Point.cpp` | 构造 `Point(double=0.0,double=0.0)`；`distanceToOrigin`＝√(x²+y²)；`distanceBetween` 两点距；`canFormTriangle` 用 `EPS=1e-6` 做三角不等式 —— p1(0,0)/p2(3,4)/p3(6,8) 共线 ⇒ 不能构成三角形，换成 p4(0,4) 就能 |
| 5.3 | 设计并实现类 `MyLine` | 🟢 | `done/c2-5.3-class-MyLine.cpp` ＋ 工程内 `Point.h`/`Point.cpp` | 一般式 `Ax+By+C=0`；两点式 A=y2−y1、B=x1−x2、C=x2·y1−x1·y2；斜率 = −A/B（B≈0 抛 `runtime_error`）；点线距 = \|Ax+By+C\|/√(A²+B²)；**Point 拆成头文件＋实现文件**，工程已加入并链接成功 |
| 5.4 | 设计并实现类 `Cylinder` | 🟢 | `done/c2-5.4-class-Cylinder.cpp`（= 当前 `main.cpp`）| 默认参数构造＋负值归零；四个公式：底圆周长 2πr、底面积 πr²、体积＝底面积×h、表面积＝2πrh＋2πr²；工程编译 **0 error / 0 warning**（ch02.plg 2026-11-11 19:51）|

> ✅ **第 2 章 2026-11-10 全部收口**：2.1~2.7 七小节 ＋ 8 个程序（2-1 ~ 2-8），全部编译 0 error、输出与教材一致。
> ✅ **第 2 章习题 2026-11-11 全部收口**：10 题（3.1/3.2/3.3、4.1/4.2/4.3、5.1/5.2/5.3/5.4）全部归档；工程当前编译 **0 error / 0 warning**（ch02.plg 19:51）。下一步新建 `cpp\ch03\`，进第三章 3.1 构造函数。

**第 3 章（类和对象进阶）**

| 小节 | 程序 | 状态 | 归档文件 | 关键点 / 踩坑 |
|---|:--:|:--:|---|---|
| 3.1 | 程序3-1-1 类 `Student` ＋ 两个构造函数 | 🟢 | `done/p3-1-1-class-Student-and-two-Constructors.cpp`（＝当前 `main.cpp`；工程另含 `myDate.h`/`myDate.cpp`）| 🎯 **重载构造函数**：`Student()` 用初始化列表给默认值（`name("Noname")`、`birthday(myDate())`＝1970/1/1），`Student(string)` 只初始化姓名；**成员对象 `birthday` 先于 `Student` 构造体构造**。`setStudent(string)` 内部再造临时 `myDate` 再 `birthday.setDate(d)` —— 走 `setDate(myDate)` 重载。工程编译 **0 error / 0 warning**（ch03.plg 08:44）|

---

## 十一、🔴🔴 `Error spawning cl.exe` —— 移动安装目录后必须改注册表

**症状**：`F7` / Rebuild All 后 Output **只显示一行** `ch01.exe - 1 error(s)`；`Ctrl+F5` 弹「This file does not exist. Do you want to build it?」→ 点「是」→ 又弹，**无限循环**。**代码本身完全正确。**

**第一步：看完整报错**

VC6 的 Output 窗口太小，只显示最后一行。**用记事本打开 `chNN.plg` —— 那是完整构建日志**：

```
Compiling...
Error spawning cl.exe
```

**根因**

VC6 的编译器路径存在**注册表**里，不跟着安装目录走。把 `D:\Downloads\VC6.0 完整绿色版` 移到 `D:\VC6Tool` 后，注册表 4 项仍是旧路径 → VC6 按旧路径找 `cl.exe` → 找不到。

```
HKCU\Software\Microsoft\DevStudio\6.0\Build System\Components\Platforms\Win32 (x86)\Directories
  ├─ Path Dirs
  ├─ Include Dirs
  ├─ Library Dirs
  └─ Source Dirs
```

**修复三步（逐个踩坑）**

| 步 | 操作 | 结果 |
|:--:|---|---|
| 1 | 把 `Directories` 4 项的旧路径改成 `D:\VC6Tool\...` | 🔴 仍失败 —— `Use Environment Paths = 0` 时不生效 |
| 2 | `Use Environment Paths` 改为 **1** | 🟡 报错变成 `fatal error C1034: iostream: no include path set` —— **说明 cl.exe 已经找到了**，只是缺 INCLUDE |
| 3 | 补设用户环境变量 `INCLUDE` / `LIB` / `PATH` | ✅ `ch01.exe - 0 error(s), 0 warning(s)` |

**最终配置（用户级环境变量）**

```
PATH    += D:\VC6Tool\VC98\Bin
PATH    += D:\VC6Tool\Common\MSDev98\Bin
INCLUDE  = D:\VC6Tool\VC98\Include;D:\VC6Tool\VC98\ATL\Include;D:\VC6Tool\VC98\MFC\Include
LIB      = D:\VC6Tool\VC98\Lib;D:\VC6Tool\VC98\MFC\Lib
```

**⚠️ 坑中坑：`explorer.exe` 的环境变量是旧的**

explorer 开机就启动，拿到的是**旧环境**。**从资源管理器双击 `.dsw` 启动的 VC6 继承 explorer 的旧环境 → 照样报错。**

**解法：用 `launch-vc6.bat` 启动**（脚本内先设好 PATH/INCLUDE/LIB 再启动 msdev.exe）：

```
D:\VC6\launch-vc6.bat
```

或者重启电脑让 explorer 拿到新环境。

> 🔴 注册表改完记得导出备份（`reg-backup/`，已 gitignore）。
> 🔴 **不要用命令行 `cl.exe` 编译自己工程的 `Debug\`** —— 会污染 VC6 的构建状态（`.opt` 与实际不符），加剧弹框循环。验证语法请用临时目录。

---

## 十二、🔴 手动把文件加入工程（绕过闪退的 `Add Files`）

**`Add Files to Project...` 会闪退时，直接改 `.dsp` 文本 —— 100% 可靠：**

**步骤：**
```
1. 关闭 VC6（必须关，否则会被覆盖）
2. 用记事本打开 chNN.dsp
3. 找到这一段：
     # Begin Group "Source Files"

     # PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
     # End Group
4. 在 PROP 行之后、# End Group 之前插入：

     # Begin Source File

     SOURCE=.\main.cpp
     # End Source File

5. 保存（保持 GBK/ANSI 编码，别存成 UTF-8）
6. 删除同目录的 .ncb 和 .plg（旧缓存）
7. 重开 .dsw → F7
```

**⚠️ 注意 `SOURCE=.\文件名.cpp` 必须用相对路径（`.\` 开头），不能写绝对路径。**

## 十三、🚀 下一步

**1. 第二章：面向对象的基本概念（7 小节）** —— 工程 `cpp\ch02\`，**2.1~2.7 全部完成**（2026-11-09 → 11-10），8 个程序已归档。
- ✅ 2.1 结构化程序设计
- ✅ 2.2 面向对象程序设计的概念和特点
- ✅ 2.3 类的初步知识（`myDate` / `Student` 两个类 ＋ 声明与实现分离）
- ✅ 2.4 类的示例程序剖析（程序 2-3 / 2-4 / 2-5：直接、指针、引用三种驱动程序）
- ✅ 2.5 访问对象的成员（程序 2-6）
- ✅ 2.6 类成员的可访问范围（程序 2-7）
- ✅ 2.7 标识符的作用域与可见性（程序 2-8，输出 1 2 1 3 3）
- ✅ **第 2 章习题 10 题全部归档**（3.1 ~ 5.4，2026-11-11）
  - ✅ 3.1 输出 1020 ／ 3.2 输出 1-10-2 ／ 3.3 成员初始化＋`getc` 改名 ／ 4.1 双重指针 ／ 4.2 求最小值 ／ 4.3 对象指针与对象数组 ／ 5.1 类 Course ／ 5.2 类 Point ／ 5.3 类 MyLine ／ 5.4 类 Cylinder

**2. 第三章：类和对象进阶（8 小节）** —— `cpp\ch03\` 工程已建立（2026-11-12 08:29）。教材 60 页，是第 1 章的两倍，密度最高。
- ✅ **3.1 构造函数**（2026-11-12 归档，程序 3-1-1：`Student` 两个重载构造函数 ＋ 成员对象 `myDate`） ／ 3.2 析构函数（下一步） ／ 3.3 类的静态成员 ／ 3.4 变量及对象的生存期和作用域
- 3.5 常量成员和常引用成员 ／ 3.6 成员对象和封闭类 ／ 3.7 友元 ／ 3.8 this 指针

**3. 🔴 合上教材从零重写第 1 章的程序**（README §七 第 5 步）—— 实践课是上机闭卷，这些必须能默写：常量指针三种写法 / `*pointValue(&oneY)=40` / `new`-`delete` 配对 / 函数重载只看参数列表 / 引用与指针的区别。

**4. 每做完一题** —— 复制到 `done\`，`main.cpp` 清空写下一题（README §三 方案 A）。

**5. 实践课清单** —— 见 `实践课手写清单\`，学一项勾一项。

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

## 八、VC++ 6.0 已知坑（8 条）

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
| IDE 启动 | 🟢 已验证（MSDEV.EXE 正常）|
| cl.exe | 🟢 已验证（编译器 12.00.8804）|
| 第一个工程 | 🟢 `cpp\hello_VC6\`（用户已建并跑通）|
| **教材目录** | 🔴 **待提供 → 才能按真实章节建工程** |

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

**1. 环境已就绪** —— VC6 里 `File → Open Workspace` 打开 `cpp\hello_VC6\hello_VC6.dsw` 确认能 Build。

**2. 等教材目录** —— 拿到后按真实章节建 `ch01\ ch02\ ...`，每章一个工程。

**3. 实践课清单** —— 见 `实践课手写清单\`，学一项勾一项。

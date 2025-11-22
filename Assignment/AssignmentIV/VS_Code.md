# VS Code Configuration & Setup Experience

## 1. Environment Overview
To establish a stable development environment, I followed the tutorial: [VS Code C/C++ Environment Setup Guide](https://medium.com/@k053170/vs-code-%E5%BB%BA%E7%BD%AE-c-%E8%AA%9E%E8%A8%80%E7%92%B0%E5%A2%83-f0da35437c01).

- **OS:** Windows (using MinGW64 / Git Bash terminal)
- **Compiler:** GCC/G++ (Rev10, Built by MSYS2 project)
- **IDE:** Visual Studio Code

## 2. Essential Extensions
During development, I utilized the following extensions to enhance productivity:
1. **C/C++ (Microsoft):** For IntelliSense, debugging, and code browsing.
2. **Code Runner:** For quick code execution during early testing.

## 3. Challenges & Solutions
During the setup process, I encountered several configuration issues. Here is how I resolved them:

### A. Compiler Path Configuration
**Problem:** VS Code initially could not locate the compiler.
**Solution:** I realized that the compiler's `bin` folder needed to be added to the system's **Environment Variables (Path)**. After adding the correct path, the terminal recognized the `gcc` and `g++` commands.

### B. Configuring `tasks.json` and `launch.json`
**Problem:** The default build task did not work for my project structure, and I faced issues when trying to debug.
**Solution:** - I manually modified `tasks.json` to ensure the arguments correctly pointed to my source files.
- I adjusted `launch.json` to enable the debugger to attach to the correct executable.
- This process helped me understand how VS Code interacts with the underlying compiler.

### C. Understanding GCC vs. G++
**Observation:** Through trial and error, I learned the distinct roles of the compilers:
- Used `gcc` for compiling the C version of the assignment.
- Used `g++` for the C++ version to properly handle standard libraries.

## 4. Verification & Execution
To verify the setup, I used two methods to compile and run the code:

- **Terminal (Manual Compilation):** Using the terminal allows full control over compilation flags.
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Code Runner: I also utilized the Code Runner extension to quickly debug and run code snippets during the development phase.

# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: [Yu-Cheng Wei]  
Email: [iixun01200.tw@gmail.com]  

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
  unsigned long hash = 0;
    long long temp_key = key;
    if(temp_key < 0){
        temp_key = -key;
        hash     = 1000000; 
    }
    while(temp_key != 0){
        hash = hash * 31 + (temp_key % 10);
        temp_key /= 10;
    }
    return hash % m;  
  ```
- Rationale: 
  我先將正負數作為分類，以區分不同的`hash`值，再進行絕對值，已便於所有的數字都可以進行運算，並且選擇質數
  作為乘數，相比於偶數，能夠最大化分佈的效果，透過`key%10`取餘，將整數進行分解。
  原本不太理解`Non-integer key`為何要用`unsigned long`作為宣告，但我研究後發現，在`overflow`後，
  `C++`會從0開始計數，剛好也能夠貼合最大化分佈的目標。

### Non-integer Keys
- Formula / pseudocode:
  ```text
    unsigned long hash = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        hash = tolower(str[i])-'a' + hash * 31;
    }
  ```
- Rationale: 
  字串部分，我會這樣做的想法，是因為我看到有一個很有名的`hash function - Polynomial Rolling Hash`，
  我一開始寫的是，根據`isupper`|`islower`，去進行設定，但發現如果遇到`cat`跟`Cat`，如果全部都用類似`c-'a'`或`C-'A'`
  的方法，會導致分佈不構均勻，最後決定直接忽略大小寫，統一轉成小寫計算。

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | Pattern repeats every 10 |
| 11             | 10, 0, 1, 2, ...       | More uniform             |
| 37             | 20, 21, 22, 23, ...    | Near-uniform             |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

### Result Snapshot
- Example output for integers:
  * C++
  ![0](https://github.com/Ycwei01200/11401_CS203A/blob/main/Picture/c++-integer-key(1).png?raw=true)
  ![1](https://github.com/Ycwei01200/11401_CS203A/blob/main/Picture/c++-integer-key(2).png?raw=true)
  * C
  ![0](https://github.com/Ycwei01200/11401_CS203A/blob/main/Picture/c-integer-key(1).png?raw=true)
  ![1](https://github.com/Ycwei01200/11401_CS203A/blob/main/Picture/c-integer-key(2).png?raw=true)
- Example output for strings:
  * C++
  ![0](https://github.com/Ycwei01200/11401_CS203A/blob/main/Picture/c++-non-integer-key(1).png?raw=true)
  ![1](https://github.com/Ycwei01200/11401_CS203A/blob/main/Picture/c++-non-integer-key(2).png?raw=true)
  * C
  ![0](https://github.com/Ycwei01200/11401_CS203A/blob/main/Picture/c-non-integer-key(1).png?raw=true)
  ![1](https://github.com/Ycwei01200/11401_CS203A/blob/main/Picture/c-non-integer-key(2).png?raw=true)

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- Prime vs non-prime `m`: Prime table sizes generally result in better distribution and fewer collisions.
- Patterns or collisions: Non-prime table sizes tend to produce repetitive patterns, leading to more collisions.
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.

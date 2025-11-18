/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp
    - 2025/11/18: download from AssignmentIV (hash_fn.cpp/hash_fn.hpp/main.cpp)
    - 2025/11/18: modify hash functions
   Developer: Yu-Cheng Wei <iixun01200.tw@gmail.com> 
 */
#include <string>
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
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
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        hash = tolower(str[i])-'a' + hash * 31;
    }
    return static_cast<int>(hash % m);  
}

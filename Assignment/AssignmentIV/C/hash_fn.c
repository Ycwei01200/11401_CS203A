/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp
    - 2025/11/18: download from AssignmentIV (hash_fn.cpp/hash_fn.hpp/main.cpp)
    - 2025/11/18: modify hash functions
    - 2025/11/18: 23:51 Finished Development(revised developer info)
    - 2025/11/21: Update logic to use tolower() (Kept CamelCase to match main.c interface)
   Developer: Yu-Cheng Wei <iixun01200.tw@gmail.com> 
 */
#include "hash_fn.h"
#include <ctype.h>

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

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    for(int i = 0;str[i] != '\0';i++){
        hash = tolower(str[i])-'a' + hash * 31;
    }
    return (int)(hash % m + m) % m; // basic division method
}

/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation

   Developer: Yu-Cheng Wei <iixun01200.tw@gmail.com> 
 */
#include <stdio.h>

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
    for(auto i = 0;str[i] != '\0';i++){
        hash = str[i]-'a' + hash * 31;
    }
    return (int)(hash % m + m) % m; // basic division method
}

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
    // TODO: replace with your own design
    return (key % m + m) % m;  // division method example
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    for(int i = 0;str[i] != '\0';i++){
        hash = hash * 29 + str[i];
    }
    return (int)(hash % m + m) % m; // basic division method
}

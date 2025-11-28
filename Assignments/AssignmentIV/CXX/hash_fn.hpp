/*
   ========================================
   hash_fn.hpp — declare your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

    Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/28: download from AssignmentIV (hash_fn.cpp/hash_fn.hpp/main.cpp)
    

   Developer: Yu-Cheng Wei <iixun01200.tw@gmail.com> 
 */
#ifndef HASH_FN_HPP
#define HASH_FN_HPP

#include <string>

int myHashString(const std::string& str, int m);
int myHashInt(int key, int m);

#endif

/*
   ========================================
   hash_fn.hpp — declare your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/17: Initial implementation
    - 2025/11/18: download from AssignmentIV (hash_fn.cpp/hash_fn.hpp/main.cpp)
    - 2025/11/18: 23:51 Finished Development(revised developer info)
   Developer: Yu-Cheng Wei <iixun01200.tw@gmail.com> 
 */
#ifndef HASH_FN_HPP
#define HASH_FN_HPP

#include <string>
int myHashInt(int key, int m);
int myHashString(const std::string& str, int m);


#endif

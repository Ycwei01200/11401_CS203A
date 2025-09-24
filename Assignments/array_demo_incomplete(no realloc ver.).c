#include <stdio.h>
#include <stdlib.h>

int main(){
    int *array;
    int n = 10;

    array = (int *) malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
        printf("Index %d -> Value: %d, Address: %p\n", i, array[i], (void*)&array[i]);
    }

    n = n * 2;

    
    
    for (int i = n/2; i < n; i++) {
        array[i] = i + 1;   // initialize new elements
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
        printf("Index %d -> Value: %d, Address: %p\n", i, array[i], (void*)&array[i]);
    }
    
    free(array);
    array = NULL;
    
    
    return 0;
}
/*

1 Index 0 -> Value: 1, Address: 0x5b2e11afe2a0
2 Index 1 -> Value: 2, Address: 0x5b2e11afe2a4
3 Index 2 -> Value: 3, Address: 0x5b2e11afe2a8
4 Index 3 -> Value: 4, Address: 0x5b2e11afe2ac
5 Index 4 -> Value: 5, Address: 0x5b2e11afe2b0
6 Index 5 -> Value: 6, Address: 0x5b2e11afe2b4
7 Index 6 -> Value: 7, Address: 0x5b2e11afe2b8
8 Index 7 -> Value: 8, Address: 0x5b2e11afe2bc
9 Index 8 -> Value: 9, Address: 0x5b2e11afe2c0
10 Index 9 -> Value: 10, Address: 0x5b2e11afe2c4
1 Index 0 -> Value: 1, Address: 0x5b2e11afe2a0
2 Index 1 -> Value: 2, Address: 0x5b2e11afe2a4
3 Index 2 -> Value: 3, Address: 0x5b2e11afe2a8
4 Index 3 -> Value: 4, Address: 0x5b2e11afe2ac
5 Index 4 -> Value: 5, Address: 0x5b2e11afe2b0
6 Index 5 -> Value: 6, Address: 0x5b2e11afe2b4
7 Index 6 -> Value: 7, Address: 0x5b2e11afe2b8
8 Index 7 -> Value: 8, Address: 0x5b2e11afe2bc
9 Index 8 -> Value: 9, Address: 0x5b2e11afe2c0
10 Index 9 -> Value: 10, Address: 0x5b2e11afe2c4
11 Index 10 -> Value: 11, Address: 0x5b2e11afe2c8
12 Index 11 -> Value: 12, Address: 0x5b2e11afe2cc
1226846769 Index 12 -> Value: 909259313, Address: 0x5b2e11afe2d0
926299192 Index 13 -> Value: 959527225, Address: 0x5b2e11afe2d4
1850286130 Index 14 -> Value: 1847603251, Address: 0x5b2e11afe2d8
2019910766 Index 15 -> Value: 2019910766, Address: 0x5b2e11afe2dc
540356896 Index 16 -> Value: 540356896, Address: 0x5b2e11afe2e0
1633034302 Index 17 -> Value: 1633034302, Address: 0x5b2e11afe2e4
1702194273 Index 18 -> Value: 1702194273, Address: 0x5b2e11afe2e8
925966394 Index 19 -> Value: 925966394, Address: 0x5b2e11afe2ec
*/

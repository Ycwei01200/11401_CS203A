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

    //array = (int *) realloc(array, n * sizeof(int));
    
    
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
/* "output"
1 Index 0 -> Value: 1, Address: 0x5b1f0eb192a0
2 Index 1 -> Value: 2, Address: 0x5b1f0eb192a4
3 Index 2 -> Value: 3, Address: 0x5b1f0eb192a8
4 Index 3 -> Value: 4, Address: 0x5b1f0eb192ac
5 Index 4 -> Value: 5, Address: 0x5b1f0eb192b0
6 Index 5 -> Value: 6, Address: 0x5b1f0eb192b4
7 Index 6 -> Value: 7, Address: 0x5b1f0eb192b8
8 Index 7 -> Value: 8, Address: 0x5b1f0eb192bc
9 Index 8 -> Value: 9, Address: 0x5b1f0eb192c0
10 Index 9 -> Value: 10, Address: 0x5b1f0eb192c4
1 Index 0 -> Value: 1, Address: 0x5b1f0eb196e0
2 Index 1 -> Value: 2, Address: 0x5b1f0eb196e4
3 Index 2 -> Value: 3, Address: 0x5b1f0eb196e8
4 Index 3 -> Value: 4, Address: 0x5b1f0eb196ec
5 Index 4 -> Value: 5, Address: 0x5b1f0eb196f0
6 Index 5 -> Value: 6, Address: 0x5b1f0eb196f4
7 Index 6 -> Value: 7, Address: 0x5b1f0eb196f8
8 Index 7 -> Value: 8, Address: 0x5b1f0eb196fc
9 Index 8 -> Value: 9, Address: 0x5b1f0eb19700
10 Index 9 -> Value: 10, Address: 0x5b1f0eb19704
11 Index 10 -> Value: 11, Address: 0x5b1f0eb19708
12 Index 11 -> Value: 12, Address: 0x5b1f0eb1970c
13 Index 12 -> Value: 13, Address: 0x5b1f0eb19710
14 Index 13 -> Value: 14, Address: 0x5b1f0eb19714
15 Index 14 -> Value: 15, Address: 0x5b1f0eb19718
16 Index 15 -> Value: 16, Address: 0x5b1f0eb1971c
17 Index 16 -> Value: 17, Address: 0x5b1f0eb19720
18 Index 17 -> Value: 18, Address: 0x5b1f0eb19724
19 Index 18 -> Value: 19, Address: 0x5b1f0eb19728
20 Index 19 -> Value: 20, Address: 0x5b1f0eb1972c
*/

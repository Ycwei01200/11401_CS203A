#include <stdio.h>
#include <stdlib.h>
int n = 10,row=10;
int main(){
    int **array = (int**) malloc(n * sizeof(int*));
    
    for(int i = 0; i < n ; i++){
        array[i] = (int*) malloc(row * sizeof(int));
        for(int l = 0; l < row; l++){
            array[i][l] = l+1;
        }
        
    }
    for(int i = 0; i < n; i++){
        for (int l = 0; l < row; l++) {
            printf("%d ", array[i][l]);
            printf("Index %d -> Value: %d, Address: %p\n", i, array[i][l], (void*)&array[i][l]);
        }
        printf("\n");
    }
    /*
    n = n * 2;

    array = (int *) realloc(array, row * n * sizeof(int));

    for (int i = n/2; i < n; i++) {
        array[i] = i + 1;   // initialize new elements
    }
    */
    for(int i = 0; i < row; i++){
        free(array[i]);
    }
    free(array);
    array = NULL;
    
    
    return 0;
}
/*
[?2004l
1 Index 0 -> Value: 1, Address: 0x5b0a57548300
2 Index 0 -> Value: 2, Address: 0x5b0a57548304
3 Index 0 -> Value: 3, Address: 0x5b0a57548308
4 Index 0 -> Value: 4, Address: 0x5b0a5754830c
5 Index 0 -> Value: 5, Address: 0x5b0a57548310
6 Index 0 -> Value: 6, Address: 0x5b0a57548314
7 Index 0 -> Value: 7, Address: 0x5b0a57548318
8 Index 0 -> Value: 8, Address: 0x5b0a5754831c
9 Index 0 -> Value: 9, Address: 0x5b0a57548320
10 Index 0 -> Value: 10, Address: 0x5b0a57548324

1 Index 1 -> Value: 1, Address: 0x5b0a57548330
2 Index 1 -> Value: 2, Address: 0x5b0a57548334
3 Index 1 -> Value: 3, Address: 0x5b0a57548338
4 Index 1 -> Value: 4, Address: 0x5b0a5754833c
5 Index 1 -> Value: 5, Address: 0x5b0a57548340
6 Index 1 -> Value: 6, Address: 0x5b0a57548344
7 Index 1 -> Value: 7, Address: 0x5b0a57548348
8 Index 1 -> Value: 8, Address: 0x5b0a5754834c
9 Index 1 -> Value: 9, Address: 0x5b0a57548350
10 Index 1 -> Value: 10, Address: 0x5b0a57548354

1 Index 2 -> Value: 1, Address: 0x5b0a57548360
2 Index 2 -> Value: 2, Address: 0x5b0a57548364
3 Index 2 -> Value: 3, Address: 0x5b0a57548368
4 Index 2 -> Value: 4, Address: 0x5b0a5754836c
5 Index 2 -> Value: 5, Address: 0x5b0a57548370
6 Index 2 -> Value: 6, Address: 0x5b0a57548374
7 Index 2 -> Value: 7, Address: 0x5b0a57548378
8 Index 2 -> Value: 8, Address: 0x5b0a5754837c
9 Index 2 -> Value: 9, Address: 0x5b0a57548380
10 Index 2 -> Value: 10, Address: 0x5b0a57548384

1 Index 3 -> Value: 1, Address: 0x5b0a57548390
2 Index 3 -> Value: 2, Address: 0x5b0a57548394
3 Index 3 -> Value: 3, Address: 0x5b0a57548398
4 Index 3 -> Value: 4, Address: 0x5b0a5754839c
5 Index 3 -> Value: 5, Address: 0x5b0a575483a0
6 Index 3 -> Value: 6, Address: 0x5b0a575483a4
7 Index 3 -> Value: 7, Address: 0x5b0a575483a8
8 Index 3 -> Value: 8, Address: 0x5b0a575483ac
9 Index 3 -> Value: 9, Address: 0x5b0a575483b0
10 Index 3 -> Value: 10, Address: 0x5b0a575483b4

1 Index 4 -> Value: 1, Address: 0x5b0a575483c0
2 Index 4 -> Value: 2, Address: 0x5b0a575483c4
3 Index 4 -> Value: 3, Address: 0x5b0a575483c8
4 Index 4 -> Value: 4, Address: 0x5b0a575483cc
5 Index 4 -> Value: 5, Address: 0x5b0a575483d0
6 Index 4 -> Value: 6, Address: 0x5b0a575483d4
7 Index 4 -> Value: 7, Address: 0x5b0a575483d8
8 Index 4 -> Value: 8, Address: 0x5b0a575483dc
9 Index 4 -> Value: 9, Address: 0x5b0a575483e0
10 Index 4 -> Value: 10, Address: 0x5b0a575483e4

1 Index 5 -> Value: 1, Address: 0x5b0a575483f0
2 Index 5 -> Value: 2, Address: 0x5b0a575483f4
3 Index 5 -> Value: 3, Address: 0x5b0a575483f8
4 Index 5 -> Value: 4, Address: 0x5b0a575483fc
5 Index 5 -> Value: 5, Address: 0x5b0a57548400
6 Index 5 -> Value: 6, Address: 0x5b0a57548404
7 Index 5 -> Value: 7, Address: 0x5b0a57548408
8 Index 5 -> Value: 8, Address: 0x5b0a5754840c
9 Index 5 -> Value: 9, Address: 0x5b0a57548410
10 Index 5 -> Value: 10, Address: 0x5b0a57548414

1 Index 6 -> Value: 1, Address: 0x5b0a57548420
2 Index 6 -> Value: 2, Address: 0x5b0a57548424
3 Index 6 -> Value: 3, Address: 0x5b0a57548428
4 Index 6 -> Value: 4, Address: 0x5b0a5754842c
5 Index 6 -> Value: 5, Address: 0x5b0a57548430
6 Index 6 -> Value: 6, Address: 0x5b0a57548434
7 Index 6 -> Value: 7, Address: 0x5b0a57548438
8 Index 6 -> Value: 8, Address: 0x5b0a5754843c
9 Index 6 -> Value: 9, Address: 0x5b0a57548440
10 Index 6 -> Value: 10, Address: 0x5b0a57548444

1 Index 7 -> Value: 1, Address: 0x5b0a57548450
2 Index 7 -> Value: 2, Address: 0x5b0a57548454
3 Index 7 -> Value: 3, Address: 0x5b0a57548458
4 Index 7 -> Value: 4, Address: 0x5b0a5754845c
5 Index 7 -> Value: 5, Address: 0x5b0a57548460
6 Index 7 -> Value: 6, Address: 0x5b0a57548464
7 Index 7 -> Value: 7, Address: 0x5b0a57548468
8 Index 7 -> Value: 8, Address: 0x5b0a5754846c
9 Index 7 -> Value: 9, Address: 0x5b0a57548470
10 Index 7 -> Value: 10, Address: 0x5b0a57548474

1 Index 8 -> Value: 1, Address: 0x5b0a57548480
2 Index 8 -> Value: 2, Address: 0x5b0a57548484
3 Index 8 -> Value: 3, Address: 0x5b0a57548488
4 Index 8 -> Value: 4, Address: 0x5b0a5754848c
5 Index 8 -> Value: 5, Address: 0x5b0a57548490
6 Index 8 -> Value: 6, Address: 0x5b0a57548494
7 Index 8 -> Value: 7, Address: 0x5b0a57548498
8 Index 8 -> Value: 8, Address: 0x5b0a5754849c
9 Index 8 -> Value: 9, Address: 0x5b0a575484a0
10 Index 8 -> Value: 10, Address: 0x5b0a575484a4

1 Index 9 -> Value: 1, Address: 0x5b0a575484b0
2 Index 9 -> Value: 2, Address: 0x5b0a575484b4
3 Index 9 -> Value: 3, Address: 0x5b0a575484b8
4 Index 9 -> Value: 4, Address: 0x5b0a575484bc
5 Index 9 -> Value: 5, Address: 0x5b0a575484c0
6 Index 9 -> Value: 6, Address: 0x5b0a575484c4
7 Index 9 -> Value: 7, Address: 0x5b0a575484c8
8 Index 9 -> Value: 8, Address: 0x5b0a575484cc
9 Index 9 -> Value: 9, Address: 0x5b0a575484d0
10 Index 9 -> Value: 10, Address: 0x5b0a575484d4

[?2004h
    */

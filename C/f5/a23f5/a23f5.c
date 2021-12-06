#include <stdio.h>

int main(){
    
    int A[4], B[4], final[4][4], sum = 0;

    for (int i = 0; i < 4; i++){
        printf("Insert SetA num %d:", i);
        scanf("%d", &A[i]);
        sum = sum + A[i];
    }

    for (int i = 0; i < 4; i++){
        printf("Insert SetB num %d:", i);
        scanf("%d", &B[i]);
        sum = sum + B[i];
    }

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            final[i][j] = A[j] + B[i];
        }
    }

    printf("Sum: %d\n", sum);
    
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%6d", final[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
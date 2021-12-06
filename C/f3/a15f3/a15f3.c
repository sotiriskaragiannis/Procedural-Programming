#include <stdio.h>


int main(){

    for (int num = 1; num <= 100;){
        for (int i = 1; i <= 10; i++){
            printf("%4d", num);
            num++;
        }
        printf("\n");
    }

    return 0;
}

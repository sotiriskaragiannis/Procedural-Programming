#include <stdio.h>
#include "simpio.h"

int main(){

    int width, height;

    printf("Dose ypsos: ");
    height = GetInteger();
    printf("Dose platos: ");
    width = GetInteger();

    for (int i = 1; i <= height; i++){
        if ((i == 1) || (i == height)){
            for (int j = 1; j <= width; j++){
                printf("*");
            }
        }
        else {
            for (int j = 1; j <= width; j++){
                if ((j == 1) || (j == width)){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }


    return 0;
}

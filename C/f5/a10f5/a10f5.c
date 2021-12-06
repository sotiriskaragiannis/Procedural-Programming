#include <stdio.h>
#include "simpio.h"

int main(){

    long devices, num_of_boxes[4] = {0, 0, 0, 0}, capacity_of_boxes[4] = {1, 5, 20, 50};

    printf("Dwse plithos syskeuwn:");
     devices = GetInteger();

    if (devices >= 0){
    
     num_of_boxes[3] = devices / 50;
     devices = devices - (num_of_boxes[3] * 50);

     num_of_boxes[2] = devices / 20;
     devices = devices - (num_of_boxes[2] * 20);

     num_of_boxes[1] = devices / 5;
     devices = devices - (num_of_boxes[1] * 5);

     num_of_boxes[0] = devices;

    }

    for (int i = 0; i < 4; i++){
        printf("%2d %5d\n", capacity_of_boxes[i], num_of_boxes[i]);
    }
    return 0;
}


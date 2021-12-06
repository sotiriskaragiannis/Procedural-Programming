#include <stdio.h>
#include <math.h>
#include "simpio.h"


int main() {
    int estimated_time, real_time, acceptable_difference, difference_of_input_times;

    printf("Dose problepomeno xrono:");
    estimated_time = GetInteger();

    printf("Dose pragmatiko xrono:");
    real_time = GetInteger();

    difference_of_input_times = estimated_time - real_time;
    if (estimated_time <= 29) {
        acceptable_difference = 1;
    }
    else if ((estimated_time >= 30) && (estimated_time <= 59)) {
        acceptable_difference = 2;
    }
    else if ((estimated_time >= 60) && (estimated_time <= 89)) {
        acceptable_difference = 3;
    }
    else if ((estimated_time >= 90) && (estimated_time <= 119)) {
        acceptable_difference = 4;
    }
    else if ((estimated_time >= 120) && (estimated_time <= 179)) {
        acceptable_difference = 6;
    }
    else if ((estimated_time >= 180) && (estimated_time <= 239)) {
        acceptable_difference = 8;
    }
    else if ((estimated_time >= 240) && (estimated_time <= 359)) {
        acceptable_difference = 13;
    }
    else if (estimated_time >= 360) {
        acceptable_difference = 17;
    }

    printf("Apodekth diafora: %d\n", acceptable_difference);
    printf("Diafora eisodou: %d\n", difference_of_input_times);


    if (abs(difference_of_input_times) <= acceptable_difference){
        printf("GOOD");
    }
    else {
        if (real_time > estimated_time){
            printf("SMALL");
        }
        else if (real_time < estimated_time){
            printf("BIG");
        }
    }
    return 0;
}

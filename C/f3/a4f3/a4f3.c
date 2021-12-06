#include <stdio.h>
#include <math.h>
#include "simpio.h"

#define total_cost 20000
#define ticket_cost 350

int main(){
    int code = 1, num_of_people;
    long cost, profit, earnings = 0;

    while (code != 2){
        printf("Dwse kwdiko: ");
        code = GetInteger();

        if (code == 1){
            printf("Dwse arithmo atomwn: ");
            num_of_people = GetInteger();

            if (num_of_people <= 10){
                cost = num_of_people * ticket_cost;
            }
            else if (num_of_people > 10){
                cost = ceil(num_of_people * (ticket_cost * 0.9));
            }
            printf("Kostos: %ld\n", cost);
            earnings = earnings + cost;
            }
        if ((code != 1) && (code != 2)){
            printf("Lathos!\n");
        }

    }
    profit = earnings - total_cost;
    printf("Kerdos: %ld", profit);

    return 0;
}



#include <stdio.h>
#include "simpio.h"

int main(){
    int numof50containers, numof20containers, numof5containers, numof1containers, plithosSyskeuwn;

    printf("Dose plithos syskeuwn:");
     plithosSyskeuwn = GetInteger();

     numof50containers = plithosSyskeuwn / 50;
     printf("50 %d\n", numof50containers);
     plithosSyskeuwn = plithosSyskeuwn - (numof50containers * 50);

     numof20containers = plithosSyskeuwn / 20;
     printf("20 %d\n", numof20containers);
     plithosSyskeuwn = plithosSyskeuwn - (numof20containers * 20);

     numof5containers = plithosSyskeuwn / 5;
     printf("5 %d\n", numof5containers);
     plithosSyskeuwn = plithosSyskeuwn - (numof5containers * 5);

     numof1containers = plithosSyskeuwn;
     printf("1 %d\n", numof1containers);

    return 0;
}

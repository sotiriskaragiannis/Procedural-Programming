#include <stdio.h>
#include "simpio.h"

int main(){

    int varos, upsos, ilikia;
    double bmr;

    printf("Dwse varos se klia: ");
    varos = GetInteger();

    printf("Dwse upsos se cm: ");
    upsos = GetInteger();

    printf("Dwse ilikia se xronia: ");
    ilikia = GetInteger();

    bmr = 655 + (9.6 * varos) + (1.8 * upsos) - (4.7 * ilikia);

    printf("To BMR einai: %g", bmr);
    return 0;
}

#include <stdio.h>
#include "simpio.h"

int main(){
    float dt, df, katharaTm, miktaTm;

    printf("Dose kathara tm: ");
    katharaTm = GetReal();

    printf("Dose mikta tm: ");
    miktaTm = GetReal();

    dt = (katharaTm  * 1.33 * 61) / 365;
    df = (miktaTm * 0.13 * 61) / 365;

    printf("DT: %.2f \n", dt);
    printf("DF: %.2f \n", df);

    return 0;
}

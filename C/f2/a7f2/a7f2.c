#include <stdio.h>
#include "simpio.h"

int main(){

    long kwdikos;
    int wres;
    double amoibh_ana_wra, ebdomadiaia_amoibh, ethsios_misthos;

    printf("Dwse ton kwdiko:");
    kwdikos = GetLong();

    if (kwdikos >= 1000) {
        printf("Dwse ton ethsio mistho:");
        ethsios_misthos = GetReal();
        ebdomadiaia_amoibh = ethsios_misthos / 52.0;
    }
    else {
        printf("Dwse tis wres ebdomadiaias ergasias:");
        wres = GetInteger();
        printf("Dwse thn amoibh ana wra:");
        amoibh_ana_wra = GetReal();
        if (wres > 40) {
            ebdomadiaia_amoibh = 40 * amoibh_ana_wra + (wres - 40) * amoibh_ana_wra * 1.5;
        }
        else {
            ebdomadiaia_amoibh = wres * amoibh_ana_wra;
        }

    }

    printf("H ebdomadiaia amoibh einai %g", ebdomadiaia_amoibh);


}

#include <stdio.h>
#include "simpio.h"



int main(){
    int wres;
    long wriaiaAntimisthia;
    double posostoKrathsewn, akatharistesApodoxes, krathseis, katharesApodoxes;

    printf("Dwse ton arithmo twn wrwn: ");
    wres = GetInteger();

    printf("Dwse thn wriaia antimisthia: ");
    wriaiaAntimisthia = GetLong();

    printf("Dwse to pososto twn krathsewn: ");
    posostoKrathsewn = GetReal();

    katharesApodoxes = wres *  wriaiaAntimisthia;
    krathseis = katharesApodoxes * posostoKrathsewn;
    akatharistesApodoxes = katharesApodoxes + krathseis;

    printf("Oi akatharistes apodoxes einai %g\n", akatharistesApodoxes);
    printf("Oi krathseis einai %g\n", krathseis);
    printf("Oi kathares apodoxes einai %g\n", katharesApodoxes);

    return 0;
}


#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

void ReadCoefficients(int coefficients[], int degree);
void PrintPolynomial(int coefficients[], int degree);
void SumPolynomial(int coefficientsSum[], int coefficientsA[], int coefficientsB[], int degree);
double ValueCalculation(int coefficients[], int degree, double x);

int main(){

    int degree;
    int coefficientsA[10], coefficientsB[10], coefficientsSum[10];
    double x, value1, value2, valueSum;

    //Ανάγνωση βαθμού πολυωνύμων
    printf("Ti vathmo exoyn ta polywnyma?\n");
    degree = GetInteger();

    ReadCoefficients(coefficientsA, degree);
    PrintPolynomial(coefficientsA, degree);
    ReadCoefficients(coefficientsB, degree);
    PrintPolynomial(coefficientsB, degree);
    SumPolynomial(coefficientsSum, coefficientsA, coefficientsB, degree);
    PrintPolynomial(coefficientsSum, degree);

    printf("Dwse mia timi gia to x: ");
    x = GetReal();

    value1 = ValueCalculation(coefficientsA, degree, x);
    value2 = ValueCalculation(coefficientsB, degree, x);
    valueSum = ValueCalculation(coefficientsSum, degree, x);

    printf("Value1: %g  Value2: %g  Value of Sum: %g", value1, value2, valueSum);
}

 //Ανάγνωση συντελεστών πολυωνύμου
void ReadCoefficients(int coefficients[], int degree){
    for(int i = 0; i <= degree; i++) {
        printf("Eisagete to syntelesti tou orou %d: ", i);
        coefficients[i] = GetInteger();
    }
}

//Εκτύπωση πρώτου πολυωνύμου
void PrintPolynomial(int coefficients[], int degree){    
    int i = degree;
    while(i>=1) { 
        printf("%dx^%d + ", coefficients[i], i);
        i--;
    }
    printf("%d\n", coefficients[0]);
}

//Πρόσθεση πολυωνύμων
void SumPolynomial(int coefficientsSum[], int coefficientsA[], int coefficientsB[], int degree){
    for(int i=0; i<=degree; i++) {
        coefficientsSum[i] = coefficientsA[i] + coefficientsB[i];
    }
}

double ValueCalculation(int coefficients[], int degree, double x){
    double value = 0;
    for(int i = 0; i <= degree; i++)
        value += coefficients[i]*pow(x, (double)i);
    
    return value;
}
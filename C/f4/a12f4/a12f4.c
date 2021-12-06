#include <stdio.h>
#include <math.h>

int check_decimals(double num, double x);
int Parag(int num);
double calculate_sinx(double x);

int main(){
    double x, sinx = 0;

    printf("Dwse to x se aktinia: ");
    scanf("%lf", &x);


    
    sinx = calculate_sinx(x);
    printf("sinx: %12.10lf", sinx);

    return 0;
}

double calculate_sinx(double x){
    int n, fact, sign = - 1, count = 0;
    double p, sinx = 0;
    for (int i = 1; i <= 11; i += 2)
    {
        n = i;
        p = 1;
        for (int j = 1; j <= i; j++)
        {
        p = p * x;
        
        }
        sign =  - 1 * sign;
        sinx += sign * p / Parag(i);
        if (check_decimals(sinx, x)){
            if (count){
                break;
            }
            else{
                count++;
            }
        }
    }
    printf("n: %d\n", n);
    return sinx;
}

int Parag(int num){
    int fact = 1;
    for (int i = 1; i <= num; i++){
        fact = fact * i;
    }
    return fact;
}

int check_decimals(double sinx, double x){
    double diff;
    diff = fabs(sinx - sin(x));
    if (diff < 0.0001){
        return 1;
    }
    return 0;
}

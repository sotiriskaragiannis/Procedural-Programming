#include <stdio.h>
#include <math.h>


int add(int x, int y);

int sub(int x, int y);

int mult(int x, int y);

int divd(int x, int y);

int exp1(int x, int y);

int ex2(int x, int y);

int main(){
    int x, y, tmp;

    printf("Dwse ton 1o arithmo: ");
    scanf("%d", &x);
    printf("Dwse ton 2o arithmo: ");
    scanf("%d", &y);
    while (y == 0){
        printf("Den mporeis na diaireseis me to 0!\n");
        printf("Dwse ton 2o arithmo: ");
        scanf("%d", &y);
    }
    tmp = add(x, y);
    printf("add: %d\n", tmp);
    tmp = sub(x, y);
    printf("sub: %d\n", tmp);
    tmp = mult(x, y);
    printf("mult: %d\n", tmp);
    tmp = divd(x, y);
    printf("divd: %d\n", tmp);
    tmp = exp1(x, y);
    printf("exp1: %d\n", tmp);
    tmp = ex2(x, y);
    
    
    printf("exp2: %d\n", tmp);

    return 0;
}

int add(int x, int y){
    return x + y;
}

int sub(int x, int y){
    return x - y;
}

int mult(int x, int y){
    return x * y;
}

int divd(int x, int y){
    return x / y;
}

int exp1(int x, int y){
    return mult(add(x,y), sub(y, divd(x,y)));
}

int ex2(int x, int y){
    return divd(sub(mult(x,y), x), add(x, y));
}




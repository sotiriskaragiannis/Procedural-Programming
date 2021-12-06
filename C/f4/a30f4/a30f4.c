#include <stdio.h>
#include <math.h>

int calc(int a, int b, int c);

int main(){
    int n, sum = 0;    
    printf("Dwse n: ");
    scanf("%d", &n);

for (int i = 1; i <= 3; i++){
    for (int j = 1; j <= n; j++){
        for (int k = 1; k <= n; k++){
            sum = sum + calc(i,j,k);
        }
    }
}    

    printf("Result: %d", sum);

    return 0;
}

int calc(int a, int b, int c){
    
    if (a == 1){
        return b + c;
    }
    if (a == 2){
        return b - c;
    }
    if (a == 3){

            return floor((b + c) / 2);
        
    }
    return 0;
}

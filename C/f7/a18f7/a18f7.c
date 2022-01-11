#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringToInteger(char str[]);

int main(){
    char lesson[10], coef[3], mark[3], input[30];
    int index, mark_int, coef_int;
    float final_mark;

    printf("Please insert course info (name/coef/mark): ");
    gets(input);

    index = 0;
    while (input[index] != '/'){
        index++;
    }
    
    
    if (index > 9){
        printf("Error! Name should not be more that 9 chars\n");
    }
    else{
        strncpy(lesson, input, index);
        lesson[index] = '\0';

        strncpy(coef, input+index+1, 2);
        coef[2] = '\0';

        strncpy(mark, input+index+4, 2);
        mark[2] = '\0';

        printf("lesson: %s\n", lesson);
        printf("coef: %s\n", coef);
        printf("makr: %s\n", mark);

        mark_int = stringToInteger(mark);
        coef_int = stringToInteger(coef);
        final_mark = mark_int * coef_int / 100.0;

        printf("final mark: %.2f\n", final_mark);

    }

    return 0;
}

int stringToInteger(char str[]){
    int num;
    num = atoi(str);
    return num;
}


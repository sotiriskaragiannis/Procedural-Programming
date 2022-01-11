#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENTS 5

int main(){
    char names[STUDENTS][20], input_char;
    int count = 0, i;

    for (i = 0; i < STUDENTS; i++){
        printf("Give name %d :", i);
        gets(names[i]);
    }

    printf("\nGive initial char:");
    input_char = getchar();

    for (i = 0; i < STUDENTS; i++){
        if (names[i][0] == input_char){
            count++;
        }
    }

    printf("Names starting with %c are: %d\n", input_char, count);

    for (i = 0; i < STUDENTS; i++){
        if (names[i][0] == input_char){
            printf("%s\n", names[i]);
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STUDENTS 30
#define SUBJECTS 3

void RandomFill(int rows, int cols, int array[rows][cols]);
void AverageCols(int rows, int cols, int array[rows][cols], float average[]);
void PrintGrades(int rows, int cols, int array[rows][cols], float average[]);
void Percentage(int size, float average[], int *failed_students, int *excellent_students, float *failed_perc, float *excell_perc);

int main(){
    
    int grades[STUDENTS][SUBJECTS];
    float average[STUDENTS];
    int failed_students, excellent_students;
    float failed_perc, excell_perc;



    RandomFill(STUDENTS, SUBJECTS, grades);
    AverageCols(STUDENTS, SUBJECTS, grades, average);
    PrintGrades(STUDENTS, SUBJECTS, grades, average);
    Percentage(STUDENTS, average, &failed_students, &excellent_students, &failed_perc, &excell_perc);



    printf("Apotyxontes: %d\n", failed_students);
    printf("Pososto apotyxonton: %5.2f%%\n", failed_perc);
    printf("Aristouxoi: %d\n", excellent_students);
    printf("Pososto aristouxwn: %5.2f%%\n", excell_perc);
    return 0;
}


void RandomFill(int rows, int cols, int array[rows][cols]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            array[i][j] = rand() % 20;
        }
    }
}

void AverageCols(int rows, int cols, int array[rows][cols], float average[]){
    float sum;
    for (int i = 0; i < rows; i++){
        sum = 0;
        for (int j = 0; j < cols; j++){
            sum = sum + array[i][j];
        }
        average[i] = sum / cols;
    }
}

void PrintGrades(int rows, int cols, int array[rows][cols], float average[]){
    for (int i = 0; i < rows; i++){
        printf("%2d:", i+1);
        for (int j = 0; j < cols; j++){
            printf("%3d", array[i][j]);
        }
        printf(" :%5.2f\n", average[i]);
    }
}


void Percentage(int size, float average[], int *failed_students, int *excellent_students, float *failed_perc, float *excell_perc){
    *failed_students = 0;
    *excellent_students = 0;

    for (int i = 0; i < size; i++){
        if (average[i] < 9.5){
            (*failed_students)++;
        }
        if (average[i] >= 18.5){
            (*excellent_students)++;
        }
    }
    *failed_perc = (*failed_students / 30.0) * 100.0;
    *excell_perc = (*excellent_students / 30.0) * 100.0;
}
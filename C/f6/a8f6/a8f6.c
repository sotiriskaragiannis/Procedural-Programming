#include <stdio.h>
#include <simpio.h>

#define STUDENTS 30
#define GRADE 20

void FillArray(int size, int array[]);
void FindFrequency(int size, int array[], int size2, int freq_array[]);
void FindMax(int size, int array[], int *max, int *grade);
void FindMin(int size, int array[], int *min, int *grade);
void PrintFrequencies(int size, int array[], int max_grade, int freq_of_max, int min_grade, int freq_of_min);

int main(){
    int grades[STUDENTS], grade_frequency[GRADE], max_grade, freq_of_max, min_grade, freq_of_min;

    FillArray(STUDENTS, grades);
    FindFrequency(STUDENTS, grades, GRADE, grade_frequency);
    FindMax(GRADE, grade_frequency, &freq_of_max, &max_grade);
    FindMin(GRADE, grade_frequency, &freq_of_min, &min_grade);
    PrintFrequencies(GRADE, grade_frequency, max_grade, freq_of_max, min_grade, freq_of_min);

    return 0;
}

void FillArray(int size, int array[]){
    for (int i = 0; i < size; i++){
        printf("Dwse bathmo %d: ", i+1);
        array[i] = GetInteger();
    }
}

void FindFrequency(int size, int array[], int size2, int freq_array[]){
    for (int i = 0; i < size2; i++){
        freq_array[i] = 0;
    }
    for (int j = 0; j < size; j++){
        freq_array[array[j]-1]++;
    }
}

void FindMax(int size, int array[], int *max, int *grade){
    // Initialize maximum element
    *max = array[0];
    *grade = 1;
    // Traverse array elements from second and
    // compare every element with current max 
    for (int i = 0; i < size; i++){
        
        if (*max < array[i]){
            *max = array[i];
            *grade = i + 1; // Save the position of the maximum, because that is going
        }                 // to show what is the time with the most bands in the party
    }
    
}

void FindMin(int size, int array[], int *min, int *grade){
    *min = array[0];
    *grade = 1;

    for (int i = 1; i < size; i++){
        
        if (array[i] < *min){
            *min = array[i];
            *grade = i + 1;
        }                
    }
}

void PrintFrequencies(int size, int array[], int max_grade, int freq_of_max, int min_grade, int freq_of_min){

    printf("Syxnotites bathmwn\n");
    for (int i = 0; i < size; i++){
        printf("%d: %d\n", i+1, array[i]);
    }

    printf("Bathmos me th megalyteri syxnotita: %d\n", max_grade);
    printf("Syxnotita: %d\n", freq_of_max);
    printf("Bathmos me th mikroteri syxnotita: %d\n", min_grade);
    printf("Syxnotita: %d\n", freq_of_min);
}

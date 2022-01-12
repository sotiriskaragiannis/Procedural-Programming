#include <stdio.h>

#define FRIENDS 13

int position_of_max(int size, int arr[size]);

int main(){
    int relations[FRIENDS][FRIENDS] = {{0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},                 // A matrix that represents the connections of a graph that connects people that hate each other.
                                       {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                 // The purpose of the program is to find the maximum number of people that are going to be in a party, so 
                                       {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},                 // that everyone will get along. It will also print the names of those people.
                                       {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                       {0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0},
                                       {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0},
                                       {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}};
    int present[FRIENDS] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // Array that has 1 if the friend is coming to the party and 0 if they aren't. It also works as an index for the names array.
    char names[FRIENDS][20] = {"Nikos", "Lydia", "Eva", "Petros", "Giannis", "Manos", "Eleni", "Akis", "Maria", "Dimitris", "Zoe", "Alexandros", "Anna"};
    int sums[FRIENDS]; // Array that will have the sum of the ones in each row of the relations matrix. 
    int sum_of_sums = 1; // This will be 0 once there are no "active" 1 in the relations matrix.
    int temp_max, total_friends = 0;

    while (sum_of_sums != 0){
        for (int i = 0; i < FRIENDS; i++){
            sums[i] = 0;
            if (present[i] == 1){
                for (int j = 0; j < FRIENDS; j++){
                    if (present[j] == 1){                     // Calculate the sum only for people that are present.
                        sums[i] = sums[i] + relations[i][j];  // Calculate the sum of every row of the 2d matrix and save the results in a 1d array. 
                    }
                }
            }
            
        }
        
        temp_max = position_of_max(FRIENDS, sums);      // Finds the max of the array and then eliminates from the 'present' array.
        present[temp_max] = 0;
        sum_of_sums = 0;
        for (int i = 0; i < FRIENDS; i++){
            if (present[i] == 1){                       // Calculate the sum only for people that are present.
                sum_of_sums = sum_of_sums + sums[i];    // If the sum is positive, then there are still present people that dont get along together.
            }   
        }
        
    }

    for (int i = 0; i < FRIENDS; i++){
        total_friends = total_friends + present[i];  // Calculate the total friends that are coming to the party, simply by the sum of the array 'present'
        }
    printf("Total Friends: %d\n", total_friends);
    printf("These people will attend your party: ");
    for (int i = 0; i < FRIENDS; i++){
        if (present[i] == 1){                   // Print the names of the people that are coming based on the indexes in the 'present' array.
            printf("%s, ", names[i]);
        }
    } 
    
    return 0;

}


int position_of_max(int size, int arr[size]){
    
    // Initialize maximum element
    int position = 0;
    int max = arr[position];
    
    // Traverse array elements from second and
    // compare every element with current max 
    for (int i = 0; i < size; i++){
        
        if (max < arr[i]){
            max = arr[i];
            position = i; // Save the position of the maximum, because that is going
        }                 // to show what is the time with the most bands in the party
    }
    return position;
}


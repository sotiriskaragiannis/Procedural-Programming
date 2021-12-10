#include <stdio.h>
#include <string.h>

int position_of_max(int size, int arr[size]);

int main(){
    int N, Sums[6];

    printf("Enter the number of the bands: ");
    scanf("%d", &N);

    char Names[N][30], temp;
    int Times_of_Arrival[N], Times_of_Departure[N], time, M[N][6];

    //int Times_of_Arrival[] = {20, 22, 19, 18, 20, 19, 19, 21, 18, 20, 20, 19, 20, 22, 18, 18, 23, 22, 19, 21, 22, 20, 22, 19, 18, 18, 20};
    //int Times_of_Departure[] = {23, 24, 20, 22, 23, 21, 20, 23, 21, 22, 21, 21, 22, 23, 21, 22, 24, 24, 24, 22, 24, 23, 24, 23, 20, 19, 21};

    for (int i = 0; i < N; i++){
        printf("Enter the name of a band: ");
        scanf("%c",&temp);
        gets(Names[i]);
        printf("Enter the time of arrival of %s: ", Names[i]);
        scanf("%d", &Times_of_Arrival[i]);
        printf("Enter the time of departure of %s: ", Names[i]);
        scanf("%d", &Times_of_Departure[i]);
    }


    for (int i = 0; i < N; i++){
        
        M[i][0] = (Times_of_Arrival[i] == 18) ?  1 :  0;
        M[i][1] = ((Times_of_Arrival[i] <= 19) && (Times_of_Departure[i] >= 20)) ?  1 :  0;  // Add a 1 or a 0 based on which hours is every band in the party
        M[i][2] = ((Times_of_Arrival[i] <= 20) && (Times_of_Departure[i] >= 21)) ?  1 :  0;
        M[i][3] = ((Times_of_Arrival[i] <= 21) && (Times_of_Departure[i] >= 22)) ?  1 :  0;
        M[i][4] = ((Times_of_Arrival[i] <= 22) && (Times_of_Departure[i] >= 23)) ?  1 :  0;
        M[i][5] = (Times_of_Departure[i] == 24) ?  1 :  0;
        
       
    }


    for (int j = 0; j < 6; j++){
        Sums[j] = 0;
        for (int i = 0; i < N; i++){
            Sums[j] = Sums[j] + M[i][j];
            
        }
    }

    int index_of_max = position_of_max(6, Sums);
    
    time = index_of_max + 18;
    printf("You should go to the concert at %d - %d and you will see %d bands.", time, time+1, Sums[index_of_max]);

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



	

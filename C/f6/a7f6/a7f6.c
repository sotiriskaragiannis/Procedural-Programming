#include <stdio.h>

#define CITIES_GR 5
#define CITIES_CY 2
#define PRICE_GR 7.5
#define PRICE_CY 8.5
#define MONTHS 3

void monthly_earnings(int rows, int cols, float array[rows][cols], float price_of_ticket);
void cities_average(int rows, int cols, float earnings[rows][cols], float city_average[rows]);
void monthly_average(int rows, int cols, float earnings[rows][cols], float month_average[cols]);
void minimum_revenue(int rows, int cols, float earnings[rows][cols], float *min, int *city, int *month);
void print_earnings(int rows, int cols, float earnings[rows][cols]);
void print_statistics(int cities, int months, float city_average[cities], float month_average[months],float min,int min_city,int min_month);

int main(){
    float earnings_gr[CITIES_GR][MONTHS], earnings_cy[CITIES_CY][MONTHS], city_average_gr[CITIES_GR], city_average_cy[CITIES_CY];
    float month_average_gr[MONTHS], month_average_cy[MONTHS], min_gr, min_cy;
    int min_city_gr, min_city_cy, min_month_gr, min_month_cy;

    printf("Tickets in Greece\n");
    monthly_earnings(CITIES_GR, MONTHS, earnings_gr, PRICE_GR);          // Calculate the monthlty earnings for each city in Greece. 
    printf("Tickets in Cyprus\n");
    monthly_earnings(CITIES_CY, MONTHS, earnings_cy, PRICE_CY);          // Calculate the monthlty earnings for each city in Cyprus.

    printf("\n");
    
    cities_average(CITIES_GR, MONTHS, earnings_gr, city_average_gr);     // Calculate the average earnings for each city in Greece.
    cities_average(CITIES_CY, MONTHS, earnings_cy, city_average_cy);     // Calculate the average earnings for each city in Cyprus.

    monthly_average(CITIES_GR, MONTHS, earnings_gr, month_average_gr);   // Calculate the average earnings for each month in Greece.
    monthly_average(CITIES_CY, MONTHS, earnings_cy, month_average_cy);   // Calculate the average earnings for each month in Cyprus.

    minimum_revenue(CITIES_GR, MONTHS, earnings_gr, &min_gr, &min_city_gr, &min_month_gr);   // Calculate the minimum revenue of Greece.
    minimum_revenue(CITIES_CY, MONTHS, earnings_cy, &min_cy, &min_city_cy, &min_month_cy);   // Calculate the minimum revenue of Cyprus.

    printf("Cinema revenues in Greece\n");
    print_earnings(CITIES_GR, MONTHS, earnings_gr);                      // Print the all specific earnings of Greece.
    
    printf("\n");

    printf("Statistics in Greece\n");
    print_statistics(CITIES_GR, MONTHS, city_average_gr, month_average_gr, min_gr, min_city_gr, min_month_gr);      // Print statistics for Greece.
    
    printf("\n");

    printf("Cinema revenues in Cyprus\n");
    print_earnings(CITIES_CY, MONTHS, earnings_cy);                      // Print the all specific earnings of Cyprus.

    printf("\n");

    printf("Statistics in Cyprus\n");
    print_statistics(CITIES_CY, MONTHS, city_average_cy, month_average_cy, min_cy, min_city_cy, min_month_cy);      // Print statistics for Cyprus.

    return 0;
}

void monthly_earnings(int rows, int cols, float array[rows][cols], float price_of_ticket){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Give tickets: [%d][%d]: ", i, j);    
            scanf("%f", &array[i][j]);                  // Read the number of tickets for every room/city.
            array[i][j] = array[i][j] * price_of_ticket; // Calculate and save the total earnings for each room/city.
        }
    }
}

void cities_average(int rows, int cols, float earnings[rows][cols], float city_average[rows]){
    for (int i = 0; i < rows; i++){
        float sum = 0;
        for (int j = 0; j < cols; j++){         // Calculate the average of each row of a 2d array.
            sum = sum + earnings[i][j];
        }
        city_average[i] = sum / cols;
    } 
}

void monthly_average(int rows, int cols, float earnings[rows][cols], float month_average[cols]){
    for (int i = 0; i < cols; i++){
        float sum = 0;
        for (int j = 0; j < rows; j++){         // Calculate the average of each collumn of a 2d array.
            sum = sum + earnings[j][i];
        }
        month_average[i] = sum / rows;
    }
}

void minimum_revenue(int rows, int cols, float earnings[rows][cols], float *min, int *city, int *month){
    *min = earnings[0][0];
    *city = 0;
    *month = 0;
    
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (earnings[i][j] < *min){
                *min = earnings[i][j];
                *city = i;
                *month = j;
            }
        }
    }
}

void print_earnings(int rows, int cols, float earnings[rows][cols]){
    for (int i = 0; i < rows; i++){
        printf("City %d:  ", i);
        for (int j = 0; j < cols; j++){
            printf(" %6.2f", earnings[i][j]);
        }
        printf("\n");
    }
}

void print_statistics(int cities, int months, float city_average[cities], float month_average[months],float min,int min_city,int min_month){
    printf("Cities average revenues\n");
    for (int i = 0; i < cities; i++){
        printf("%d: %6.2f\n", i, city_average[i]);
    }
    printf("Months average revenues\n");
    for (int i = 0; i < months; i++){
        printf("Month %d: %6.2f\n", i, month_average[i]);
    }
    printf("Min revenue: %6.2f\n", min);
    printf("City: %d\n", min_city);
    printf("Month: %d\n", min_month);

}
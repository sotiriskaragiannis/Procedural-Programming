#include <stdio.h>
#include "genlib.h"

int Valid_Date(int day, int month, int year, int current_year);
long Read_and_Calculate(int current_year);
bool Is_Leap_Year(int year);

int main(){
    int day, month, year, current_year;
    long fpa;

    printf("Current year: ");
    scanf("%d", &current_year);
    fpa = Read_and_Calculate(current_year);

    printf("SYNOLO FPA: %ld", fpa);

    return 0;
}



int Valid_Date(int day, int month, int year, int current_year){
    if (year != current_year){
        return 0;
    }
    if (day == 31){
        if ((month == 2) || (month == 4) || (month == 6) || (month == 9) || (month == 11)){
                return 0;
        }
    }
    if ((day == 30) && (month == 2)){
        return 0;
    }
    if (((day == 29) &&  (month == 2)) && (!Is_Leap_Year(year))){
        return 0;
    }
    
    if ((day < 1) || (day > 31)){
        return 0;
    }
    if ((month < 1) || (month > 12)){
        return 0;
    }
    return 1;
}

long Read_and_Calculate(int current_year){
    int year, month, day;
    long fpa, sum_fpa = 0;
    printf("Day: ");
    scanf("%d", &day);
    while (day != -1){
        printf("Month: ");
        scanf("%d", &month);
        printf("Year: ");
        scanf("%d", &year);
        printf("FPA: ");
        scanf("%d", &fpa);
        if (Valid_Date(day, month, year, current_year)){
             sum_fpa = sum_fpa + fpa;
        }
        printf("Day: ");
        scanf("%d", &day);
    }

    return sum_fpa;
}

bool Is_Leap_Year(int year)
{
	return ( ((year % 4 == 0) && (year % 100 !=0)) || (year % 400 == 0) );
}
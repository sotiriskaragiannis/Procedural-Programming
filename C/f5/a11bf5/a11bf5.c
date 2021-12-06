#include <stdio.h>
#include <math.h>
#include "simpio.h"

#define CTS 10
#define S 3

void ReadData(int row, int col, double temper[row][col]);
double CalculateAverage(int row, int col, double temper[row][col]);
void CalculateAv(int row, int col, double temper[row][col], double average[row]);
void CalculateMaxDeviaion(int row, int col, double temper[row][col], double mdeviation[row], double natavg);
void Print_results(int row, double average[], double mdeviation[], double natavg);

int main(){

    double temper[CTS][S];
    double average[CTS], mdeviation[CTS];
    double natavg;

    ReadData(CTS, S, temper);

    natavg = CalculateAverage(CTS, S, temper);
    CalculateAv(CTS, S, temper, average);
    CalculateMaxDeviaion(CTS, S, temper,mdeviation,natavg);
    Print_results(CTS,average, mdeviation, natavg);


    return 0;
}

/*Read all Temperatures*/
void ReadData(int row, int col, double temper[row][col]){
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
            printf("Temp of City %d During %d 8-hour period: ",i,j);
            temper[i][j] = GetReal();
        }
	}
}

/*Calculating The Average of all Cities&Temps*/
double CalculateAverage(int row, int col, double temper[row][col]){
    double natavg = 0;
    for (int i=0; i<row; i++)
      for (int j=0; j<col; j+=1)
         natavg += temper[i][j];
    natavg = natavg/(row*col);
    return natavg;
}

/*Calculating Average temp on each City*/
void CalculateAv(int row, int col, double temper[row][col], double average[row]){
	for (int i=0; i<row; i++)
    {
        average[i] = 0;
        for (int j=0; j<col; j++)
        {
            average[i] += temper[i][j];
        }
        average[i] = average[i]/col;
    }
}

void CalculateMaxDeviaion(int row, int col, double temper[row][col], double mdeviation[row], double natavg){
    double devnat[row][col];
    /*Calculating Standard Deviation*/
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            devnat[i][j] = fabs(natavg-temper[i][j]);
        }
    }
	/*Calculating max Deviation*/
    for (int i=0; i<row; i++)
    {
        mdeviation[i] = devnat[i][0];
        for(int j=1; j<col; j++)
            if (mdeviation[i]<devnat[i][j]) mdeviation[i] = devnat[i][j];
    }
}


/*Printing results*/
void Print_results(int row, double average[], double mdeviation[], double natavg){
    
    printf("%3.1f\n", natavg);
    for (int i=0; i<row; i+=1)
		printf("City %d  %.1f  %.1f\n",i, average[i], mdeviation[i]);
    
}
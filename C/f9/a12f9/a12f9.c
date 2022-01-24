#include <stdio.h>
#include <stdlib.h>
#include <genlib.h>

#define max_taxed 100

typedef struct {
    long ssn;
    char name[29];
    float income;
    float tax;
} taxedT;

int readDataFromFile(FILE *infile, taxedT array[]);
float calculateTax(int size, taxedT array[]);
void writeToFile(FILE *outfile, int size, taxedT array[], float total);

int main(){
    FILE *infile, *outfile;
    taxedT taxed[max_taxed];
    int size;
    float total;
    
    
    infile = fopen("i12f9.dat", "r");
    if (infile == NULL){
        printf("Cant open file i12f9.dat!\n");
        exit(1);
    }
    outfile = fopen("Foro12f9.dat", "w");

    size = readDataFromFile(infile, taxed);
    total = calculateTax(size, taxed);
    writeToFile(outfile, size, taxed, total);

    fclose(infile);
    fclose(outfile);
    return 0;
}

int readDataFromFile(FILE *infile, taxedT array[]){
    int income, nscan, line;
    char name[30], termc;
    long ssn;

    line = 0;
    while (TRUE){
        nscan = fscanf(infile, "%ld,%28[^,],%f%c", &array[line].ssn, array[line].name, &array[line].income, &termc);
        if (nscan == EOF){
            break;
        }

        if (nscan != 4 || termc != '\n'){
        printf("Error in line %d. Program termination\n", line);
        exit(1);
        }

        //printf("Line %d: %ld %s %.2f \n",line, array[line].ssn, array[line].name, array[line].income);
        line++;
    }
    return line;
}

float calculateTax(int size, taxedT array[]){
    float total = 0;
    int i;
    for (i = 0; i < size; i++){
        if (array[i].income <= 10000){
            array[i].tax = array[i].income * 0.14;
        }
        else if (array[i].income <= 23000){
            array[i].tax = array[i].income * 0.19;
        }
        else if (array[i].income <= 55000){
            array[i].tax = array[i].income * 0.23;
        }
        else if (array[i].income > 55000){
            array[i].tax = array[i].income * 0.28;
        }
        total = total + array[i].tax;
    }
    return total;
}

void writeToFile(FILE *outfile, int size, taxedT array[], float total){
    int i;
    fprintf(outfile, "%-10s%-30s%-7s\n", "AFM", "ONOMATEPWNYMO", "FOROS");
    for (i = 0; i < 47; i++){
        fputc('-', outfile);
    }
    fputc('\n', outfile);

    for (i = 0; i < size; i++){
        fprintf(outfile, "%-10ld%-29s%8.2f\n", array[i].ssn, array[i].name, array[i].tax );
    }

    for (i = 0; i < 47; i++){
        fputc('-', outfile);
    }
    fputc('\n', outfile);
    fprintf(outfile, "%-12s%35.2f", "SYNOLO FOROY", total);
}
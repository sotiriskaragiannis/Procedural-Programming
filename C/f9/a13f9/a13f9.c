#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

typedef struct {
    char name[41];
    long int balance;
    float epitokio;
    int date;
} customerT;

int readInput(customerT array[], FILE *infile);
void find_differences(customerT array_new[], customerT array_old[], int size_new, int size_old);
int calculateExpectedTax(customerT array[], int size);
void mztfgm(FILE *outfile, customerT array[], int size);
int findMax(customerT array[], int size);

int main(){
    FILE *infile_new, *infile_old, *outfile;
    customerT array_new[MAX_CUSTOMERS], array_old[MAX_CUSTOMERS];
    int num_new, num_old, index_of_max_new, index_of_max_old;
    double tax_new, tax_old;

    infile_new = fopen("bank_new.dat", "r");
    infile_old = fopen("bank_old.dat", "r");
    outfile = fopen("mztfgm.dat", "w");

    if ((infile_new == NULL) || (infile_old == NULL)){ // check if input files exist.
        printf("Error with the input files!\n");
        exit(1);
    }

    num_new = readInput(array_new, infile_new);  // reads data from input files to two individual structure arrays.
    num_old = readInput(array_old, infile_old);

    printf("Clients in List New not in Old\n");
    find_differences(array_new, array_old, num_new, num_old); // finds the clients that are listed in new, that are not listed in old.

    mztfgm(outfile, array_new, num_new); // saves in a file all customers that have a date greater than 2000.

    tax_new = calculateExpectedTax(array_new, num_new); // calculates the tax (40% of total balance) for each file (new and old).
    tax_old = calculateExpectedTax(array_old, num_old);

    printf("Expected Tax New %.2lf\n", tax_new);
    printf("Expected Tax New %.2lf\n", tax_old);

    index_of_max_new = findMax(array_new, num_new); // finds the client with the maximum balance in each file.
    index_of_max_old = findMax(array_old, num_old);

    printf("Max in New: %s %d\n", array_new[index_of_max_new].name, array_new[index_of_max_new].date);
    printf("Max in Old: %s %d\n", array_old[index_of_max_old].name, array_old[index_of_max_old].date);

    fclose(infile_new);
    fclose(infile_old);
    fclose(outfile);
    return 0;
}

int readInput(customerT array[], FILE *infile){
    int i = 0, nscan;
    char termc;
    while(1){
        nscan = fscanf(infile,"%40[^,], %ld, %f, %d%c", array[i].name, &array[i].balance, &array[i].epitokio, &array[i].date, &termc);
        if (nscan == EOF){
            break;
        }
        if (nscan != 5){
            printf("Error in line %d", i);
        }
        i++;
    }
    return i;
}

void find_differences(customerT array_new[], customerT array_old[], int size_new, int size_old){
    int i, j, cmp, existence;
    for (i = 0; i < size_new; i++){
            existence = 0;
        for (j = 0; j < size_old; j++){
            cmp = strcmp(array_new[i].name, array_old[j].name);
            if (cmp == 0){
               existence = existence + 1;
            }
        }
        if (existence == 0){
            printf("- %s %ld\n", array_new[i].name, array_new[i].balance);
        }
    }
}

int calculateExpectedTax(customerT array[], int size){
    long int total;
    double tax;
    int i;
    total = 0;

    for (i = 0; i < size; i++){
        total = total + array[i].balance;
    }
    tax = 0.4 * total;
    return tax;
}

void mztfgm(FILE *outfile, customerT array[], int size){
    int i;
    for (i = 0; i < size; i++){
        if (array[i].date >= 2000){
            fprintf(outfile,"%s, %ld, %f, %d\n", array[i].name, array[i].balance, array[i].epitokio, array[i].date);
        }
    }
}

int findMax(customerT array[], int size){
    int i, pos_of_max;
    long int max_balance;

    max_balance = array[0].balance;
    pos_of_max = 0;

    for (i = 0; i < size; i++){
        if (array[i].balance > max_balance){
            max_balance = array[i].balance;
            pos_of_max = i;
        }
    }
    return pos_of_max;
}

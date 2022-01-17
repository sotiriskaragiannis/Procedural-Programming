#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 50
#define GALINOS_PATIENTS 3
#define ELPIS_PATIENTS 2


typedef struct {
    char last_name[20];
    char first_name[15];
    char address[30];
    int amount;
}patientT;

void get_data(patientT array[], int size);
void print_data(char name_of_clinic[], patientT array[], int size);
int find_max_amount_patient(patientT array[], int size);
int calculate_total(patientT array[], int size);
void print_data_of_patient(patientT patient);
void search_of_patient(char name_of_clinic[], patientT array[], int size);

int main(){
    patientT galinos[MAX_PATIENTS];
    patientT elpis[MAX_PATIENTS];
    int pos_of_max_galinos, pos_of_max_elpis;
    int total_galinos, total_elpis;

    get_data(galinos, GALINOS_PATIENTS);
    get_data(elpis, ELPIS_PATIENTS);

    print_data("GALINOS", galinos, GALINOS_PATIENTS);
    print_data("ELPIS", elpis, ELPIS_PATIENTS);

    pos_of_max_galinos = find_max_amount_patient(galinos, GALINOS_PATIENTS);
    pos_of_max_elpis = find_max_amount_patient(elpis, ELPIS_PATIENTS);

    total_galinos = calculate_total(galinos, GALINOS_PATIENTS);
    total_elpis = calculate_total(elpis, ELPIS_PATIENTS);

    print_data_of_patient(galinos[pos_of_max_galinos]);
    print_data_of_patient(elpis[pos_of_max_elpis]);

    if (total_elpis < total_galinos){
        printf("Max income GALINOS %d\n", total_galinos);
    }
    else {
        printf("Max income ELPIS %d\n", total_elpis);
    }

    search_of_patient("GALINOS", galinos, GALINOS_PATIENTS);
    search_of_patient("ELPIS", elpis, ELPIS_PATIENTS);

    return 0;
}

void get_data(patientT array[], int size){
    char temp, temporary[20];
    for (int i = 0; i < size; i++){
        printf("Give data patient %d\n", i);
        printf("Last name: ");
        scanf("%c",&temporary[0]);
        //gets(array[i].last_name);
        gets(array[i].last_name);
        if (temporary[0] != '\n'){
            strcat(temporary, array[i].last_name);
            strcpy(array[i].last_name, temporary);
            temporary[0] = '\n';
        }
        printf("First name: ");
        gets(array[i].first_name);
        printf("Address: ");
        gets(array[i].address);
        printf("Amount: ");
        scanf("%d", &array[i].amount);
        printf("\n");
    }
    
}

void print_data(char name_of_clinic[], patientT array[], int size){
    printf("---------%s---------\n", name_of_clinic);
    printf("%-21s%-16s%-35s%6s\n", "Last name", "First name", "Address", "Amount");
    printf("------------------------------------------------------------------------------\n");
    for (int i = 0; i < size; i++){
        printf("%-21s%-16s%-35s%6d", array[i].last_name, array[i].first_name, array[i].address, array[i].amount);
        printf("\n");       

    }
}

int find_max_amount_patient(patientT array[], int size){
    int max_amount = array[0].amount;
    int index = 0;

    for (int i = 1; i < size; i++){
        if (array[i].amount > max_amount){
            max_amount = array[i].amount;
            index = i;
        }
    }
    return index;
}

int calculate_total(patientT array[], int size){
    int total = 0;
    for (int i = 0; i < size; i++){
        total = total + array[i].amount;
    }
    return total;
}

void print_data_of_patient(patientT patient){
    printf("%-21s%-16s%-35s%6s\n", "Last name", "First name", "Address", "Amount");
    printf("------------------------------------------------------------------------------\n");
    printf("%-21s%-16s%-35s%6d", patient.last_name, patient.first_name, patient.address, patient.amount);
    printf("\n");       
}

void search_of_patient(char name_of_clinic[], patientT array[], int size){
    char l_name[20], f_name[15], temporary[20];
    int result1, result2;

    printf("Search a patient for %s\n", name_of_clinic);
    printf("Give last name ");
    scanf("%c", &temporary[0]);
    gets(l_name);
    if (temporary[0] != '\n'){
            strcat(temporary, l_name);
            strcpy(l_name, temporary);
            temporary[0] = '\n';
        }
    printf("Give first name ");
    gets(f_name);

    //printf("L_NAME = %s,  F_NAME = %s\n", l_name, f_name);

    for (int i = 0; i < size; i++){
        result1 = strcmp(l_name, array[i].last_name);
        result2 = strcmp(f_name, array[i].first_name);
        if ((result1 == 0) && (result2 == 0)){
            print_data_of_patient(array[i]);
        };
    }
}
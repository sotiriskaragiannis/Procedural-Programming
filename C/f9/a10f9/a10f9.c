#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *infile, *outfile;
    char ch, prev;
    int flag = 0;

    infile = fopen("i10f9.dat", "r");
    if (infile == NULL){
        printf("Cannot open file i10f9.dat");
        exit(1);
    }
    outfile = fopen("o10f9.dat", "w");

    while(1){
        ch = fgetc(infile);

        if (ch == EOF){
            break;
        }
        if ((ch != ' ') && ((prev == '.' ) || (prev == ','))){
            fputc(' ', outfile);
        }
        fputc(ch, outfile);
        prev = ch;
    }



    return 0;
}
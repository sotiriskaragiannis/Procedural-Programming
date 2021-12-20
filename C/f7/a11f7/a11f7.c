#include <stdio.h>
#include <string.h>
#include "simpio.h"

#define LEN 80

int main(){
    char email[LEN], dst[LEN], name[LEN], server[LEN];
    int front, back, index;


    printf("Give email: ");
    gets(email);

    front = 0;
    while (email[front]==' '){
        front++;

    }

    back = strlen(email) - 1;
    while (email[back]==' '){
        back--;
    }

    strncpy(dst, email+front, back-front+1);
    dst[back-front+1] = '\0';

    index = 0;
    while (dst[index] != '@'){
        index++;
    }

    strncpy(name, dst, index);
    name[index] = '\0';

    strncpy(server, dst + index + 1, strlen(dst)-index);

    printf("%s:%d\n", name, strlen(name));
    printf("%s:%d", server, strlen(server));

    return 0;
}

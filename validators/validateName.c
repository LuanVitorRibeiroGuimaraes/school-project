#include "validators.h"

int validateName(char name[]){

    for (int i = 0; name[i] != '\0'; i++) {
        if (isdigit(name[i])) {
            printf("\n-----------------------------------------");
            printf("\n[!] Campo 'Nome' Nao Pode Conter Numeros!");
            printf("\n-----------------------------------------");
            return 1; 
        }
    }
    return 0;
}
#include "validators.h"

int validateName(char name[]){

    for (int i = 0; name[i] != '\0'; i++) {
        if (isdigit(name[i])) {
            printf("\n-------------------------------------");
            printf("\nCampo 'Nome' Nao Pode Conter Numeros!");
            printf("\n-------------------------------------\n");
            return 1; 
        }
    }
    return 0;
}
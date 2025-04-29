#include "validators.h"

int validateSex(char Sex)
{

    if (Sex != 'M' && Sex != 'F')
    {
        printf("\n--------------------------");
        printf("\nDigite Somente 'M' ou 'F'.");
        printf("\n--------------------------\n");
        return 1;
    }

    return 0; 
}
#include "validators.h"

int validateSex(char Sex)
{

    if (Sex != 'M' && Sex != 'F')
    {
        printf("\n------------------------------");
        printf("\n[!] Digite Somente 'M' ou 'F'.");
        printf("\n------------------------------");
        return 1;
    }

    return 0; 
}
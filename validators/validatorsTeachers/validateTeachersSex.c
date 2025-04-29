#include <stdio.h>
#include <stdlib.h>

int validateTeachersSex(char pSex)
{

    if (pSex != 'M' && pSex != 'F')
    {
        printf("\n--------------------------");
        printf("\nDigite Somente 'M' ou 'F'.");
        printf("\n--------------------------");
        return 1;
    }

    return 0; 
}
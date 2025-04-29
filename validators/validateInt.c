#include "validators.h"

int validateInt()
{
    int value;
    int scanfResult;
	int c;

    scanfResult = scanf("%d", &value);
    if (scanfResult != 1)
    {
        while ((c = getchar()) != '\n' && c != EOF) { } //Limpar o buffer 
        return -1; // Retorna -1 para indicar entrada inválida
    }

    return value;
}
#ifndef VALIDATORS_H
#define VALIDATORS_H

#define SIZE_CPF 15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



void validateCpf();
void formatCpf(char cpf[]);

void formatCpf();

void validadebirthDate(char birthDate[10]);//precisa testar

void validateSemester();

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
#endif

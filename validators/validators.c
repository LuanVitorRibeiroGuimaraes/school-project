#include "validators.h"


void formatCpf(char cpf[])
{
    char formatted[SIZE_CPF];

    sprintf(formatted, "%.3s.%.3s.%.3s-%.2s", cpf, cpf+3, cpf+6, cpf+9);

    // printf("%s", formatted);
}

int validateCpf(char cpf[]) {
    int i, qtdNumeros = 0;

    for (i = 0; cpf[i] != '\0'; i++) {
        if (cpf[i] >= '0' && cpf[i] <= '9')
            qtdNumeros++;
    }

    if (qtdNumeros != 11)
        return 0;


    int soma = 0, resto, digito1, digito2;
    int numeros[11];
    int pos = 0;

    for (i = 0; cpf[i] != '\0'; i++) {
        if (cpf[i] >= '0' && cpf[i] <= '9') {
            numeros[pos] = cpf[i] - '0';
            pos++;
        }
    }

    // Primeiro dígito
    for (i = 0; i < 9; i++)
        soma += numeros[i] * (10 - i);
    
    resto = soma % 11;
    digito1 = (resto < 2) ? 0 : 11 - resto;

    if (digito1 != numeros[9])
        return 0;

    // Segundo dígito
    soma = 0;
    for (i = 0; i < 10; i++)
        soma += numeros[i] * (11 - i);

    resto = soma % 11;
    digito2 = (resto < 2) ? 0 : 11 - resto;

    if (digito2 != numeros[10])
        return 0;

    return 1;

    formatCpf(cpf);
}


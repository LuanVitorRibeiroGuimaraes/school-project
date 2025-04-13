#include <stdio.h>

void validateCpf(long cpf)
{
    while (sizeof(cpf) > 11 && sizeof(cpf) < 11)
    {
        printf("Quantidade de caracteres incorreta\n");
        
        printf("Digite novamente o cpf: ");
        scanf("%ld", &cpf);
    }
}
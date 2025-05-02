#include "validators.h"

void formatCpf(char *cpf)
{
    char formatted[15]; // "xxx.xxx.xxx-xx" + \0
    sprintf(formatted, "%.3s.%.3s.%.3s-%.2s", cpf, cpf+3, cpf+6, cpf+9);
    strcpy(cpf, formatted);
}


int validateCpf(char *cpf) //funcionando.
{
    int i, j, digito1 = 0, digito2 = 0;
    int len = strlen(cpf);
    if(len != 11)
    {
        printf("\n------------------------------------------");
        printf("\n[!] CPF deve conter exatamente 11 digitos.");
        printf("\n------------------------------------------");
        return 0;
    }

    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
        (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
        (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
        (strcmp(cpf,"99999999999") == 0))
    {
        printf("\n------------------------------------------------");
        printf("\n[!] CPF com todos os digitos iguais eh invalido.");
        printf("\n------------------------------------------------");
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    }

    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < len-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11; //pega o resto do resultado da multiplicação
        if(digito1 < 2) //se o resto for menor que 2 sempre é 0
            digito1 = 0;
        else
            digito1 = 11 - digito1; //se o resto for maior que 2 subtrai de 11
        if((cpf[9]-48) != digito1)
        {
            printf("\n----------------------------------");
            printf("\n[!] Digito verificador 1 invalido.");
            printf("\n----------------------------------");
            return 0;
        }
        else
        {
            ///digito 2--------------------------------------------------
            for(i = 0, j = 11; i < len-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                digito2 += (cpf[i]-48) * j;
            digito2 %= 11;
            if(digito2 < 2)
                digito2 = 0;
            else
                digito2 = 11 - digito2;
            if((cpf[10]-48) != digito2)
            {
                printf("\n----------------------------------");
                printf("\n[!] Digito verificador 2 invalido.");
                printf("\n----------------------------------");
                return 0;
            }
        }

        formatCpf(cpf);
        return 1;
    }
}

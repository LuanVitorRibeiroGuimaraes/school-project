#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// strtok - quebra uma string em tokens, dado um delimitador específico (use /).
// strtol - converte uma string para um inteiro longo.
// strstr - localiza a primeira ocorrência de uma substring específica em uma string (use //).
// isdigit - verifica se o caractere passado como argumento é um dígito.
// atof() Conversão de string em float
// atoi() Conversão de string to int
// atol() Conversão de string to long
// itoa() Conversão de int to string
// ltoa() Conversão de long to string

void validatebirthDate(char birthDate[10])
{
    //verificando o tamanho do array (terá q ser 9 no input por conta do '\0')
    if (sizeof(birthDate) < 8)
    {
        printf("Tamanho de data incorreto, formato correto: (##/##/##)\n");
    }

    //removendo os '/' da data
    for (int i = 0; birthDate[i] != '\0'; i++)
    {
        if (birthDate[i] == '/')
        {
            birthDate[i] = "";
        }
    }

    //printando a data sem a /
    for (int i = 0; birthDate[i] != '\0'; i++)
    {
        printf("%c", birthDate[i]);
    }
    printf("\n");

    int number = atoi(birthDate);
    printf("%d\n", number);
}


int main() 
{

void validatebirthDate(char birthDate[10]);

  char string[] = "12/01/24";

  validatebirthDate(string);

}
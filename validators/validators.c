#include "validators.h"


void formatCpf(char cpf[])
{
    char formatted[SIZE_CPF];

    sprintf(formatted, "%.3s.%.3s.%.3s-%.2s", cpf, cpf+3, cpf+6, cpf+9);

    printf("%s", formatted);
}

void validateCpf()
{
    char CPF[SIZE_CPF];

    printf("Digite o CPF: ");
    fgets(CPF, sizeof(CPF), stdin);
    CPF[strcspn(CPF, "\n")] = '\0';
    
    
    if (strlen(CPF) < 11 || strlen(CPF) > 11)
        do
        {
            printf("CPF precisa de 11 caracteres.\n");
            printf("Digite o CPF: ");
            fgets(CPF, sizeof(CPF), stdin);
            CPF[strcspn(CPF, "\n")] = '\0';
        }
        while (strlen(CPF) < 11 || strlen(CPF) > 11);

    formatCpf(CPF);
}

int main ()
{
    void validateCpf();

    validateCpf();

    return 0;
}
#include <stdio.h>
#include "validators/validators.h"
#include "students/students.h"
#include "teachers/teachers.h"

int main()
{
    int resposta;
    char buffer[100];

    printf("\n---------------------MENU PRINCIPAL---------------------");
    printf("\nSeja Bem Vindo ao Projeto Escola!");
    printf("\n1 - Menu Alunos.");
    printf("\n2 - Menu Professores.");
    printf("\n3 - Menu Disciplinas.");
    printf("\n4 - Aniversariantes do Mes.");
    printf("\n5 - Encerrar Programa.");
    printf("\n--------------------------------------------------------");

    printf("\n>> ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &resposta);

    switch (resposta)
    {
    default:
        printf("\n-------------------------------------");
        printf("\n[!] Selecione Uma Das Opcoes Validas!");
        printf("\n-------------------------------------");
        break;

    case 1:

        studentMenu();
        break;

    case 2:

        teachersMenu();
        break;

    case 3:

        subjectMainMenu();
        break;

    case 4:

        //! FAZER
        break;

    case 5:

        printf("\n[!][!] Encerrando o Programa...");
        exit(0);
        break;
    }

    return 0;
}

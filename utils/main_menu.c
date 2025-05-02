#include "utils.h"

void mainMenu()
{
    while (true)
    {
        int resposta;
        char buffer[100];

        printf("\n---------------------MENU PRINCIPAL---------------------");
        printf("\nSeja Bem Vindo ao Projeto Escola!\n");
        printf("\n1 - Menu Alunos.\n");
        printf("\n2 - Menu Professores.\n");
        printf("\n3 - Menu Disciplinas.\n");
        printf("\n4 - Aniversariantes do Mes.\n");
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

            birthdaysMonth();
            break;

        case 5:

            printf("\n[!][!] Encerrando o Programa...");
            exit(0);
            break;
        }
    }
}

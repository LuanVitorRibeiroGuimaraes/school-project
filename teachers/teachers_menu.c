#include <stdio.h>
#include <stdbool.h>
#include "teachers.h"

void teachersMenu()
{
    while (1)
    {
        printf("\n----------------- MENU PROFESSORES ----------------\n");
        printf("1 - Adicionar Professor.\n");
        printf("2 - Atualizar Dados do Professor.\n");
        printf("3 - Listar Todos os Professores.\n");
        printf("4 - Buscar Professor por Matricula.\n");
        printf("5 - Buscar Professores pelo Nome.\n");
        printf("6 - Listar Professores Pelo Sexo.\n");
        printf("7 - Listar Professores Pela Data de Aniversario.\n");
        printf("8 - Excluir Professor.\n");
        printf("9 - Voltar Para o Menu Principal\n");
        printf("----------------------------------------------------\n");

        int lResposta;
        char buffer[100];

        printf(">> ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &lResposta);

        switch (lResposta)
        {
        default:
            printf("Selecione uma das opcoes validas!\n");
        case 1:
            createTeacher();
            break;
        case 2:
            if (isEmpityTeacher() == true)
            {
                break;
            }
            else
            {
                updateTeacher();
                break;
            }
            break;
        case 3:
            if (isEmpityTeacher() == true)
            {
                break;
            }
            else
            {
                listTeachers();
                break;
            }
        case 4:
            if (isEmpityTeacher() == true)
            {
                break;
            }
            printf("Digite a matricula do professor que deseja buscar: \n");
            printf(">> ");
            int lId;
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &lId);

            listTeachersById(lId);
            break;

        case 5:
            if (isEmpityTeacher() == true)
            {
                break;
            }
            printf("Digite o nome do professor que deseja buscar: \n");
            printf(">> ");
            char lName[100];
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%s", &lName);

            listTeachersByName(lName);
            break;

            /*case 6:
                printf("Digite o sexo (F/M) dos professores que deseja buscar: \n");
                printf(">> ");
                char lSexo;
                scanf("%c", &lSexo);
                listTeachersBySex(lSexo);
                break;

            case 7:
                printf("Digite a data de aniversario (dd/mm/aaaa) do professor que deseja buscar: \n");
                printf(">> ");
                int lDataAniversario;
                scanf("%d", &lDataAniversario);
                listTeachersBybirthDate(lDataAniversario);
                break;*/

        case 8:
            if (isEmpityTeacher() == true)
            {
                break;
            }
            else
            {
                excluirProfessor();
                break;
            }
            break;
        case 9:
            return;
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "teachers.h"

void teachersMenu()
{

    while (1)
    {
        int resposta, respostaSub;
        char buffer[100];

        printf("\n----------------- MENU PROFESSORES ----------------\n");
        printf("0 - Voltar Para o Menu Principal\n");
        printf("1 - Adicionar Professor.\n");
        printf("2 - Atualizar Dados do Professor.\n");
        printf("3 - Buscar Professores.\n");
        printf("4 - Excluir Professor.\n");
        printf("-----------------------------------------------------\n");

        printf(">> ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &resposta);

        switch (resposta)
        {
        default:
            printf("\n-------------------------------------");
            printf("\n[!] Selecione Uma Das Opcoes Validas!");
            printf("\n-------------------------------------");
            break;

        case 0:
            return;

        case 1:
            createTeacher();
            break;

        case 2:
            if (isEmpityTeacher() == true)
            {
                break;
            }

            updateTeacher();
            break;

        case 3:

            while (1)
            {
                printf("\n------------- MENU BUSCAR PROFESSORES -------------");
                printf("\n0 - Voltar Para o Menu de Professores.");
                printf("\n1 - Buscar Todos os Professores.");
                printf("\n2 - Buscar Professor por Matricula.");
                printf("\n3 - Buscar Professor pelo Nome.");
                printf("\n4 - Buscar Professor Pelo Sexo.");
                printf("\n5 - Buscar Professor Pela Data de Aniversario.");
                printf("\n6 - Buscar Professor Por Iniciais.");
                printf("\n---------------------------------------------------");

                printf("\n>> ");
                fgets(buffer, sizeof(buffer), stdin);
                sscanf(buffer, "%d", &respostaSub);

                switch (respostaSub)
                {
                default:
                    printf("\n-------------------------------------");
                    printf("\n[!] Selecione Uma Das Opcoes Validas!");
                    printf("\n-------------------------------------");
                    break;

                case 0:
                    //* Faz sair do submenu e voltar para o menu de professores
                    goto fim_submenu;

                case 1:
                    if (isEmpityTeacher() == true)
                    {
                        break;
                    }

                    listTeachers();
                    break;

                case 2:
                    if (isEmpityTeacher() == true)
                    {
                        break;
                    }

                    listTeachersById();
                    break;

                case 3:
                    if (isEmpityTeacher() == true)
                    {
                        break;
                    }

                    listTeachersByName();
                    break;

                case 4:
                    if (isEmpityTeacher() == true)
                    {
                        break;
                    }

                    listTeachersBySex();
                    break;

                case 5:
                    if (isEmpityTeacher() == true)
                    {
                        break;
                    }

                    listTeachersBybirthDate();
                    break;

                case 6:
                    if (isEmpityTeacher() == true)
                    {
                        break;
                    }

                    listTeacherByLetter();
                    break;
                }
            }
            fim_submenu:
            break;
            
        case 4:
            if (isEmpityTeacher() == true)
            {
                break;
            }
            excluirProfessor();
            break;
        }
    }
}

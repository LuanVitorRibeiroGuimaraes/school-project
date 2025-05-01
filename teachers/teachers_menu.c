#include <stdio.h>
#include "teachers.h"

void teachersMenu()
{
    while (1)
    {
        int resposta;
        char buffer[100];

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
        printf("---------------------------------------------------\n");

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
            if (isEmpityTeacher() == true)
            {
                break;
            }

            listTeachers();
            break;

        case 4:
            if (isEmpityTeacher() == true)
            {
                break;
            }

            listTeachersById();
            break;

        case 5:
            if (isEmpityTeacher() == true)
            {
                break;
            }

            listTeachersByName();
            break;

        case 6:
            if (isEmpityTeacher() == true)
            {
                break;
            }
        
            listTeachersBySex();
            break;

        case 7:
            if (isEmpityTeacher() == true)
            {
                break;
            }
            
            listTeachersBybirthDate();
            break;

        case 8:
            if (isEmpityTeacher() == true)
            {
                break;
            }
            excluirProfessor();
            break;

        case 9:
            return;
        }
    }
}

#include "students.h"


void updateStudent()
{
    if (studentQnt == 0)
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados!");
        printf("\n---------------------------------------------------\n");
        return;
    }

    int id;
    char name[100];
    bool exist = true;
    int birthDate;

    printf("\n----------------------------------------------------\n");
    printf("Digite a matricula do aluno que deseja atualizar: ");
    printf("\n>> ");
    scanf("%d", &id);
    printf("\n----------------------------------------------------\n");
    getchar();

    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].studentId == id && students[i].active)
        {
            exist = true;
            while (true)
            {
                printf("Digite o nome: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                if (validateName(name) == 0)
                    break;
            }

            printf("Digite a data de aiversario: ");
            scanf("%d", &birthDate);

            strcpy(students[i].name, name);
            students[i].birthDate = birthDate;
        }
        break;

        if (!exist)
        {
            printf("\n----------------------------------------------------\n");
            printf("Nao existe aluno com essa matricula!");
            printf("\n---------------------------------------------------\n");
        }
    }
}
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
    int toFind;
    int currentId;
    char name[100];
    int birthDate;
    bool found = false;
    bool currentStatus;

    printf("\n----------------------------------------------------\n");
    printf("Digite a matricula do aluno que deseja atualizar: ");
    printf("\n>> ");
    scanf("%d", &id);
    printf("\n----------------------------------------------------\n");
    getchar();

    toFind = id;

    for (int i = 0; i < studentQnt; i++)
    {
        currentId = students[i].studentId;
        currentStatus = students[i].active;

        if (toFind == currentId && currentStatus)
        {
            found = true;

            while (true)
            {
                printf("Digite o nome: ");
                printf(">> ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                if (validateName(name) == 0)
                {
                    break;
                }
            }

            printf("\n >>Digite a data de aniversario (DDMMAAAA): ");
            scanf("%d", &birthDate);

            printf("\n----------------------------------------------------\n");
            printf("Aluno atualizado com sucesso!");
            printf("\n---------------------------------------------------\n");

            strcpy(students[i].name, name);
            students[i].birthDate = birthDate;
            break;
        }
    }

    if (!found)
        {
            printf("\n----------------------------------------------------\n");
            printf("Aluno nao encontrado!");
            printf("\n---------------------------------------------------\n");
        }
}
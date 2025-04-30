#include "students.h"

void updateStudent()
{
    if (studentQnt == 0)
    {
        printf("\n--------------------------");
        printf("\nNao ha alunos cadastrados!");
        printf("\n--------------------------");
        return;
    }

    int id;
    int toFind;
    int currentId;
    char name[100];
    char cpf[15];
    int birthDate;
    bool found = false;
    bool currentStatus;

    printf("\n>> Digite a matricula do aluno que deseja atualizar: ");
    printf("\n>> ");
    scanf("%d", &id);
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
                printf("\n>> Digite o nome: ");
                printf("\n>> ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                if (validateName(name) == 0)
                {
                    break;
                }
            }

            printf("\n >> Digite a data de aniversario (DDMMAAAA): ");
            printf("\n>> ");
            scanf("%d", &birthDate);

            while (true)
            {
                printf("\n >> Digite o CPF do aluno: ");
                fgets(cpf, sizeof(cpf), stdin);
                cpf[strcspn(cpf, "\n")] = '\0';
        
                if (validateCpf(cpf) == 1)
                {
                    break;
                }    
            }

            printf("\n-----------------------------");
            printf("\nAluno atualizado com sucesso!");
            printf("\n-----------------------------");

            strcpy(students[i].name, name);
            students[i].birthDate = birthDate;
            break;
        }
    }

    if (!found)
        {
            printf("\n----------------------------------------------------");
            printf("\nAluno nao encontrado!");
            printf("\n---------------------------------------------------");
        }
}

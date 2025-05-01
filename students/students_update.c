#include "students.h"

char buffer[100];

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
    int day, month, year;


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

            printf("\n >> Digite a data de aniversario do aluno: ");
            printf("\n >> Dia (DD): ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &day);

            printf("\n >> Mes (MM): ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &month);

            printf("\n >> Ano (AAAA): ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &year);
            if (validateData(day, month, year))
                break;
            else
            {
                printf("\n-----------------------------------");
                printf("\n[!] Data invalida! Tente novamente!");
                printf("\n-----------------------------------");
                continue;
            }

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
            students[i].birthDay = day;
            students[i].birthMonth = month;
            students[i].birthYear = year;
            break;
        }
    }

    if (!found)
        {
            printf("\n-------------------------");
            printf("\n[!] Aluno nao encontrado!");
            printf("\n-------------------------");
        }
}

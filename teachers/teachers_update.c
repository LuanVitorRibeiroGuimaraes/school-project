#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teachers.h"
#include "../validators/validators.h"

char buffer[100];

void updateTeacher()
{

    listTeachers();
    printf("\nDigite a matricula do professor no qual voce quer alterar os dados:");
    printf("\n>> ");
    int lId;
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &lId);

    for (int i = 0; i < teacherQnt; i++)
    {
        if (teachers[i].teacherId == lId)
        {
            char lName[100];
            char lSex;
            int lBirthDate;
            long lCpf;

            while (1)
            {
                printf("\n >>Digite o novo nome do professor: ");
                fgets(buffer, sizeof(buffer), stdin);
                sscanf(buffer, "%s", &lName);
                if (validateName(lName) == 1)
                {
                    continue;
                }
                strcpy(teachers[i].name, lName);
                break;
            }

            while (1)
            {
                printf("\n >>Digite o novo sexo do professor: ");
                fgets(buffer, sizeof(buffer), stdin);
                sscanf(buffer, "%c", &lSex);
                lSex = toupper(lSex);
                if (validateSex(lSex) == 1)
                {
                    continue;
                }
                teachers[i].sex = lSex;
                break;
            }

            printf("\n >>Digite a nova data de aniversario (DDMMAAAA) do professor: ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &lBirthDate);
            //! VALIDAR DATA DE ANIVERSARIO

            teachers[i].birthDate = lBirthDate;

            while (1)
            {
                printf("\n >>Digite o novo CPF do professor: ");
                fgets(buffer, sizeof(buffer), stdin);
                sscanf(buffer, "%s", &lCpf);
                if (validateCpf(lCpf) == 0)
                {
                    continue;
                }
                strcpy(teachers[i].cpf, lCpf);
                break;
            }

            printf("\n----------------------------");
            printf("\nDados alterados com sucesso!");
            printf("\n----------------------------");
            return;
        }
    }
    printf("\n-------------------------------------------------");
    printf("\nMatricula Incorreta, Por Favor, Digite Novamente.");
    printf("\n-------------------------------------------------");
    return;
}
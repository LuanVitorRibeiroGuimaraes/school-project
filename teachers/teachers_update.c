#include <stdio.h>
#include <stdlib.h>
#include "teachers.h"

char buffer[100];

void updateTeacher()
{

    listTeachers();
    printf("\n Digite a matricula do professor no qual voce quer alterar os dados:");
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

            printf("\nDigite o novo nome do professor: ");
            printf("\n>> ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%s", &lName);
            strcpy(teachers[i].name, lName);

            printf("\nDigite o novo sexo do professor: ");
            printf("\n>> ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%c", &lSex);
            teachers[i].sex = lSex;

            printf("\nDigite a nova data de aniversario do professor: ");
            printf("\n>> ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &lBirthDate);
            teachers[i].birthDate = lBirthDate;

            printf("\nDigite o novo CPF do professor: ");
            printf("\n>> ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%ld", &lCpf);
            teachers[i].cpf = lCpf;

            printf("\nDados alterados com sucesso!");
            break;
        }
    }
    printf("\nMatricula Incorreta, Por Favor, Digite Novamente.\n");
}
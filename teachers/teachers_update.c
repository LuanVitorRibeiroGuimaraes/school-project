#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teachers.h"
#include "../validators/validators.h"

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

            printf("Digite o novo nome do professor: ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%s", &lName);
            if (validateTeachersName(lName) == 1)
            {
                return;
            }
            strcpy(teachers[i].name, lName);

            printf("Digite o novo sexo do professor: ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%c", &lSex);
            lSex = toupper(lSex);
            if (validateTeachersSex(lSex) == 1)
            {
                return;
            }
            teachers[i].sex = lSex;

            printf("Digite a nova data de aniversario do professor: ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &lBirthDate);
            //! VALIDAR DATA DE ANIVERSARIO

            teachers[i].birthDate = lBirthDate;

            printf("Digite o novo CPF do professor: ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%ld", &lCpf);
            //! validateCpf(cpf);

            teachers[i].cpf = lCpf;

            printf("\n----------------------------");
            printf("\nDados alterados com sucesso!");
            printf("\n----------------------------");
            return;
        }
    }
    printf("\nMatricula Incorreta, Por Favor, Digite Novamente.\n");
}
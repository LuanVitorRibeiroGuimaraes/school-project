#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "teachers.h"
#include "../validators/validators.h"

#define SIZE_PROFESSORES 100

int teacherQnt = 0;
Teacher teachers[SIZE_PROFESSORES];

void createTeacher()
{
    int teacherId;
    char name[100];
    char sex;
    char cpf[15];
    int day, month, year;
    char cargo[] = "Professor(a)";

    if (teacherQnt == SIZE_PROFESSORES)
    {
        printf("\n-----------------------------------------------");
        printf("\n[!] Nao eh possivel cadastrar mais professores!");
        printf("\n-----------------------------------------------");
        return;
    }

    char buffer[100];

    while (1)
    {
        printf("\n >> Digite a matricula do professor: ");
        fgets(buffer, sizeof(buffer), stdin);

        //* VALIDA SE O USUARIO DIGITOU UM NUMERO!
        if (sscanf(buffer, "%d", &teacherId) != 1 || teacherId <= 0)
        {
            printf("\n--------------------------------------------");
            printf("\n[!] Digite Somente Numeros Maiores Que Zero!");
            printf("\n--------------------------------------------");
            continue;
        }
        if (validateTeacherId(teacherId) == 1)
        {
            continue;
        }
        break;
    }

    while (1)
    {
        printf("\n >> Digite o nome do professor: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        if (validateName(name) == 1)
        {
            continue;
        }
        break;
    }

    while (1)
    {
        printf("\n >> Digite o sexo do professor (F ou M): ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%c", &sex);
        sex = toupper(sex);
        if (validateSex(sex) == 1)
        {
            continue;
        }
        break;
    }

    printf("\n >> Digite a data de aiversario do professor(a): ");
    while (1)
    {
        printf("\n\n >> Dia (DD): ");
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
    }

    while (1)
    {
        printf("\n >> Digite o CPF do professor (Somente Numeros): ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%s", &cpf);
        if (validateCpf(cpf) == 0)
        {
            continue;
        }
        break;
    }

    teachers[teacherQnt].teacherId = teacherId;
    strcpy(teachers[teacherQnt].name, name);
    teachers[teacherQnt].sex = sex;
    teachers[teacherQnt].birthDay = day;
    teachers[teacherQnt].birthMonth = month;
    teachers[teacherQnt].birthYear = year;
    strcpy(teachers[teacherQnt].cpf, cpf);
    strcpy(teachers[teacherQnt].cargo, cargo);

    teacherQnt++;

    printf("\n---------------------------------");
    printf("\nProfessor cadastrado com sucesso!");
    printf("\n---------------------------------");
    return;
}
#pragma endregion

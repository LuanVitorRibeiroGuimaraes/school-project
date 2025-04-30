#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "teachers.h"
#include <string.h>
#include "../validators/validators.h"

#define SIZE_PROFESSORES 100

int teacherQnt = 0;
Teacher teachers[SIZE_PROFESSORES];

void createTeacher()
{
    int teacherId;
    char name[100];
    char sex;
    int birthDate;
    char cpf[15];
    char cargo[] = "Professor(a)";

    if (teacherQnt == SIZE_PROFESSORES)
    {
        printf("\n-------------------------------------------");
        printf("\nNao eh possivel cadastrar mais professores!");
        printf("\n-------------------------------------------");
        return;
    }

    char buffer[100];

    while (1)
    {
        printf("\n >>Digite a matricula do professor: ");
        fgets(buffer, sizeof(buffer), stdin);

        //* VALIDA SE O USUARIO DIGITOU UM NUMERO!
        if (sscanf(buffer, "%d", &teacherId) != 1 || teacherId <= 0)
        {
            printf("\n----------------------------------------");
            printf("\nDigite Somente Numeros Maiores Que Zero!");
            printf("\n----------------------------------------");
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
        printf("\n >>Digite o nome do professor: ");
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
        printf("\n >>Digite o sexo do professor (F ou M): ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%c", &sex);
        sex = toupper(sex);
        if (validateSex(sex) == 1)
        {
            continue;
        }
        break;
    }

    printf("\n >>Digite a data de aiversario (DDMMAAAA): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &birthDate);
    //! VALIDAR DATA DE ANIVERSARIO

    while (1)
    {
        printf("\n >>Digite o CPF do professor: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%s", &cpf);
        if(validateCpf(cpf) == 0){
            continue;
        }
        break;   
    }
    
    teachers[teacherQnt].teacherId = teacherId;
    strcpy(teachers[teacherQnt].name, name);
    teachers[teacherQnt].sex = sex;
    teachers[teacherQnt].birthDate = birthDate;
    strcpy(teachers[teacherQnt].cpf, cpf);
    strcpy(teachers[teacherQnt].cargo, cargo);

    teacherQnt++;

    printf("\n---------------------------------");
    printf("\nProfessor cadastrado com sucesso!");
    printf("\n---------------------------------");
    return;
}
#pragma endregion


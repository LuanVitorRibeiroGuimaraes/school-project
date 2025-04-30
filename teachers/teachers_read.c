#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "teachers.h"

char buffer[100];

bool isEmpityTeacher()
{
    if (teacherQnt == 0)
    {
        printf("\n--------------------------------");
        printf("\n[!] Nenhum Professor Cadastrado.");
        printf("\n--------------------------------");
        printf("\nDeseja Voltar ao Menu de Professores? (y/n)");
        printf("\n>> ");
        char lResposta;
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%c", &lResposta);
        if (toupper(lResposta) == 'Y')
        {
            return true;
        }
        else
        {
            printf("\n\nFim do programa!\n\n");
            exit(0);
        }
    }
    return false;
}

int compararNomes(const void *a, const void *b)
{
    return strcmp(((Teacher *)a)->name, ((Teacher *)b)->name);
}

void listTeachers()
{
    qsort(teachers, teacherQnt, sizeof(Teacher), compararNomes);

    printf("\t\tLISTA DE PROFESSORES\n");
    for (int i = 0; i < teacherQnt; i++)
    {
        if (teachers[i].teacherId != 0)
        {
            printf("\n-------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDate, teachers[i].sex, teachers[0].cargo);
            printf("\n-------------------------------------");
        }
    }
}

void listTeachersById()
{
    printf("\nDigite a matricula do professor que deseja buscar:");
    printf("\n>> ");
    int lId;
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &lId);

    for (int i = 0; i < teacherQnt; i++)
    {
        if (teachers[i].teacherId == lId)
        {
            printf("\n-------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDate, teachers[i].sex, teachers[0].cargo);
            printf("\n-------------------------------------");
            break;
        }
        else
        {
            printf("\n------------------------------------------------");
            printf("\n[!] Professor nao existe ou matricula incorreta.");
            printf("\n------------------------------------------------");
        }
    }
}

void listTeachersByName()
{
    printf("\nDigite o nome do professor que deseja buscar:");
    printf("\n>> ");
    char lName[100];
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%s", &lName);

    int lCont = 0;

    qsort(teachers, teacherQnt, sizeof(Teacher), compararNomes);

    for (int i = 0; i < teacherQnt; i++)
    {
        if (strcmp(teachers[i].name, lName) == 0)
        {
            printf("\n-------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDate, teachers[i].sex, teachers[0].cargo);
            printf("\n-------------------------------------");
            lCont++;
        }
    }
    if (lCont == 0)
    {
        printf("\n------------------------");
        printf("\n[!] Nome nao encontrado.");
        printf("\n------------------------");
    }
}

void listTeachersBySex()
{
    printf("\nDigite o sexo (F/M) dos professores que deseja buscar:");
    printf("\n>> ");
    char lSexo;
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%c", &lSexo);
    lSexo = toupper(lSexo);

    int lCont = 0;
    for (int i = 0; i < teacherQnt; i++)
    {
        if (teachers[i].sex == lSexo)
        {
            printf("\n-------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDate, teachers[i].sex, teachers[0].cargo);
            printf("\n-------------------------------------");
            lCont++;
        }
    }
    if (lCont == 0)
    {
        printf("\n-----------------------------------");
        printf("\n[!] Nenhum professor com esse sexo.");
        printf("\n-----------------------------------");
    }
}

void listTeachersBybirthDate()
{
    printf("\nDigite a data de aniversario (DDMMAAAA) do professor que deseja buscar:");
    printf("\n>> ");
    int lDataAniversario;
    fgets(buffer, sizeof(buffer), stdin);
    scanf(buffer, "%d", &lDataAniversario);

    int lCont = 0;

    for (int i = 0; i < teacherQnt; i++)
    {
        if (teachers[i].birthDate == lDataAniversario)
        {
            printf("\n-------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDate, teachers[i].sex, teachers[0].cargo);
            printf("\n-------------------------------------");
            lCont++;
        }
    }
    if (lCont == 0)
    {
        printf("\n--------------------------------------------------");
        printf("\n[!] Nenhum Professor Com Essa Data de Aniversario.");
        printf("\n--------------------------------------------------");
    }
}
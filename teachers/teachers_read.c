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
        printf("----------------------------\n");
        printf("Nenhum Professor Cadastrado.\n");
        printf("----------------------------\n");
        printf("Deseja Voltar ao Menu de Professores? (y/n)\n");
        printf(">> ");
        char lResposta;
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%c", &lResposta);
        if (toupper(lResposta) == 'Y')
        {
            return true;
        }
        else
        {
            printf("\nFim do programa!\n");
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
            printf("\nNome: %s \nMatricula: %d \nCPF: %ld \nData de Nascimento: %d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDate, teachers[i].sex, teachers[0].cargo);
            printf("\n-------------------------------------");
        }
    }
}

void listTeachersById()
{
    printf("Digite a matricula do professor que deseja buscar: \n");
    printf(">> ");
    int lId;
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &lId);

    for (int i = 0; i < teacherQnt; i++)
    {
        if (teachers[i].teacherId == lId)
        {
            printf("\n-------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %ld \nData de Nascimento: %d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDate, teachers[i].sex, teachers[0].cargo);
            printf("\n-------------------------------------");
            break;
        }
        else
        {
            printf("\n--------------------------------------------");
            printf("\nProfessor nao existe ou matricula incorreta.");
            printf("\n--------------------------------------------");
        }
    }
}

void listTeachersByName()
{
    printf("Digite o nome do professor que deseja buscar: \n");
    printf(">> ");
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
            printf("\nNome: %s \nMatricula: %d \nCPF: %ld \nData de Nascimento: %d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDate, teachers[i].sex, teachers[0].cargo);
            printf("\n-------------------------------------");
            lCont++;
        }
    }
    if (lCont == 0)
    {
        printf("\n--------------------");
        printf("\nNome nao encontrado.");
        printf("\n--------------------");
    }
}

void listTeachersBySex()
{
    printf("Digite o sexo (F/M) dos professores que deseja buscar: \n");
    printf(">> ");
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
            printf("\nNome: %s \nMatricula: %d \nCPF: %ld \nData de Nascimento: %d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDate, teachers[i].sex, teachers[0].cargo);
            printf("\n-------------------------------------");
            lCont++;
        }
    }
    if (lCont == 0)
    {
        printf("\n-------------------------------");
        printf("\nNenhum professor com esse sexo.");
        printf("\n-------------------------------");
    }
}

void listTeachersBybirthDate()
{
    printf("Digite a data de aniversario (DDMMAAAA) do professor que deseja buscar: \n");
    printf(">> ");
    int lDataAniversario;
    fgets(buffer, sizeof(buffer), stdin);
    scanf(buffer, "%d", &lDataAniversario);

    int lCont = 0;

    for (int i = 0; i < teacherQnt; i++)
    {
        if (teachers[i].birthDate == lDataAniversario)
        {
            printf("\n-------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %ld \nData de Nascimento: %d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDate, teachers[i].sex, teachers[0].cargo);
            printf("\n-------------------------------------");
            lCont++;
        }
    }
    if (lCont == 0)
    {
        printf("\n----------------------------------------------");
        printf("\nNenhum professor com essa data de aniversario.");
        printf("\n----------------------------------------------");
    }
}
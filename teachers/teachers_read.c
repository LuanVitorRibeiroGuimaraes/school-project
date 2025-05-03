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
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d/%d/%d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDay, teachers[i].birthMonth, teachers[i].birthYear, teachers[i].sex, teachers[0].cargo);
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
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d/%d/%d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDay, teachers[i].birthMonth, teachers[i].birthYear, teachers[i].sex, teachers[0].cargo);
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
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d/%d/%d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDay, teachers[i].birthMonth, teachers[i].birthYear, teachers[i].sex, teachers[0].cargo);
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
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d/%d/%d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDay, teachers[i].birthMonth, teachers[i].birthYear, teachers[i].sex, teachers[0].cargo);
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
    int lDay, lMonth, lYear;
    printf("\n >> Digite a data de aiversario do professor(a) que deseja buscar: ");
    printf("\n\n >> Dia (DD): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &lDay);

    printf("\n >> Mes (MM): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &lMonth);

    printf("\n >> Ano (AAAA): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &lYear);

    int lCont = 0;

    for (int i = 0; i < teacherQnt; i++)
    {
        if (teachers[i].birthDay == lDay && teachers[i].birthMonth == lMonth && teachers[i].birthYear == lYear)
        {
            printf("\n-------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d/%d/%d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDay, teachers[i].birthMonth, teachers[i].birthYear, teachers[i].sex, teachers[0].cargo);
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

void listTeacherByLetter()
{
    
    int lQtn;
    printf("\n----------------------------------");
    printf("\n >> Quantas Letras Deseja Filtrar?");
    printf("\n >> ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &lQtn);
    
    if(lQtn < 3){
        
        printf("\n----------------------------------");
        printf("\n[!] Digite no Minimo 3 Caracteres.");
        printf("\n----------------------------------");
        return;
    }

    char letter[lQtn];
    
    for (int i = 0; i < lQtn; i++) {
        printf("\n >> Digite a %do Letra: ", i + 1);
        letter[i] = getchar();
        getchar();
        letter[i] = toupper(letter[i]);
    }
    
    int found = 0;
    char firstLetter;
    
    for (int i = 0; i < teacherQnt; i++) {

        firstLetter = toupper(teachers[i].name[0]);

        for (int j = 0; j < lQtn; j++) {
            if (firstLetter == letter[j]) {
                printf("\n----------------------------------------------------------------------");
                printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d/%d/%d \nSexo: %c",
                    teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDay, teachers[i].birthMonth, teachers[i].birthYear, teachers[i].sex);
                printf("\n----------------------------------------------------------------------");
                found = 1;
                break;
            }
        }
    }
    
    if (!found)
    {
        printf("\n-----------------------------");
        printf("\n[!] Professor Nao Encontrado.");
        printf("\n-----------------------------");
    }
    
}

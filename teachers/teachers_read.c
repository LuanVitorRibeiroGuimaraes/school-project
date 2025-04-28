#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
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

int compararNomes(const void *a, const void *b) {
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
            printf("\n-------------------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %ld \nData de Nascimento: %d \nSexo: %c",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDate, toupper(teachers[i].sex));
            printf("\n-------------------------------------------------");
        }
    }
}

void listTeachersById(int pId)
{
    for (int i = 0; i < teacherQnt; i++)
    {
        if (teachers[i].teacherId == pId)
        {
            printf("\n-------------------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %ld \nData de Nascimento: %d \nSexo: %c",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDate, toupper(teachers[i].sex));
            printf("\n-------------------------------------------------");
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

void listTeachersByName(char pName[]){
    int lCont = 0;

    qsort(teachers, teacherQnt, sizeof(Teacher), compararNomes);

    for(int i = 0; i < teacherQnt; i++){
        if(strcmp(teachers[i].name, pName) == 0){
            printf("\n-------------------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %ld \nData de Nascimento: %d \nSexo: %c",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDate, toupper(teachers[i].sex));
            printf("\n-------------------------------------------------");
            lCont++;
        }
    }
    if(lCont == 0){
        printf("\n--------------------------------------------");
        printf("\nNome nao encontrado."); 
        printf("\n--------------------------------------------");
    }

}

void listTeachersBySex(char pSex[]){
    int lCont = 0;
    for(int i = 0; i < teacherQnt; i++){
        if(strcmp(teachers[i].sex, pSex) == 0){
            printf("\n-------------------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %ld \nData de Nascimento: %d \nSexo: %c",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDate, toupper(teachers[i].sex));
            printf("\n-------------------------------------------------");
            lCont++;
        }
    }
    if(lCont == 0){
        printf("\n--------------------------------------------");
        printf("\nNenhum professor com esse sexo."); 
        printf("\n--------------------------------------------");
    }

}


void listTeachersBybirthDate(int pDataAniversario){
    int lCont = 0;

    for(int i = 0; i < teacherQnt; i++){
        if(strcmp(teachers[i].birthDate, pDataAniversario) == 0){
            printf("\n-------------------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %ld \nData de Nascimento: %d \nSexo: %c",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDate, toupper(teachers[i].sex));
            printf("\n-------------------------------------------------");
            lCont++;
        }
    }
    if(lCont == 0){
        printf("\n--------------------------------------------");
        printf("\nNenhum professor com essa data de aniversario."); 
        printf("\n--------------------------------------------");
    }
}
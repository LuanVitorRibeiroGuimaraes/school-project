#include <stdio.h>
#include <stdlib.h>
#include "teachers.h"

char buffer[100];

void excluirProfessor(){
    listTeachers();

    while (1)
    {
    printf("\nDigite a matricula do professor no qual voce quer excluir:");
    printf("\n>> ");
    int lId;
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &lId);

    for(int i = 0; i < teacherQnt; i++){

        if(teachers[i].teacherId == lId){
            for (int j = 0; j < teachers[i].assignedSubjectsQnt; j++) 
            {
                teachers[i].assignedSubjects[j] = -1;
            }

            for(int j = i; j < teacherQnt - 1; j++){
                teachers[j] = teachers[j+1];
            }
            teacherQnt--;
            printf("\n-------------------------------");
            printf("\nProfessor Excluido com Sucesso!");
            printf("\n-------------------------------");
            return;
        }
    }
    printf("\n-------------------------------------------------");
    printf("\nMatricula Incorreta, Por Favor, Digite Novamente.");
    printf("\n-------------------------------------------------");
    continue;
    }
}
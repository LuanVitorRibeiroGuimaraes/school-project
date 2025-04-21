#include <stdio.h>
#include <stdlib.h>
#include "teachers.h"

char buffer[100];

void excluirProfessor(){
    listTeachers();
    printf("\n Digite a matricula do professor no qual voce quer excluir:");
    printf("\n>> ");
    int lId;
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &lId);

    for(int i = 0; i < teacherQnt; i++){

        if(teachers[i].teacherId == lId){
            // fazer ainda
            printf("\nProfessor Excluido com Sucesso!"); 
            break;
        }
    }
    printf("\nMatricula Incorreta, Por Favor, Digite Novamente.\n");
}
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
            for(int j = i; j < teacherQnt - 1; j++){
                teachers[j] = teachers[j+1];
            }
            teacherQnt--;
            printf("\nProfessor Excluido com Sucesso!"); 
            return;
        }
    }
    printf("\nMatricula Incorreta, Por Favor, Digite Novamente.\n");
}
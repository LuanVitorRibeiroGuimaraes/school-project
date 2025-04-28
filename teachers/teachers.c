#include <stdio.h>
#include <stdlib.h>
#include "teachers.h"
#include "../validators/validators.h"

#define SIZE_PROFESSORES 100

teacherQnt = 0;
Teacher teachers[SIZE_PROFESSORES]; 

void createTeacher(){
    int teacherId; 
    char name[100];
    char sex;
    int birthDate;
    long cpf;

    if(teacherQnt == SIZE_PROFESSORES){
        printf("\nNao eh possivel cadastrar mais professores!");
    }

    char buffer[100];

    printf("Digite a matricula do professor: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &teacherId);
    for(int i = 0; i < teacherQnt; i++){
        if(teachers[i].teacherId == teacherId){
            printf("\nJa Existe um Professor Com Essa Matricula!\n");
            return;
        }
    }

    printf("Digite o nome do professor: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';


    printf("Digite o sexo do professor (F ou M): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%c", &sex);


    printf("Digite a data de aiversario (dd/mm/aaaa): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &birthDate);


    printf("Digite o CPF do professor: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%ld", &cpf);
    //validateCpf(cpf);

    teachers[teacherQnt].teacherId = teacherId;
    strcpy(teachers[teacherQnt].name, name);
    teachers[teacherQnt].sex = sex;
    teachers[teacherQnt].birthDate = birthDate;
    teachers[teacherQnt].cpf = cpf;

    teacherQnt ++;

    printf("Professor cadastrado com sucesso!\n");

}

#include <string.h>

>>>>>>>>> Temporary merge branch 2

#include <stdio.h>
#include <stdlib.h>
#include "teachers.h"
#include "../validators/validators.h"

#define SIZE_PROFESSORES 100

teacherQnt = 0;
Teacher teachers[SIZE_PROFESSORES]; 

#pragma region CRIAR PROFESSOR
void createTeacher(){
    int teacherId; 
    char name[100];
    char sex;
    int birthDate;
    long cpf;

    if(teacherQnt == SIZE_PROFESSORES){
        printf("\nNao eh possivel cadastrar mais alunos!");
    }

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &teacherId);

    getchar();

    printf("Digite o nome do professor: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';


    printf("Digite o sexo do professor (F ou M): ");
    scanf("%c", &sex);

    getchar();

    printf("Digite a data de aiversario: ");
    scanf("%d", &birthDate);

    getchar();

    printf("Digite o CPF do professor: ");
    scanf("%ld", &cpf);
    validateCpf(cpf);

    teachers[teacherQnt].studentId = teacherId;
    strcpy(teachers[teacherQnt].name, name);
    teachers[teacherQnt].sex = sex;
    teachers[teacherQnt].birthDate = birthDate;
    teachers[teacherQnt].cpf = cpf;

    teacherQnt ++;

    printf("Professor cadastrado com sucesso!\n");
}
#pragma endregion

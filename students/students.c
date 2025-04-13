#include <stdio.h>
#include <string.h>

#include "students.h"
#include "../validators/validators.h"

#define SIZE_STUDENTS 100
    
int studentQnt = 0;
Students students[SIZE_STUDENTS];

void createStudent()
{

    int studentId; 
    char name[100];
    char sex;
    int birthDate;
    long cpf;

    if (studentQnt == SIZE_STUDENTS)
    {
        printf("Nao e possuivel cadastrar mais alunos!");
    }

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &studentId);

    getchar();

    printf("Digite o nome do usuario: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';


    printf("Digite o sexo do aluno: ");
    scanf("%c", &sex);

    getchar();

    printf("Digite a data de aiversario: ");
    scanf("%d", &birthDate);

    getchar();

    printf("Digite o CPF do aluno: ");
    scanf("%ld", &cpf);
    validateCpf(cpf);

    //em C, strings são arrays de caracteres, e você não pode atribuir arrays diretamente assim
    //é preciso copiar o conteúdo de uma string para outra


    students[studentQnt].studentId = studentId;
    strcpy(students[studentQnt].name, name);
    students[studentQnt].sex = sex;
    students[studentQnt].birthDate = birthDate;
    students[studentQnt].cpf = cpf;

    studentQnt+= 1;

    printf("Aluno cadastrado com sucesso!\n");
}

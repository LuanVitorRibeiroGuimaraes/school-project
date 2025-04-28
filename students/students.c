#include "students.h"
// #include "../validators/validators.h"
// #include "../validators/validators.h"

//precisa testar

int studentQnt = 0;
Students students[SIZE_STUDENTS];

void createStudent() //adicionar verificar se campo está vazio ou não
{

    bool active = true;
    int studentId; 
    char name[100];
    char sex;
    char birthDate[10];
    char cpf[14];


    if (studentQnt == SIZE_STUDENTS)
    {
        printf("Nao e possuivel cadastrar mais alunos!");
        return;
    }

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &studentId);
    getchar();

    printf("Digite o nome do aluno: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; //trocar o \n do final pelo \0

    printf("Digite o sexo do aluno: ");
    scanf("%c", &sex);
    getchar();

    printf("Digite a data de aiversario: ");
    fgets(birthDate, sizeof(birthDate), stdin);
    birthDate[strcspn(birthDate, "\n")] = '\0';

    printf("Digite o CPF do aluno: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0'; //trocar o \n do final pelo \0
    // validateCpf(cpf);


    students[studentQnt].studentId = studentId;
    strcpy(students[studentQnt].name, name);
    students[studentQnt].sex = sex;
    strcpy(students[studentQnt].birthDate, birthDate);
    students[studentQnt].active = active;
    strcpy(students[studentQnt].cpf, cpf);

    studentQnt+= 1;

    printf("Aluno cadastrado com sucesso!\n");
}
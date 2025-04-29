#include "students.h"

int studentQnt = 0;
Students students[SIZE_STUDENTS];

void createStudent() //adicionar verificar se campo está vazio ou não
{

    if (studentQnt == SIZE_STUDENTS)
    {
        printf("\nNao e possivel cadastrar mais alunos!\n");
        return;
    }

    bool active = true;
    int studentId; 
    char name[100];
    char upper;
    char sex;
    int birthDate;
    long cpf;

    printf("Digite a data de aiversario: ");
    scanf("%d", &birthDate);
    getchar();

    printf("Digite o CPF do aluno: ");
    scanf("%ld", &cpf);
    getchar();

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &studentId);
    validateStudentId(studentId);

    getchar();

    printf("Digite o nome do aluno: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; //trocar o \n do final pelo \0
    toUpperCase(name);

    while (true)
    {
        printf("\nDigite o sexo do aluno: ");
        scanf(" %c", &sex);

        if (validateSex(sex) == 0)
            break;
    }

    students[studentQnt].studentId = studentId;
    strcpy(students[studentQnt].name, name);
    students[studentQnt].sex = sex;
    students[studentQnt].birthDate = birthDate;
    students[studentQnt].active = active;
    students[studentQnt].cpf = cpf;

    studentQnt+= 1;

    printf("\n---------------------------------");
    printf("\nAluno cadastrado com sucesso!");
    printf("\n---------------------------------");
    return;
}

void toUpperCase(char *name)
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        name[i] = toupper((unsigned char) name[i]);
    }
}
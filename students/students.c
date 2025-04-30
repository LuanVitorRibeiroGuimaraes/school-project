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
    char cpf[15];

    char buffer[100];

    printf("\n >>Digite a data de aniversario (DDMMAAAA): ");
    scanf("%d", &birthDate);
    getchar();

    while (true)
    {
        printf("\n >>Digite o CPF do aluno: ");
        fgets(cpf, sizeof(cpf), stdin);
        cpf[strcspn(cpf, "\n")] = '\0'; //trocar o \n do final pelo \0

        if (validateCpf(cpf))
            break;
        else
            printf("\nCpf invalido! Tente novamente!\n");
    }

    while (true)
    {

        printf("\n >>Digite a matricula do aluno: ");
        fgets(buffer, sizeof(buffer), stdin);

        if (sscanf(buffer, "%d", &studentId) != 1 || studentId <= 0)
        {
            printf("\n----------------------------------------");
            printf("\nDigite Somente Numeros Maiores Que Zero!");
            printf("\n----------------------------------------");
            continue;
        }

        if (validateStudentId(studentId) == 0)
            break;
    }
    

    printf("\n >>Digite o nome do aluno: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; //trocar o \n do final pelo \0
    toUpperCase(name);

    while (true)
    {
        printf("\n >>Digite o sexo do aluno (F ou M): ");
        scanf(" %c", &sex);

        if (validateSex(sex) == 0)
            break;
    }

    students[studentQnt].studentId = studentId;
    strcpy(students[studentQnt].name, name);
    students[studentQnt].sex = sex;
    students[studentQnt].birthDate = birthDate;
    students[studentQnt].active = active;
    strcpy(students[studentQnt].cpf, cpf);

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
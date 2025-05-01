#include "students.h"

int studentQnt = 0;
Students students[SIZE_STUDENTS];

void createStudent()
{

    if (studentQnt == SIZE_STUDENTS)
    {
        printf("\n-----------------------------------------");
        printf("\n[!] Nao e possivel cadastrar mais alunos!");
        printf("\n-----------------------------------------");
        return;
    }

    bool active = true;
    int studentId; 
    char name[100];
    char upper;
    char sex;
    int day, month, year;
    char cpf[15];
    char buffer[100];

    printf("\nDigite a data de nascimento do aluno:");

    while (true)
    {
        printf("\n >> Dia (DD): ");
        scanf("%d", &day);

        printf("\n >> Mes (MM): ");
        scanf("%d", &month);

        printf("\n >> Ano (AAAA): ");
        scanf("%d", &year);

        if (validateData(day, month, year))
            break;
        else
        {
            printf("\n-----------------------------------");
            printf("\n[!] Data Invalida! Tente Novamente!");
            printf("\n-----------------------------------");
            continue;
        }
    }

    while (true)
    {
        printf("\n >> Digite o CPF do aluno: ");
        fgets(cpf, sizeof(cpf), stdin);
        cpf[strcspn(cpf, "\n")] = '\0';

        if (validateCpf(cpf))
            break;
        else
        {
            printf("\n----------------------------------");
            printf("\n[!] CPF Invalido! Tente Novamente!");
            printf("\n----------------------------------");
        }
    }

    while (true)
    {

        printf("\n >> Digite a matricula do aluno: ");
        fgets(buffer, sizeof(buffer), stdin);

        if (sscanf(buffer, "%d", &studentId) != 1 || studentId <= 0)
        {
            printf("\n--------------------------------------------");
            printf("\n[!] Digite Somente Numeros Maiores Que Zero!");
            printf("\n--------------------------------------------");
            continue;
        }

        if (validateStudentId(studentId) == 0)
            break;
    }
    

    printf("\n >> Digite o nome do aluno: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    toUpperCase(name);

    while (true)
    {
        printf("\n >> Digite o sexo do aluno (F ou M): ");
        scanf(" %c", &sex);

        if (validateSex(sex) == 0)
            break;
    }

    students[studentQnt].studentId = studentId;
    strcpy(students[studentQnt].name, name);
    students[studentQnt].sex = sex;
    students[studentQnt].birthDay = day;
    students[studentQnt].birthMonth = month;
    students[studentQnt].birthYear = year;
    students[studentQnt].active = active;
    strcpy(students[studentQnt].cpf, cpf);

    studentQnt+= 1;

    printf("\n-----------------------------");
    printf("\nAluno Cadastrado Com Sucesso!");
    printf("\n-----------------------------");
    return;
}

void toUpperCase(char *name)
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        name[i] = toupper((unsigned char) name[i]);
    }
}
#include "students.h"

//testar todos os métodos

void listStudents() //funcionando
{
    bool exist;

    if (studentQnt == 0)
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados!");
        printf("\n---------------------------------------------------\n");
        return;
    }

    for (int i = 0; i < studentQnt; i++)
    {
        printf("\n-------------------------------------");
        printf("\nNome: %s \nMatricula: %d \nCPF: %ld \nData de Nascimento: %d \nSexo: %c",students[i].name, students[i].studentId, students[i].cpf, students[i].birthDate, students[i].sex);
        printf("\n-------------------------------------");
        exist = true;
    }

    if (!exist)
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados com essa letra!\n");
        printf("\n----------------------------------------------------\n");
    }
}

void listStudentsById() //funcionando
{
    if (studentQnt == 0)
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados!");
        printf("\n---------------------------------------------------\n");
        return;
    }

    int id;
    bool exist = true;

    printf("Digite a matricula do aluno que deseja consultar: ");
    printf("\n>> ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].studentId == id && students[i].active)
        {
            printf("\n-------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %ld \nData de Nascimento: %d \nSexo: %c",students[i].name,    students[i].studentId, students[i].cpf, students[i].birthDate, students[i].sex);
            printf("\n-------------------------------------");
            exist = true;
            break;
        }
    }

    if (!exist)
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados com essa letra!\n");
        printf("\n----------------------------------------------------\n");
    }
}

void listStudentsByLetter() //funcionando
{
    if (studentQnt == 0)
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados!");
        printf("\n---------------------------------------------------\n");
        return;
    }

    int qtn;
    bool exist = true;

    printf("Quantas letras deseja filtrar? ");
    printf("\n>> ");
    scanf("%d", &qtn);
    getchar();

    char letter[qtn];

    for (int i = 0; i < qtn; i++)
    {
        printf("Digite a %do letra: ", i+1);
        scanf("%c", &letter[i]);
    }

    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].name[0] == letter[i] && students[i].active)
        {
            printf("\n-------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %ld \nData de Nascimento: %d \nSexo: %c",students[i].name,    students[i].studentId, students[i].cpf, students[i].birthDate, students[i].sex);
            printf("\n-------------------------------------");
            exist = true;
        }
    }

    if (!exist)
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados com essa letra!\n");
        printf("\n----------------------------------------------------\n");
    }
}

void listStudentsBySex() //funcionando
{
    if (studentQnt == 0)
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados!");
        printf("\n---------------------------------------------------\n");
        return;
    }

    char sex;
    bool exist = true;

    while (true)
    {
        printf("Digite o sexo ('M' ou 'F') para filtrar os alunos: ");
        printf("\n>> ");
        scanf(" %c", &sex);

        if (validateSex(sex) == 0)
            break;
    }
        
    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].sex == sex && students[i].active)
            printf("\n-------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %ld \nData de Nascimento: %d \nSexo: %c",students[i].name,        students[i].studentId, students[i].cpf, students[i].birthDate, students[i].sex);
            printf("\n-------------------------------------");
            exist = true;
    }

    if (!exist)
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados!\n");
        printf("\n---------------------------------------------------\n");
        return;
    }
}

void listStudentsBybirthDate()
{
    if (studentQnt == 0)
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados!\n");
        printf("\n---------------------------------------------------\n");
        return;
    }
}
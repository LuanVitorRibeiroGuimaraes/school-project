#include "students.h"

//testar todos os métodos

void listStudents()
{
    if (studentQnt == 0)
    {
        printf("Nao ha alunos cadastrados");
        return;
    }

    for (int i = 0; i < studentQnt; i++)
    {
        printf("Nome: %s, matricula: %d\n", students[i].name, students[i].studentId);
    }
}

void listStudentsById()
{
    int id;

    printf("Digite a matricula do aluno que deseja consultar: ");
    printf("\n>> ");
    scanf("%d", &id);
    getchar();

    if (studentQnt == 0)
    {
        printf("Nao ha alunos cadastrados");
        return;
    }

    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].studentId == id && students[i].active)
        {
            printf("Aluno: %s, matricula: %d, sexo: %c, data nascimento: %s.\n", students[i].name, students[i].studentId, students[i].sex, students[i].birthDate);
            break;
        }
    }
}

void listStudentsByLetter() //testar
{
    int qtn;

    printf("Quantas letras deseja filtrar? ");
    printf("\n>> ");
    scanf("%d", &qtn);
    getchar();

    char letter[qtn];

    if (studentQnt == 0)
    {
        printf("Nao ha alunos cadastrados!\n");
        return;
    }

    for (int i = 0; i < qtn; i++)
    {
        printf("Digite a %d letra: ", i+1);
        scanf("%c", &letter[i]);
    }

    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].name[0] == letter[i] && students[i].active)
            printf("Aluno: %s, matricula: %d, sexo: %c, data nascimento: %s.\n", students[i].name, students[i].studentId, students[i].sex, students[i].birthDate);
    }
}

void listStudentsBySex()
{
    char sex;

    printf("Digite o sexo ('M' ou 'F') para filtrar os alunos: ");
    printf("\n>> ");
    scanf("%c", &sex);
    getchar();

    if (studentQnt == 0)
    {
        printf("Nao ha alunos cadastrados");
        return;
    }

    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].sex == sex && students[i].active)
            printf("Aluno: %s, matricula: %d, sexo: %c, data nascimento: %s.\n", students[i].name, students[i].studentId, students[i].sex, students[i].birthDate);
    }
}

void listStudentsBybirthDate()
{
    printf("falta implementar");
}

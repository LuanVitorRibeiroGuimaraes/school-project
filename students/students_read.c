#include "students.h"

//testar todos os métodos

void listStudents()
{
    for (int i = 0; i < studentQnt; i++)
    {
        printf("Nome: %s, matricula: %d\n", students[i].name, students[i].studentId);
    }
}

void listStudentsById()
{
    int id;

    printf("Digite a matricula do aluno que deseja consultar: ");
    scanf("%d", &id);

    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].studentId == id && students[i].active)
        {
            printf("Aluno: %s, matricula: %d, sexo: %c, data nascimento: %s.\n", students[i].name, students[i].studentId, students[i].sex, students[i].birthDate);
            break;
        }
    }
}

void listStudentsByLetter()
{
    int qtn;

    printf("Quantas letras deseja filtrar ? ");
    scanf("%d", &qtn);

    char letter[qtn];

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
    scanf("%c", &sex);

    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].sex == sex && students[i].active)
            printf("Aluno: %s, matricula: %d, sexo: %c, data nascimento: %s.\n", students[i].name, students[i].studentId, students[i].sex, students[i].birthDate);
    }
}

void listStudentsBybirthDate()
{
    //
}

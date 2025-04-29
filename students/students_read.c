#include "students.h"

//testar todos os métodos

void listStudents() //funcionando
{
    if (studentQnt == 0)
    {
        printf("----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados!");
        return;
        printf("----------------------------------------------------\n");
    }

    for (int i = 0; i < studentQnt; i++)
    {
        printf("Nome: %s, matricula: %d\n", students[i].name, students[i].studentId);
    }
}

void listStudentsById() //funcionando
{
    if (studentQnt == 0)
    {
        printf("----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados");
        printf("----------------------------------------------------\n");
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
            printf("---------------------------------------------------------\n");
            printf("Aluno: %s, matricula: %d, sexo: %c, data nascimento: %s.\n", students[i].name, students[i].studentId, students[i].sex, students[i].birthDate);
            printf("---------------------------------------------------------\n");
            exist = true;
            break;
        }
    }

    if (!exist)
    {
        printf("----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados com esse id!\n");
        printf("----------------------------------------------------\n");
    }
}

void listStudentsByLetter() //funcionando
{
    if (studentQnt == 0)
    {
        printf("----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados!\n");
        printf("----------------------------------------------------\n");
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
        printf("Digite a %d letra: ", i+1);
        scanf("%c", &letter[i]);
    }

    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].name[0] == letter[i] && students[i].active)
        {
            printf("----------------------------------------------------\n");
            printf("Aluno: %s, matricula: %d, sexo: %c, data nascimento: %s.\n", students[i].name, students[i].studentId, students[i].sex, students[i].birthDate);
            printf("----------------------------------------------------\n");
            exist = true;
        }
    }

    if (!exist)
    {
        printf("----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados com essa letra!\n");
        printf("----------------------------------------------------\n");
    }
}

void listStudentsBySex() //nao printa nada
{
    if (studentQnt == 0)
    {
        printf("----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados");
        printf("----------------------------------------------------\n");
        return;
    }

    char sex;
    bool exist = true;

    do
    {
        printf("Digite o sexo ('M' ou 'F') para filtrar os alunos: ");
        printf("\n>> ");
        scanf("%c", &sex);
        getchar();
    }
    while (sex != 'M' || sex != 'm' || sex != 'F' || sex != 'f');

    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].sex == sex && students[i].active)
            printf("----------------------------------------------------\n");
                printf("Aluno: %s, matricula: %d, sexo: %c, data nascimento: %s.\n", students[i].name, students[i].studentId, students[i].sex, students[i].birthDate);
            printf("----------------------------------------------------\n");
            exist = true;
    }

    if (!exist)
    {
        printf("----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados com esse sexo!\n");
        printf("----------------------------------------------------\n");
    }
}

void listStudentsBybirthDate()
{
    printf("falta implementar");
}

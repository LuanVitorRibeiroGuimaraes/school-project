#include "students.h"


void updateStudent()
{
    int id;
    int find;
    char name[100];
    char date[100];

    printf("Digite a matricula do aluno que deseja atualizar: ");
    scanf("%d", &id);

    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].studentId == id && students[i].active)
        {
            printf("Digite o nome: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            getchar();

            printf("Digite a data de nascimento: ");
            fgets(date, sizeof(date), stdin);
            date[strcspn(date, "\n")] = '\0';

            strcpy(students[i].name, name);
            strcpy(students[i].birthDate, date);
        }
    }
}
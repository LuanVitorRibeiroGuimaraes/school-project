#include "students/students.h"


void updateStudent(int id)
{
    char name[100];
    int birthDate;

    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].studentId == id)
        {
            printf("Digite o nome do aluno: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            printf("Digite a data de nascimento do aluno: ");
            scanf("%d", &birthDate);

            strcpy(students[i].name, name);
            students[i].birthDate = birthDate;
        }
        printf("Usuario atualizado com sucesso!\n");
        break;
    }
}
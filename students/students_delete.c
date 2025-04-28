#include "students.h"

void deleteStudentById()
{
    int id;
    bool find = false;
    int position;

    printf("Digite a matricula do aluno que deseja deletar: ");
    scanf("%d", &id);

    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].studentId == id && students[i].active)
            find = true;
            position = i;
            students[i].active = false;
            break;
    }

        if (find)
        {
            for (int i = 0; i < studentQnt - 1; i++) //aplicando o shift
            {
                students[i].studentId = students[i+1].studentId;
                strcpy(students[i].name, students[i+1].name);
                students[i].sex = students[i+1].sex;
                strcpy(students[i].birthDate, students[i+1].birthDate);
                strcpy(students[i].cpf, students[i+1].cpf);
            }
            studentQnt--;
        }

        printf("\nEstudante nao encontrado.");
}
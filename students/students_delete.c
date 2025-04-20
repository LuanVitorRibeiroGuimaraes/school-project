#include "students.h"

//Precisa testar
//precisa melhorar a lógica do encontrar aluno


void deleteStudentById()
{
    int id;
    int find = 0;
    int position;

    printf("Digite a matricula do aluno que deseja deletar: ");
    scanf("%d", &id);

    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].studentId == id && students[i].active)
            for (int i = 0; i < studentQnt; i++)
            {
                find = 1;
                position = i;
                break;
            }

        if (find == 1)
        {
            for (int i = 0; i < students - 1; i++) //aplicando o shift
            {
                students[i].studentId = students[i+1].studentId;
                strcpy(students[i].name, students[i+1].name);
                students[i].sex = students[i+1].sex;
                strcpy(students[i].birthDate, students[i+1].birthDate);
                strcpy(students[i].cpf, students[i+1].cpf);
                students[i].active = false;
                studentQnt--;
                break;
            }
        }
    }
}
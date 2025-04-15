#include "students/students.h"

//Precisa testar

void deleteStudentById(int id)
{
    for (int i = 0; i < studentQnt; i++)
    {
        //melhorar lógica
        if (!students[i].active || students[i].studentId != id)
        {
            printf("Usuario nao encontrado!");
            break;
        }

        if (students[i].active)
        {
            for (int j = 0; j < studentQnt - 1; j++) //pegando o termo de trás e jogando para frente (shift)
            {
                students[i].studentId = students[i+1].studentId;
                strcpy(students[i].name, students[i+1].name);
                students[i].sex = students[i+1].sex;
                strcpy(students[i].cpf, students[i+1].cpf);
            }
        }
        printf("Aluno deletado!");
        break;
    }
}
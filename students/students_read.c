#include "students/students.h"

//testar todos os métodos

void listStudents()
{
    for (int i = 0; i < studentQnt; i++)
    {
        printf("Nome: %s, matricula: %d\n", students[i].name, students[i].studentId);
    }
}

void listStudentsById(int id)
{
    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].studentId == id)
        {
            printf("matricula: ,\n nome: %s, sexo: %c", students[i].studentId, students[i].name, students[i].sex);
            break;
        }
    }
}

void listStudentsByLetter()
{
    //
}

void listStudentsBySex(char sex)
{
    //
}

void listStudentsBybirthDate()
{
    //
}

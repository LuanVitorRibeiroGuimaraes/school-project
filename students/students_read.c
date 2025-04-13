#include <stdio.h>
#include "students.h"


void listStudents()
{
    for (int i = 0; i < studentQnt; i++)
    {
        printf("Nome: %s, matricula: %d\n", students[i].name, students[i].studentId);
    }
}

void listStudentsById()
{
    //
}

void listStudentsByName()
{
    //
}

void listStudentsBySex()
{
    //
}

void listStudentsBybirthDate()
{
    //
}

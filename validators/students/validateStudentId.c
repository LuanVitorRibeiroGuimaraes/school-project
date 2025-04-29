#include "validators.h"

int validateStudentId(int id)
{
    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].studentId == id)
        {
            printf("\n------------------------------------------");
            printf("\nJa Existe um Aluno Com Essa Matricula!");
            printf("\n------------------------------------------");
            return 1;
        }
    }

    return 0; 
}
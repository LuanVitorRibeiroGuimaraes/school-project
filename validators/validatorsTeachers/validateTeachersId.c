#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../teachers/teachers.h" 

int validateTeacherId(int pId)
{
    for (int i = 0; i < teacherQnt; i++)
    {
        if (teachers[i].teacherId == pId)
        {
            printf("\n------------------------------------------");
            printf("\nJa Existe um Professor Com Essa Matricula!");
            printf("\n------------------------------------------");
            return 1;
        }
    }

    return 0; 
}
#include "../validators.h"

int validateTeacherId(int id)
{
    for (int i = 0; i < teacherQnt; i++)
    {
        if (teachers[i].teacherId == id)
        {
            printf("\n------------------------------------------");
            printf("\nJa Existe um Professor Com Essa Matricula!");
            printf("\n------------------------------------------");
            return 1;
        }
    }

    return 0; 
}
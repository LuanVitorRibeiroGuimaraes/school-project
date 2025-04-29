#include <stdio.h>
<<<<<<<<< Temporary merge branch 1

#include "../validators.h"
#include "../students.h"

int main()
{
    createStudent();
    listStudents();
}
=========
#include <locale.h>
#include "validators/validators.h"
#include "students/students.h"
#include "teachers/teachers.h"

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    teachersMenu();
    
    return 0;
}
>>>>>>>>> Temporary merge branch 2

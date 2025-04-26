#include <stdio.h>
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
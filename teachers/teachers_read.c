#include <stdio.h>>
#include "teachers.h"

void listTeachers(){
    for(int i = 0; i < teacherQnt; i++){
        printf("Nome: %s, matricula: %d\n", teachers[i].name, teachers[i].teacherId);
    }
}
#ifndef TEACHERS_H
#define TEACHERS_H
#include <stdbool.h>

//definindo o struct Teachers
typedef struct
{
    int teacherId; 
    char name[100];
    char sex;
    int birthDate;
    long cpf;
}Teacher;

extern int teacherQnt; 
extern Teacher teachers[];

void createTeacher(); // feito
void updateTeacher(); // feito
void listTeachers(); // feito
void listTeachersById(); // feito
void listStudentsByName();
void listTeachersBySex();
void listTeachersBybirthDate();
void excluirProfessor();
void teachersMenu(); // feito
bool isEmpityTeacher(); // feito

#endif

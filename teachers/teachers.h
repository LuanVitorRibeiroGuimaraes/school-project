#ifndef TEACHERS_H
#define TEACHERS_H
#include <stdbool.h>

#define MAX_SUBJECTS 8

//definindo o struct Teachers
typedef struct
{
    int teacherId; 
    char name[100];
    char sex;
    char cpf[15];
    char cargo[15];
    int assignedSubjects[MAX_SUBJECTS];
    int assignedSubjectsQnt;
    int birthDay;
    int birthMonth;
    int birthYear;
}Teacher;

extern int teacherQnt; 
extern Teacher teachers[];

void createTeacher(); // feito
void updateTeacher(); // feito
void listTeachers(); // feito
void listTeachersById(); // feito
void listTeachersByName(); // feito 
void listTeachersBySex(); // feito
void listTeachersBybirthDate(); // feito FALTA VALIDAR 
void excluirProfessor(); // feito
void teachersMenu(); // feito
void listTeacherByLetter(); // feito
bool isEmpityTeacher(); // feito

#endif

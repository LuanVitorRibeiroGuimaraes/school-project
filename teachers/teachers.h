#ifndef TEACHERS_H
#define TEACHERS_H

//definindo o struct Teachers
typedef struct
{
    int teacherId; 
    char name[100];
    char sex;
    int birthDate;
    long cpf;
}Teacher;

//extern -> informa que a variável ou vetor foi criado e implementado em algum lugar
extern int teacherQnt; 
extern Teacher teachers[];

void createTeacher();
void updateTeacher();
void listTeachers();
void listTeachersById();
void listStudentsByName();
void listTeachersBySex();
void listTeachersBybirthDate();



#endif

#ifndef STUDENTS_SCHOOL_H
#define STUDENTS_SCHOOL_H

//definindo o struct Students
typedef struct
{
    int studentId; 
    char name[100];
    char sex;
    int birthDate;
    long cpf;
}Students;

//extern -> informa que a variável ou vetor foi criado e implementado em algum lugar
extern int studentQnt; 
extern Students students[];

void createStudent();
void updateStudent();
void createStudent();
void listStudents();
void listStudentsById();
void listStudentsByName();
void listStudentsBySex();
void listStudentsBybirthDate();

#endif

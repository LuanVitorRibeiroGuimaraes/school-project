#ifndef STUDENTS_SCHOOL_H
#define STUDENTS_SCHOOL_H

#define SIZE_STUDENTS 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//definindo o struct Students
typedef struct
{
    int studentId; 
    char* name;
    char sex;
    char* birthDate;
    char* cpf;
    bool active;
}Students;

//extern -> informa que a variável ou vetor foi criado e implementado em algum lugar
extern int studentQnt; 
extern Students students[];

void studentMenu(); //precisa testar
void createStudent(); //precisa testar
void updateStudent(); //precisa testar
void listStudents(); //precisa testar
void listStudentsById(); //precisa testar
void listStudentsByLetter(); //precisa testar
void listStudentsBySex(); //precisa testar
void listStudentsBybirthDate(); //precisa testar
void deleteStudentById(); //precisa testar

#endif

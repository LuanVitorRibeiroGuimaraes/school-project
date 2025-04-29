#ifndef STUDENTS_SCHOOL_H
#define STUDENTS_SCHOOL_H

#define SIZE_STUDENTS 100
#define MAX_SUBJECTS 8

#include "../subject/subject.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//definindo o struct Students
typedef struct
{
    int studentId; 
    char name[50];
    char sex;
    char birthDate[10];
    char cpf[14];
    bool active;
    int enrolledSubjects[MAX_SUBJECTS];
    int enrolledSubjectsQnt;
}Students;

//extern -> informa que a variável ou vetor foi criado e implementado em algum lugar
extern int studentQnt; 
extern Students students[];

void studentMenu(); //precisa testar
void createStudent(); //precisa testar
void updateStudent(); //precisa testar
void listStudents(); //working
void listStudentsById(); //precisa testar
void listStudentsByLetter(); //precisa testar
void listStudentsBySex(); //precisa testar
void listStudentsBybirthDate(); //precisa testar
void deleteStudentById(); //precisa testar

#endif

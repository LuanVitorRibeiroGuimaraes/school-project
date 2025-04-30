#ifndef STUDENTS_SCHOOL_H
#define STUDENTS_SCHOOL_H

#define SIZE_STUDENTS 100
#define MAX_SUBJECTS 8

#include "../validators/validators.h"
#include "../subject/subject.h"
#include "ctype.h"
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
    int birthDate;
    char cpf[15];
    bool active;
    int enrolledSubjects[MAX_SUBJECTS];
    int enrolledSubjectsQnt;
    int birthDay;
    int birthMonth;
    int birthYear;
}Students;

//extern -> informa que a variável ou vetor foi criado e implementado em algum lugar
extern int studentQnt; 
extern Students students[];

void studentMenu(); //falta testar
void createStudent(); //funcionando - faltando validador de cpf e aniversario
void updateStudent(); //funcionando
void listStudents(); //funcionando
void listStudentsById(); //funcionando
void listStudentsByLetter(); //funcionando
void listStudentsBySex(); //funcionando
void listStudentsByBirthDate();//funcionando
void deleteStudentById(); //funcionando
void toUpperCase(char *name); //funcionando

#endif

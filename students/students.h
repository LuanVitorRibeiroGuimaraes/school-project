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
    char name[100];
    char sex;
    char birthDate[10];
    char cpf[14];
    bool active = true;
}Students;

//extern -> informa que a variável ou vetor foi criado e implementado em algum lugar
extern int studentQnt; 
extern Students students[];

void studentMenu(); //precisa testar
void createStudent(); //precisa testar
void updateStudent(int id); //precisa testar
void createStudent(); //precisa testar
void listStudents(); //precisa testar
void listStudentsById(int id); //precisa testar
void listStudentsByLetter(); //precisa testar
void listStudentsBySex(char sex); //precisa testar
void listStudentsBybirthDate(); //precisa testar
void deleteStudentById(int id); //precisa testar

#endif

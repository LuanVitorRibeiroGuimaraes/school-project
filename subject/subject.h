#ifndef SUBJECTS_SCHOOL_H
#define SUBJECTS_SCHOOL_H
#include "../teachers/teachers.h"
#include "../students/students.h"
#include "../validators/validators.h"
#include <string.h>
#include <stdio.h>
#define SIZE_SUBJECTS 40

//definindo o struct Subjects
typedef struct
{
    char name[40];
    int subjectId; 
    int subjectSemester;
    int subjectEnrolledQnt;
}Subject;

extern Subject subjects[SIZE_SUBJECTS];

//extern -> informa que a variável ou vetor foi criado e implementado em algum lugar
extern int subjectQnt;
extern Subject subjects[];

void createSubject();
void updateSubject();
void deleteSubject();
void enrollStudent(); //Inserir aluno em uma disciplina
void unenrollStudent(); //Excluir aluno de uma disciplina
void listAllSubjects(); //dados das disciplinas sem os alunos
void listSubject(); // dados da disciplina e os alunos matriculados
void listLargeSubjects(); // Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas.
void listUnderEnrolledStudents(); // Lista de alunos matriculados em menos de 3 disciplinas
void subjectMainMenu();
void subjectRegisterMenu();
void subjectEnrollmentMenu();
void subjectListingMenu();

#endif

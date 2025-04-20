#ifndef SUBJECTS_SCHOOL_H
#define SUBJECTS_SCHOOL_H
#include "../teachers/teachers.h"

//definindo o struct Subjects
typedef struct
{
    char name[40];
    int subjectId; 
    int subjectSemester;
    Teacher subjectTeacher;
}Subject;

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
void listSubjectsWithMoreThan40Students(); // Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas.

#endif

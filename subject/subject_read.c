#include "subject.h"
#include <stdio.h>

void listAllSubjects()
{
    int i, j, k, teacherFinded = 0;
    char subjectTeacher[100];

    if(subjectQnt == 0) printf("Nenhuma disciplina encontrada.");

    else
    {
        printf
        (
            "------------------ LISTA DE DISCIPLINAS ------------------\n"
            "Codigo | Nome | Semestre | Professor\n"
            "----------------------------------------------------------\n"
        );
    
        for(i = 0; i < subjectQnt; i++)
        {
            for(j = 0; j < teacherQnt; j++)
            {
                for(k = 0; k < teachers[i].assignedSubjectsQnt; k++)
                {
                    if(subjects[i].subjectId = teachers[j].assignedSubjects[k])
                    {
                        strcpy(subjectTeacher, teachers[j].name);
                        teacherFinded = 1;
                    }
                }
                
            }
            if (teacherFinded == 0) strcpy(subjectTeacher, "Sem Professor Cadastrado");
            printf("%d | %s | %d | %s\n", subjects[i].subjectId, subjects[i].name, subjects[i].subjectSemester, subjectTeacher);
        }
    
        printf("----------------------------------------------------------\n");
    }
}

void listSubject()
{
    int i, findId, finded = 0;
    char subjectTeacher[100];

    if(subjectQnt == 0) printf("Nenhuma disciplina encontrada.");

    else
    {
        do
        {
            printf("Digite o codigo da disciplina que deseja listar: ");
            scanf("%d", findId);

            for(i = 0; i < teacherQnt; i++)
            {
                if(teachers[i].teacherId = findId)
                {
                    strcpy(subjectTeacher, teachers[i].name);
                }

                else strcpy(subjectTeacher, "Sem Professor Cadastrado");
            }
    
            for(i = 0; i < subjectQnt; i++)
            {
                if(subjects[i].subjectId == findId)
                {
                    printf("Disciplina: %s\tCodigo: %s\tSemestre: %d\tProf. %s", subjects[i].name, subjects[i].subjectId, subjects[i].subjectSemester, subjectTeacher);
                    printf("---------------------------------------------------------------\n");
                    printf("Aluno: %s | Matricula: %d"); //pendente
                    finded = 1;
                    break;
                }
            }
    
            if(!finded) printf("Codigo nao encontrado. Tente novamente.");
        }while (!finded);
    }

}

void listStudentEnrolledInLessThan3Subjects()
{
    int i, studentFinded = 0;

    printf("\n- LISTA DE ALUNOS MATRICULADOS EM MENOS DE 3 DISCIPLINAS -\n\n");

    for (i = 0; i < studentQnt; i++)
    {
        if (students[i].enrolledSubjectsQnt < 2)
        {
            printf("%d - %s\n", students[i].studentId, students[i].name);
            if (studentFinded == 0) studentFinded = 1;
        }
    }

    if(!studentFinded) printf("Nenhum aluno encontrado\n");

    printf("----------------------------------------------------------\n");

}

void listSubjectsWithMoreThan40Students()
{
    int i, j, k;
    char professor[100];

    printf("------ LISTA DE DISCIPLINAS QUE EXTRAPOLAM 40 VAGAS ------\n");

    for(i = 0;i < subjectQnt; i++)
    {
        if(subjects[i].subjectEnrolledQnt > 40)
        {
            for(j = 0; j < teacherQnt; j++)
            {
                for(k = 0; k < teachers[j].assignedSubjectsQnt; k++)
                {
                    if (teachers[j].assignedSubjects[k] == subjects[i].subjectId) strcpy(professor, teachers[j].name);                  
                }
                
            }
            
            printf("%d - %s - Professor: %s\n", subjects[i].subjectId, subjects[i].name, professor);
        }
    }

    printf("--------------------------------------------------- ------\n");
}


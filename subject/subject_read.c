#include "subject.h"

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

    return;
}

void listSubject()
{
    int i, j, k, findId, pos, finded = 0, studentsFinded = 0;
    char subjectTeacher[100];

    if(subjectQnt == 0) printf("Nenhuma disciplina encontrada.");

    else
    {
        do
        {
            printf("Digite o codigo da disciplina que deseja listar: ");
            findId = validateInt();

            if (findId == -1)
            {
                printf("Codigo da disciplina precisa ser um numero inteiro. Tente novamente.\n");
                continue;
            }

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
                    pos = i;
                    finded = 1;
                }
            }
                
            if(finded)
            {
                printf("Disciplina: %s\tCodigo: %s\tSemestre: %d\tProf. %s", subjects[pos].name, subjects[pos].subjectId, subjects[pos].subjectSemester, subjectTeacher);
                printf("---------------------------------------------------------------\n"); 
                printf("Aluno | Matricula");                   
                for (j = 0; j < studentQnt; j++)
                {
                    for (k = 0; k < students[j].enrolledSubjectsQnt; k++)
                    {
                        if(students[j].enrolledSubjects[k] == findId)
                        {
                            printf("%s | %d\n", students[j].name, students[j].studentId);
                            studentsFinded++;
                        }
                    }
                    if(subjects[i].subjectEnrolledQnt == studentsFinded) break;
                }
                printf("---------------------------------------------------------------\n");
            }
            
    
            if(!finded) printf("Codigo nao encontrado. Tente novamente.");
        }while (!finded);
    }
    
    return;
}

void listUnderEnrolledStudents()
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

    return;
}

void listLargeSubjects()
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

    return;
}


#include "subject.h"
#include <stdio.h>

void listAllSubjects()
{
    int i;

    if(subjectQnt == 0) printf("Nenhuma disciplina encontrada.");

    else
    {
        printf
        (
            "LISTA DE DISCIPLINAS"
            "Codigo | Nome | Semestre | Professor\n"
            "---------------------------------------------------------------\n"
        );
    
        for(i = 0; i < subjectQnt; i++)
        {
            printf("%d | %s | %d | %s\n", subjects[i].subjectId, subjects[i].name, subjects[i].subjectSemester, subjects[i].subjectTeacher);
        }
    
        printf("---------------------------------------------------------------\n");
    }
}

void listSubject()
{
    int i, findId, finded = 0;

    if(subjectQnt == 0) printf("Nenhuma disciplina encontrada.");

    else
    {
        do
        {
            printf("Digite o codigo da disciplina que deseja listar: ");
            scanf("%d", findId);
    
            for(i = 0; i < subjectQnt; i++)
            {
                if(subjects[i].subjectId == findId)
                {
                    printf("Disciplina: %s\tCodigo: %s\tSemestre: %d\tProf. %s", subjects[i].name, subjects[i].subjectId, subjects[i].subjectSemester, subjects[i].subjectTeacher);
                    printf("---------------------------------------------------------------\n");
                    printf("Aluno: %s | Matricula: %d", ); //pendente
                    finded = 1;
                    break;
                }
            }
    
            if(!finded) printf("Codigo nao encontrado. Tente novamente.");
        }while (!finded);
    }

}

void listSubjectsWithMoreThan40Students()
{
    int i;

    for(i = 0;i < subjectQnt; i++)
    {
        if()
    }
}
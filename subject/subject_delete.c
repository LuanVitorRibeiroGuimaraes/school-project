#include "subject.h"

deleteSubject()
{
    int findSubjectId, i, j, k, pos;
    int subjectFinded = 0;

    do
    {
        listAllSubjects();
        printf(
            "\n----------------- EXCLUIR DISCIPLINA ----------------"
            "\n >> Digite o codigo da disciplina que deseja excluir:"
            "\n-----------------------------------------------------"
        );
        findSubjectId = validateInt();
        
        if(findSubjectId == -1)
        {
            printf("\n------------------------------------------------------------------------");
            printf("\n[!] Codigo da Disciplina Precisa Ser um Numero Inteiro. Tente Novamente.");
            printf("\n------------------------------------------------------------------------");
            continue;
        }

        for(i = 0; i < subjectQnt; i++)
        {
            if(subjects[i].subjectId == findSubjectId)
            {
                pos = i;
                subjectFinded = 1;
                printf("\n-------------------------------------------");
                printf("\nDisciplina: %s excluida com sucesso!", subjects[i].name);
                printf("\n-------------------------------------------");
            }
        }
    
        if(subjectFinded)
        {
            for (i = 0; i < studentQnt; i++)
            {
                for (j = 0; j < students[i].enrolledSubjectsQnt; j++)
                {
                    if (students[i].enrolledSubjects[j] == findSubjectId)
                    {
                        for (k = j; k < students[i].enrolledSubjectsQnt - 1; k++)
                        {
                            students[i].enrolledSubjects[k] = students[i].enrolledSubjects[k+1];
                        }
                        students[i].enrolledSubjectsQnt--;
                        subjects[pos].subjectEnrolledQnt--;
                    }
                }

                if (subjects[pos].subjectEnrolledQnt == 0) break;
            }

            for (i = 0; i < teacherQnt; i++)
            {
                for (j = 0; j < teachers[i].assignedSubjectsQnt; j++)
                {
                    if (teachers[i].assignedSubjects[j] == findSubjectId)
                    {
                        for (k = j; k < teachers[i].assignedSubjectsQnt - 1; k++)
                        {
                            teachers[i].assignedSubjects[k] = teachers[i].assignedSubjects[k+1];
                        }
                        teachers[i].assignedSubjectsQnt--;
                        break;
                    }
                }
            }

            for (i = pos; i < subjectQnt - 1; i++)
            {
                subjects[i] = subjects[i+1];
            }
            subjectQnt--;

            return;          
        }
                           
        if(!subjectFinded){
            printf("\n-------------------------------------------");
            printf("\nDisciplina Nao Encontrada. Tente Novamente.");
            printf("\n-------------------------------------------");
        }   
    } while (!subjectFinded);
    
}
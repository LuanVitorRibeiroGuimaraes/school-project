#include "students.h"
#include "../subject/subject.h"

void deleteStudentById()
{
    if (studentQnt == 0)
    {
        printf("\n--------------------------");
        printf("\nNao ha alunos cadastrados!");
        printf("\n--------------------------");
        return;
    }

    int id;
    bool found;
    int position = false;
    int toDelete;
    int currentId;
    bool currentStatus;

    printf("\n-----------------------------------------------");
    printf("\nDigite a matricula do aluno que deseja deletar:");
    printf("\n>> ");
    scanf("%d", &id);
    printf("\n-----------------------------------------------");

    toDelete = id;

    for (int i = 0; i < studentQnt; i++)
    {
        currentId = students[i].studentId;
        currentStatus = students[i].active;

        if (toDelete == currentId && currentStatus)
        {
            position = i;
            found = true;
            printf("\n---------------------------------------");
            printf("\nAluno: %s, matricula: %d, foi deletado!", students[i].name, students[i].studentId);
            printf("\n---------------------------------------");
            currentStatus = false;
            break;
        }
    }

    if (found)
    {
        for (int i = 0; i < students[position].enrolledSubjectsQnt; i++)
        {
            for (int j = 0; j < subjectQnt ;j++)
            {
                if (students[position].enrolledSubjects[i] == subjects[j].subjectId)
                {
                    subjects[j].subjectEnrolledQnt--;
                    students[position].enrolledSubjects[i] = -1;
                }
            }    
        }
        
        for (int i = 0; i < studentQnt - 1; i++)
        {
            students[i] = students[i+1];
        }
        studentQnt--;
        return;
    }
    
    if (!found)
    {
        printf("\n---------------------");
        printf("\nAluno nao encontrado.");
        printf("\n---------------------");
    }
}


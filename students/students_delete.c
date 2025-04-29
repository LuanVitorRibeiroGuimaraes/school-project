#include "students.h"

void deleteStudentById() //últimos ajustes
{
    int id;
    bool find = false;
    int position;

    printf("\n---------------------------------------------------------\n");
    printf("Digite a matricula do aluno que deseja deletar: \n");
    printf(">> ");
    scanf("%d", &id);
    printf("\n---------------------------------------------------------\n");

    for (int i = 0; i < studentQnt; i++)
    {
        if (students[i].studentId == id && students[i].active)
            find = true;
            position = i;
            students[i].active = false;
            printf("Aluno: %s, matricula: %d: Deletado!", students[i].name, students[i].studentId);
            break;
    }

    if (find)
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
        
        for (int i = 0; i < studentQnt - 1; i++) //aplicando o shift
        {
            students[i] = students[i+1];
        }
        studentQnt--;
        return;
    }
    else
    {
        printf("\n---------------------------------------------\n");
        printf("\nAluno nao encontrado.");
        printf("\n---------------------------------------------\n");
    }
}


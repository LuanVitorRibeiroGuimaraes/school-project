#include "students.h"

void deleteStudentById() //funcionando
{
    if (studentQnt == 0) //ok
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados!");
        printf("\n---------------------------------------------------\n");
        return;
    }

    int id;
    bool found;
    int position = false;
    int toDelete;
    int currentId;
    bool currentStatus;

    printf("\n---------------------------------------------------------\n");
    printf("Digite a matricula do aluno que deseja deletar: \n");
    printf(">> ");
    scanf("%d", &id);
    printf("\n---------------------------------------------------------\n");

    toDelete = id;

    for (int i = 0; i < studentQnt; i++) //percorrendo o loop para encontrar o aluno
    {
        currentId = students[i].studentId;
        currentStatus = students[i].active;

        if (toDelete == currentId && currentStatus)
        {
            position = i;
            found = true;
            printf("\nAluno: %s, matricula: %d, foi deletado!", students[i].name, students[i].studentId);
            currentStatus = false;
            break;
        }
    }

        if (found)
        {
            for (int i = position; i < studentQnt - 1; i++) //aplicando o shift
            {
                students[i] = students[i+1];
            }
            studentQnt--;
            return;
        }
        
        if (!found)
        {
            printf("\n---------------------------------------------\n");
            printf("\nAluno nao encontrado.");
            printf("\n---------------------------------------------\n");
            return;
        }
}
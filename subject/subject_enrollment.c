#include "subject.h"

void enrollStudent()
{
    int findSubjectId, findStudentId;
    int i, j, findedSubject = 0, findedStudent = 0;

    do
    {
        printf("Digite o codigo da disciplina: ");
        scanf("%d", &findSubjectId);

        for(i = 0; i < subjectQnt; i++)
        {
            if(subjects[i].subjectId == findSubjectId)
            {
                printf("Matricular aluno na Disciplina: %s\n", subjects[i].name);
                do
                {
                    printf("Digite a matricula do aluno para registrar na disciplina: ");
                    scanf("%d", &findStudentId);

                    for(j = 0; j < studentQnt; j++)
                    {
                        if(students[j].studentId == findStudentId)
                        {
                            //Falta o comando para atribuir o codigo da disciplina ao estudante.
                            subjects[i].subjectEnrolledQnt++;
                            printf("Aluno matriculado com sucesso!");                           
                        }
                    }
                } while (!findedStudent);
                

            }
        }

        if(!findedSubject) printf("Disciplina nao encontrada. Tente novamente.\n");
    } while (!findedSubject);   
}

void unenrollStudent()
{

}
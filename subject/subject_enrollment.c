#include "subject.h"

void enrollStudent()
{
    int findSubjectId, findStudentId;
    int i, j, findedSubject = 0, findedStudent = 0;

    do
    {
        printf("\n >> Digite o codigo da disciplina: ");
        findSubjectId = validateInt();

        if (findStudentId == -1)
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
                printf("\n >> Matricular Aluno na Disciplina: %s", subjects[i].name);
                do
                {
                    printf("\n >> Digite a Matricula do Estudante Para Registrar na Disciplina: ");
                    findStudentId = validateInt();

                    if (findStudentId == -1)
                    {
                        printf("\n-------------------------------------------------------------------------");
                        printf("\n[!] Matricula do Estudante Precisa Ser um Numero Inteiro. Tente Novamente");
                        printf("\n-------------------------------------------------------------------------");
                        continue;
                    }

                    for(j = 0; j < studentQnt; j++)
                    {
                        if(students[j].studentId == findStudentId)
                        {
                            students[j].enrolledSubjects[students[i].enrolledSubjectsQnt];
                            students[j].enrolledSubjectsQnt++;
                            subjects[i].subjectEnrolledQnt++;
                            findedStudent = 1;
                            printf("\n------------------------------");
                            printf("\nAluno Matriculado Com Sucesso!");
                            printf("\n------------------------------");
                        }
                    }

                    if(!findedStudent){
                        printf("\n-------------------------------------------------------");
                        printf("\n[!] Matricula de Aluno Nao Encontrado. Tente Novamente.");
                        printf("\n-------------------------------------------------------");
                    } 
                } while (!findedStudent);
                
                findedSubject = 1;
            }
        }

        if(!findedSubject){
            printf("\n-----------------------------------------------");
            printf("\n[!] Disciplina Nao Encontrada. Tente Novamente.");
            printf("\n-----------------------------------------------");
        } 
    } while (!findedSubject);
    
    return;
}

void unenrollStudent()
{
    int findSubjectId, findStudentId, studentPosition, subjectPosition;
    int i, j, findedSubject = 0, findedStudent = 0;

    do
    {
        printf("\n >> Digite a Matricula do Estudante Para Remover de Uma Disciplina: ");
        findStudentId = validateInt();

        if (findStudentId == -1)
        {
            printf("\n--------------------------------------------------------------------------");
            printf("\n[!] Matricula do Estudante Precisa Ser um Numero Inteiro. Tente Novamente.");
            printf("\n--------------------------------------------------------------------------");
            continue;
        }

        for (i = 0; i < studentQnt; i++)
        {
            if (students[i].studentId == findStudentId)
                findedStudent = 1;
                studentPosition = i;
                break;
        }

        if(findedStudent)
        {
            if(students[studentPosition].enrolledSubjectsQnt == 0)
            {
                printf("\n--------------------------------------------------------------------");
                printf("\n[!] Matriculas Nao Encontradas Para Esse Estudante. Tente Novamente.");
                printf("\n--------------------------------------------------------------------"); 
                findedStudent = 0;
                continue;
            }

            else
                {
                    printf("\n------------------------------------------------");
                    printf("\nEstudante matriculado nas seguintes disciplinas:\n");
                    for (i = 0; i < students[studentPosition].enrolledSubjectsQnt; i++)
                    {
                        for(j = 0; j < subjectQnt; j++)
                        {
                            if(students[studentPosition].enrolledSubjects[i] = subjects[j].subjectId)
                            {
                                printf("%d - %s\n", students[studentPosition].enrolledSubjects[i], subjects[j].name);
                            } 
                        }
                        
                    }
                    printf("\n------------------------------------------------");
                    
                    do
                    {
                        printf("\n >> Digite o Codigo da Disciplina Para Desmatricular: ");
                        findSubjectId = validateInt();

                        if (findStudentId == -1)
                        {
                            printf("\n------------------------------------------------------------------------");
                            printf("\n[!] Codigo da Disciplina Precisa Ser um Numero Inteiro. Tente Novamente.");
                            printf("\n------------------------------------------------------------------------");
                            continue;
                        }

                        for (i = 0; i < students[studentPosition].enrolledSubjectsQnt; i++)
                        {
                            if (students[studentPosition].enrolledSubjects[i] == findSubjectId)
                                findedSubject = 1;
                                subjectPosition = i;
                                break;
                        }
                        
                        if(findedSubject)
                        {
                            for(i = subjectPosition; i < students[studentPosition].enrolledSubjectsQnt - 1; i++)
                            {
                                students[studentPosition].enrolledSubjects[i] = students[studentPosition].enrolledSubjects[i+1];
                                students[studentPosition].enrolledSubjectsQnt--;       
                            }
                            printf("\n---------------------------------");
                            printf("\nAluno desmatriculado com sucesso.");
                            printf("\n---------------------------------");
                        }

                        else{
                            printf("\n--------------------------------------");
                            printf("\n[!] Codigo Incorreto. Tente Novamente.");
                            printf("\n--------------------------------------");
                        } 
                    } while (!findedSubject);
                }
        }

        if(!findedStudent){
            printf("\n------------------------------------------");
            printf("\n[!] Aluno Nao Encontrado. Tente Novamente.");
            printf("\n------------------------------------------");
        } 
        
    } while (!findedStudent);

    return;
}
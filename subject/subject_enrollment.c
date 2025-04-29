#include "subject.h"

void enrollStudent()
{
    int findSubjectId, findStudentId;
    int i, j, findedSubject = 0, findedStudent = 0;

    do
    {
        printf("Digite o codigo da disciplina: ");
        findSubjectId = validateInt();

        if (findStudentId == -1)
        {
            printf("Codigo da disciplina precisa ser um numero inteiro. Tente novamente\n");
            continue;
        }

        for(i = 0; i < subjectQnt; i++)
        {
            if(subjects[i].subjectId == findSubjectId)
            {
                printf("Matricular aluno na Disciplina: %s\n", subjects[i].name);
                do
                {
                    printf("Digite a matricula do estudante para registrar na disciplina: ");
                    findStudentId = validateInt();

                    if (findStudentId == -1)
                    {
                        printf("Matricula do estudante precisa ser um numero inteiro. Tente novamente\n");
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
                            printf("Aluno matriculado com sucesso!");                         
                        }
                    }

                    if(!findedStudent) printf("Matricula de aluno nao encontrado. Tente novamente.\n");
                } while (!findedStudent);
                
                findedSubject = 1;
            }
        }

        if(!findedSubject) printf("Disciplina nao encontrada. Tente novamente.\n");
    } while (!findedSubject);
    
    return;
}

void unenrollStudent()
{
    int findSubjectId, findStudentId, studentPosition, subjectPosition;
    int i, j, findedSubject = 0, findedStudent = 0;

    do
    {
        printf("Digite a matricula do estudante para remover de uma disciplina: ");
        findStudentId = validateInt();

        if (findStudentId == -1)
        {
            printf("Matricula do estudante precisa ser um numero inteiro. Tente novamente\n");
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
                printf("Matriculas nao encontradas para esse estudante. Tente novamente\n");
                findedStudent = 0;
                continue;
            }

            else
                {
                    printf("Estudante matriculado nas seguintes disciplinas:\n");
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
                    
                    do
                    {
                        printf("Digite o codigo da disciplina para desmatricular: ");
                        findSubjectId = validateInt();

                        if (findStudentId == -1)
                        {
                            printf("Codigo da disciplina precisa ser um numero inteiro. Tente novamente\n");
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

                            printf("Aluno desmatriculado com sucesso.");
                        }

                        else printf("Codigo incorreto. Tente novamente.\n");
                    } while (!findedSubject);
                }
        }

        if(!findedStudent) printf("Aluno nao encontrado. Tente novamente.\n");
        
    } while (!findedStudent);

    return;
}
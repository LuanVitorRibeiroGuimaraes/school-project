#include <stdio.h>
#include "subject.h"
#include <string.h>

#define SIZE_SUBJECTS 40
int subjectQnt = 0;
Subject subjects[SIZE_SUBJECTS]; //mudar esses valores depois

void createSubject()
{
	char name[100];
    int subjectId; 
    int subjectSemester;
	int i, findId, registerTeacher, findedTeacher = 0, findedSubjectId = 1;
    
	if (subjectQnt == SIZE_SUBJECTS)
	{
		printf("Nao e possivel cadastrar mais disciplinas");
	}
	
	printf("Digite o nome da disciplina: ");
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = '\0';
	
	do
	{
		printf("Digite o codigo da disciplina: ");
		scanf("%d", &subjectId);

		for(i = 0; i < subjectQnt; i++)
		{
			if(subjects[i].subjectId == subjectId)
			{
				printf("Codigo ja cadastrado em outra disciplina. Tente novamente.\n");
				findedSubjectId = 0;
			}
		}
	} while (!findedSubjectId);
	
	
	
	printf("Digite o semestre da disciplina: ");
	scanf("%d", &subjectSemester);

	if(teacherQnt > 0)
	{	
		do
		{
			printf(
				"Deseja cadastrar um professor para a disciplina?\n"
				"0 - Nao\n"
				"1 - Sim\n"
			);
			registerTeacher = validateInt();
	
			switch(registerTeacher)
			{
				case 0:
					break;
	
				case 1:
					printf("Digite a matricula do professor que vai ministrar a disciplina: ");
					scanf("%d", &findId);
					
					for(i = 0; i < teacherQnt; i++) 
					{
						do
						{
							if(teachers[i].teacherId == findId) 
							{
								teachers[i].assignedSubjects[teachers[i].assignedSubjectsQnt] = subjectId;
								teachers[i].assignedSubjectsQnt++;
								findedTeacher = 1;
								break;
							}
						if(!findedTeacher) printf("Professor nao encontrado. Tente novamente.\n");
						}while(!findedTeacher);
					}
					break;
	
				default:
					printf("Opcao invalida. Tente novamente.\n");
			}	
		} while (registerTeacher != 0 && registerTeacher != 1);
	}
	
	strcpy(subjects[subjectQnt].name, name);
    subjects[subjectQnt].subjectId = subjectId;
    subjects[subjectQnt].subjectSemester = subjectSemester;
	subjects[subjectQnt].subjectEnrolledQnt = 0;
    
	subjectQnt ++;

    printf("Disciplina cadastrada com sucesso!\n");
	
	return;
}


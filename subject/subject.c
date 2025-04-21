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
    Teacher subjectTeacher;
	int i, findId, finded = 0;
    
    if (teacherQnt == 0)
    {
    	printf("Nao e possivel cadastrar uma disciplina sem ter professores cadastrados");
		//Podemos mudar para ser possivel e pular a parte que pede para o usuario digitar o codigo do prof.
	}
	if (subjectQnt == SIZE_SUBJECTS)
	{
		printf("Nao e possivel cadastrar mais disciplinas");
	}
	
	printf("Digite o nome da disciplina: ");
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = '\0';
	
	printf("Digite o codigo da disciplina: "); //precisa verificar se ja tem o codigo cadastrado
	scanf("%d", &subjectId);
	
	printf("Digite o semestre da disciplina: ");
	scanf("%d", &subjectSemester);

	do
	{
		printf("Digite a matricula do professor que vai ministrar a disciplina: ");
		scanf("%d", &findId);
		
		for(i = 0; i < teacherQnt; i++) 
		{
			if(teachers[i].teacherId == findId) 
			{
				subjects[subjectQnt].subjectTeacher = teachers[i];
				finded = 1;
				break;
			}
		}
		if(!finded) printf("Professor nao encontrado. Tente novamente.\n");
	}while(!finded);
	
	strcpy(subjects[subjectQnt].name, name);
    subjects[subjectQnt].subjectId = subjectId;
    subjects[subjectQnt].subjectSemester = subjectSemester;
    subjects[subjectQnt].subjectTeacher = subjectTeacher;
	subjects[subjectQnt].subjectEnrolledQnt = 0;
    
	subjectQnt ++;

    printf("Disciplina cadastrada com sucesso!\n");
	
}


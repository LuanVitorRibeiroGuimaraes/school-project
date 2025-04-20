#include <stdio.h>
#include "subject.h"

#define SIZE_SUBJECTS 50
int subjectQnt = 0;
Subject subjects[SIZE_SUBJECTS]; //mudar esses valores depois

void createSubject()
{
	char name[100];
    int subjectId; 
    int subjectSemester;
    Teacher subjectTeacher;
    int findId;
    
    if (teacherQnt == 0)
    {
    	printf("Nao e possivel cadastrar uma disciplina sem ter professores cadastrados");
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

	do{
		printf("Digite a matricula do professor que vai ministrar a disciplina: ");
		scanf("%d", &findId);
		
		int finded = 0;
		int i;
		
		for(i = 0; i < teacherQnt; i++) {
	    if(teachers[i].teacherId == findId) {
	        subjects[subjectQnt].subjectTeacher = teachers[i];
	        finded = 1;
	        break;
	    }
		
		if(finded = 0) printf("Professor nao encontrado. Tente novamente.\n");
	}while(finded = 0);
	
	strcpy(subjects[subjectQnt].name, name);
    subjects[subjectQnt].subjectId = subjectId;
    subjects[subjectQnt].subjectSemester = subjectSemester;
    subjects[subjectQnt].subjectTeacher = subjectTeacher;
    
	subjectQnt ++;

    printf("Disciplina cadastrada com sucesso!\n");
	
}


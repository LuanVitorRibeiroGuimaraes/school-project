#include <stdio.h>
#include "subject.h"


void updateSubject()
{
	int option = 0, updatePos, findId, finded = 0, i;
	
	do
	{
		printf("Digite o codigo da disciplina que deseja atualizar: ");
		scanf("%d", &findId);
		
		for(i = 0, i < subjectQnt; i++)
		{	
			if(subjects[i].subjectId == findId)
			{
				finded = 1;
				updatePos = i;
				break;
			}
		}
		
		if(finded = 0) printf("Disciplina nao encontrada tente novamente.\n");
	}while(finded = 0);
	
	printf("Atualizando a Disciplina: %s\n\n", subjects[updatePos].name);
	printf(
		"1 - Nome da Disciplina\n"
		"2 - Codigo da Disciplina\n"
		"3 - Semestre da Disciplina\n"
		"4 - Professor que vai ministrar a disciplina\n"
		"0 - Voltar\n"
		"Selecione qual campo deseja alterar: "
	);
	scanf("%d", &option);
	
	if
	if
}
#include "subject.h"
#include <stdio.h>

void subjectMenu()
{
	int option;
	
	printf(
		"MENU DISCIPLINA\n\n"
		"0 - Voltar\n"
		"1 - Cadastrar Disciplina\n"
		"2 - Matricular aluno em uma Disciplina\n"
		"3 - Excluir aluno de uma Disciplina\n"
		"4 - Listar todas as Disciplinas\n"
		"5 - Listar dados de uma Disciplina\n"
		"6 - Listar Disciplinas que extrapolam 40 vagas\n\n"
		"Selecione uma opcao: "
	);
    scanf("%d", &option);
	
	do
	{
		switch (option)
		{
			case 1:
				createSubject();
				break;

			case 2:
				enrollStudent();
				break;

			case 3:
				unenrollStudent();
				break;

			case 4:
				listAllSubjects();
				break;

			case 5:
				listSubject();
				break;

			case 6:
				listSubjectsWithMoreThan40Students();
				break;

			default:
				printf("Opcao invalida. Tente novamente.");
				break;
		}
	}while(option != 0);

}
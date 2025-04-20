#include "subject.h"
#include <stdio.h>

void subjectMenu()
{
	int option;
	
	printf(
		"MENU DISCIPLINA"
		"0 - Voltar\n"
		"1 - Cadastrar Disciplina\n");
		"2 - Matricular aluno em uma Disciplina\n"
		"3 - Excluir aluno de uma Disciplina\n"
		"4 - Listar todas as Disciplinas\n"
		"5 - Listar dados de uma Disciplina\n"
		"6 - Listar Disciplinas que extrapolam 40 vagas\n"
		"Selecione uma opcao: "
	);
    scanf("%d", &option);
	
}
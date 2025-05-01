#include "subject.h"

void subjectMainMenu()
{
	int menuOption;
	
	while(1)
	{
		printf(
			"\n---------------- MENU DISCIPLINA ----------------\n"
			"0 - Voltar\n"
			"1 - Cadastrar Disciplina\n"
			"2 - Matricular ou Desmatricular estudante em uma Disciplina\n"
			"3 - Listar Disciplinas\n"
			"-------------------------------------------------\n"
			"\n>> "
		);
		menuOption = validateInt();
	
		switch (menuOption)
		{
			case 0:
				return;
	
			case 1:
				subjectRegisterMenu();
				break;
	
			case 2:
				subjectEnrollmentMenu();
				break;
	
			case 3:
				subjectListingMenu();
				break;
			
			default:
				printf("\n--------------------------------------------------------------------");
				printf("\n[!] Opcao Invalida. Apenas Numeros Inteiros Entre 0 e 3 Sao Aceitos.");
				printf("\nPressione Enter para continuar..."); 
				getchar();
				getchar();
		}
	}

}

void subjectRegisterMenu()
{
	int menuOption;

	while(1)
	{
		printf(
			"\n---------------- CADASTRO DISCIPLINA ----------------\n"
			"0 - Voltar\n"
			"1 - Incluir Disciplina\n"
			"2 - Excluir Disciplina\n"
			"3 - Atualizar Disciplinas\n"
			"-----------------------------------------------------\n"
			"\n>> "
		);
		menuOption = validateInt();
	
		switch (menuOption)
		{
			case 0:
				return;
			
			case 1:
				createSubject();
				break;
			
			case 2:
				deleteSubject();
				break;
	
			case 3:
				updateSubject();
				break;
	
			default:
				printf("\n--------------------------------------------------------------------");
				printf("\n[!] Opcao Precisa Ser um Valor Inteiro Entre 0 e 3. Tente Novamente.");
				printf("\nPressione Enter Para Continuar..."); 
				getchar();
				getchar();
		}	
	}

}

void subjectEnrollmentMenu()
{
	int menuOption;

	while(1)
	{
		printf(
			"\n---------------- MATRICULA DISCIPLINA ----------------\n"
			"0 - Voltar\n"
			"1 - Matricular Estudante\n"
			"2 - Desmatricular Estudante\n"
			"--------------------------------------------------------\n"
			"\n>> "
		);
		menuOption = validateInt();
	
		switch (menuOption)
		{
			case 0:
				return;
			
			case 1:
				enrollStudent();
				break;
			
			case 2:
				unenrollStudent();
				break;
	
			default:
				printf("\n--------------------------------------------------------------------");
				printf("\n[!] Opcao Invalida. Apenas numeros inteiros entre 0 e 2 sao aceitos.");
				printf("\nPressione Enter para continuar..."); 
				getchar();
				getchar();
		}
	}
	
}

void subjectListingMenu()
{
	int menuOption;

	while(1)
	{
		printf(
			"\n---------------- LISTAGENS DISCIPLINA ----------------\n"
			"0 - Voltar\n"
			"1 - Listar Disciplinas (dados da disciplina sem os alunos)\n"
			"2 - Listar uma disciplina (dados da disciplina e os alunos matriculados)\n"
			"3 - Lista de alunos matriculados em menos de 3 disciplinas\n"
			"4 - Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas.\n"
			"------------------------------------------------------\n"
			"\n>> "
		);
		menuOption = validateInt();
	
		switch (menuOption)
		{
			case 0:
				return;
			
			case 1:
				listAllSubjects();
				break;
			
			case 2:
				listSubject();
				break;
	
			case 3:
				listUnderEnrolledStudents();
				break;
	
			case 4:
				listLargeSubjects();
				break;
	
			default:
				printf("\n--------------------------------------------------------------------");
				printf("\n[!] Opcao Invalida. Apenas Numeros Inteiros Entre 0 e 4 Sao Aceitos.");
				printf("\nPressione Enter para continuar..."); 
				getchar();
				getchar();
		}
	}
	
}
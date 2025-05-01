#include "subject.h"


Subject subjects[SIZE_SUBJECTS];
int subjectQnt = 0;

void createSubject()
{
	char name[100];
    int subjectId; 
    int subjectSemester;
	int i, findId, registerTeacher, findedTeacher = 0, notFindedSubjectId = 0;
    
	if (subjectQnt == SIZE_SUBJECTS)
	{
		printf("\n------------------------------------------");
		printf("\nNao Eh Possivel Cadastrar Mais Disciplinas");
		printf("\n------------------------------------------");
	}
	
	printf("\n >> Digite o Nome da Disciplina: ");
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = '\0';
	
	do
	{
		printf("\n >> Digite o codigo da disciplina: ");
		subjectId = validateInt();

		if (subjectId == -1)
		{
			printf("\n------------------------------------------------------");
			printf("\nCodigo So Pode Ser Um Numero Inteiro. Tente Novamente.");
			printf("\n------------------------------------------------------");
			continue;
		}

		for(i = 0; i < subjectQnt; i++)
		{
			if(subjects[i].subjectId == subjectId)
			{
				printf("\n--------------------------------------------------------------");
				printf("\n[!] Codigo Ja Cadastrado Em Outra Disciplina. Tente Novamente.");
				printf("\n--------------------------------------------------------------");
				notFindedSubjectId = 1;
			}
		}
	} while (notFindedSubjectId);
	
	
	do
	{
		printf("\n >> Digite o Semestre da Disciplina: ");
		subjectSemester = validateInt();
	
		if (subjectSemester == -1){
			printf("\n----------------------------------------------------------");
			printf("\n[!] Codigo So Pode Ser Um Numero Inteiro. Tente Novamente.");
			printf("\n----------------------------------------------------------");
		}	
	} while (subjectSemester == -1);
	


	if(teacherQnt > 0)
	{	
		do
		{
			printf(
				"\n >> Deseja Cadastrar Um Professor Para a Disciplina?"
				"\n0 - Nao"
				"\n1 - Sim"
			);
			registerTeacher = validateInt();
	
			switch(registerTeacher)
			{
				case 0:
					break;
	
				case 1:
					printf("\n >> Digite a Matricula Do Professor Que Vai Ministrar a Disciplina: ");
					scanf("\n%d", &findId);
					
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
						if(!findedTeacher){
							printf("\n----------------------------------------------");
							printf("\n[!] Professor Nao Encontrado. Tente Novamente.");
							printf("\n----------------------------------------------");
						} 
						}while(!findedTeacher);
					}
					break;
	
				default:
					printf("\n------------------------------------");
					printf("\n[!] Opcao Invalida. Tente Novamente.");
					printf("\n------------------------------------");
			}	
		} while (registerTeacher != 0 && registerTeacher != 1);
	}
	
	strcpy(subjects[subjectQnt].name, name);
    subjects[subjectQnt].subjectId = subjectId;
    subjects[subjectQnt].subjectSemester = subjectSemester;
	subjects[subjectQnt].subjectEnrolledQnt = 0;
    
	subjectQnt ++;

	printf("\n----------------------------------");
    printf("\nDisciplina cadastrada com sucesso!");
	printf("\n----------------------------------");
	
	return;
}


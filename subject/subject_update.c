#include "subject.h"


void updateSubject()
{
	int option = 0, updatePos, findId, findTeacherId, finded = 0, i;
	
	do
	{
		listAllSubjects();
		printf("Digite o codigo da disciplina que deseja atualizar: ");
		findId = validateInt();

		if (findId == -1)
		{
			printf("Codigo da disciplina precisa ser um numero inteiro. Tente novamente.\n");
			continue;
		}
		
		for(i = 0; i < subjectQnt; i++)
		{	
			if(subjects[i].subjectId == findId)
			{
				finded = 1;
				updatePos = i;
				break;
			}
		}
		
		if(!finded) printf("Disciplina nao encontrada tente novamente.\n");
	}while(!finded);
	
	while(1)
	{
		printf("Atualizando a Disciplina: %s\n\n", subjects[updatePos].name);
		printf(
			"Selecione qual campo deseja alterar: \n"
			"0 - Voltar\n"
			"1 - Nome da Disciplina\n"
			"2 - Codigo da Disciplina\n"
			"3 - Semestre da Disciplina\n"
			"4 - Professor que vai ministrar a disciplina\n"
			"\n>> "
			
		);
		option = validateInt();
	
		switch (option)
		{
			case 0:
				return;

			case 1:
				printf("Digite o novo nome da disciplina: ");
				fgets(subjects[updatePos].name, sizeof(subjects[updatePos]), stdin);
				printf("Nome da disciplina atualizado com sucesso!\n");
				break;
			
			case 2:
				printf("Digite o novo codigo da disciplina: ");
				scanf("%d", &subjects[updatePos].subjectId);
				printf("Codigo da disciplina atualizado com sucesso!\n");
				break;
			
			case 3:
				printf("Digite o novo semestre da disciplina: ");
				scanf("%d", &subjects[updatePos].subjectSemester);
				printf("Semestre da disciplina atualizado com sucesso!\n");
				break;

			case 4:
				int newTeacherId, j, k;
				int oldTeacherRemoved = 0, newTeacherFinded = 0;

				do
				{
					listTeachers();
					printf("Digite a matricula do novo professor que vai ministrar a disciplina: ");
					newTeacherId = validateInt();

					if(newTeacherId == -1)
					{
						printf("Matricula do professor precisa ser um numero inteiro. Tente novamente.\n");
						continue;
					}

					for (i = 0; i < teacherQnt; i++)
					{
						if (teachers[i].teacherId == newTeacherId)
						{
							teachers[i].assignedSubjects[teachers[i].assignedSubjectsQnt] = subjects[updatePos].subjectId;
							teachers[i].assignedSubjectsQnt++;
							newTeacherFinded = 1;
							break;
						}
					}

					if(newTeacherFinded)
					{
						for (i = 0; i < teacherQnt; i++)
						{
							for (j = 0; j < teachers[i].assignedSubjectsQnt; j++)
							{
								if (teachers[i].assignedSubjects[j] == subjects[updatePos].subjectId)
								{
									for (k = j; k < teachers[i].assignedSubjectsQnt - 1; k++)
									{
										teachers[i].assignedSubjects[k] = teachers[i].assignedSubjects[k+1];
									}
									teachers[i].assignedSubjectsQnt--;
									oldTeacherRemoved = 1;
								}
							}
							if(oldTeacherRemoved) break;
						}
					}

				 if(!newTeacherFinded) printf("Matricula do novo professor nao encontrada. Tente novamente.\n");
				} while (!newTeacherFinded);
							
			default:
				printf("Opcao precisa ser um valor inteiro entre 0 e 4. Tente novamente.\n");
				printf("Pressione Enter para continuar...\n"); 
				getchar();
				getchar();
		}	
	}
}
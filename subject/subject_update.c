#include "subject.h"

void updateSubject()
{
	int option = 0, updatePos, findId, findTeacherId, finded = 0, i;

	do
	{
		listAllSubjects();
		printf("\n >> Digite o Codigo da Disciplina Que Deseja Atualizar: ");
		findId = validateInt();

		if (findId == -1)
		{
			printf("\n------------------------------------------------------------------------");
			printf("\n[!] Codigo da Disciplina Precisa Ser um Numero Inteiro. Tente Novamente.");
			printf("\n------------------------------------------------------------------------");
			continue;
		}

		for (i = 0; i < subjectQnt; i++)
		{
			if (subjects[i].subjectId == findId)
			{
				finded = 1;
				updatePos = i;
				break;
			}
		}

		if (!finded)
		{
			printf("\n-----------------------------------------------");
			printf("\n[!] Disciplina Nao Encontrada. Tente Novamente.");
			printf("\n-----------------------------------------------");
		}
	} while (!finded);

	while (1)
	{
		printf("\nAtualizando a Disciplina: %s\n\n", subjects[updatePos].name);
		printf(
			"0 - Voltar\n"
			"1 - Nome da Disciplina\n"
			"2 - Codigo da Disciplina\n"
			"3 - Semestre da Disciplina\n"
			"4 - Professor Que Vai Ministrar a Disciplina\n"
			">> "

		);
		option = validateInt();

		switch (option)
		{
		case 0:
			return;

		case 1:
			printf("\n >> Digite o Novo Nome da Disciplina: ");
			fgets(subjects[updatePos].name, sizeof(subjects[updatePos]), stdin);
			printf("\n-------------------------------------------");
			printf("\n Nome da Disciplina Atualizado Com Sucesso!");
			printf("\n-------------------------------------------");
			break;

		case 2:
			printf("\n >> Digite o Novo Codigo da Disciplina: ");
			scanf("%d", &subjects[updatePos].subjectId);
			printf("\n--------------------------------------------");
			printf("\nCodigo da Disciplina Atualizado Com Sucesso!");
			printf("\n--------------------------------------------");
			break;

		case 3:
			printf("\n >> Digite o Novo Semestre da Disciplina: ");
			scanf("%d", &subjects[updatePos].subjectSemester);
			printf("\n----------------------------------------------");
			printf("\nSemestre da Disciplina Atualizado com Sucesso!");
			printf("\n----------------------------------------------");
			break;

		case 4:
		{

			int newTeacherId, j, k;
			int oldTeacherRemoved = 0, newTeacherFinded = 0;

			do
			{
				listTeachers();
				printf("\n >> Digite a Matricula do Novo Professor Que Vai Ministrar a Disciplina: ");
				newTeacherId = validateInt();

				if (newTeacherId == -1)
				{
					printf("\n--------------------------------------------------------------------------");
					printf("\n[!] Matricula do Professor Precisa Ser um Numero Inteiro. Tente Novamente.");
					printf("\n--------------------------------------------------------------------------");
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

				if (newTeacherFinded)
				{
					for (i = 0; i < teacherQnt; i++)
					{
						for (j = 0; j < teachers[i].assignedSubjectsQnt; j++)
						{
							if (teachers[i].assignedSubjects[j] == subjects[updatePos].subjectId)
							{
								for (k = j; k < teachers[i].assignedSubjectsQnt - 1; k++)
								{
									teachers[i].assignedSubjects[k] = teachers[i].assignedSubjects[k + 1];
								}
								teachers[i].assignedSubjectsQnt--;
								oldTeacherRemoved = 1;
							}
						}
						if (oldTeacherRemoved)
							break;
					}
				}

				if (!newTeacherFinded)
				{
					printf("\n----------------------------------------------------------------");
					printf("\n[!] Matricula do Novo Professor Nao Encontrada. Tente Novamente.");
					printf("\n----------------------------------------------------------------");
				}
			} while (!newTeacherFinded);

		default:
			printf("\n[!] Opcao Precisa Ser Um Valor Inteiro Entre 0 e 4. Tente Novamente.");
			printf("\n >> Pressione Enter para continuar...");
			getchar();
			getchar();
		}
		}
	}
}
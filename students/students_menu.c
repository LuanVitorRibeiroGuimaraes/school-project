#include "students.h"

void studentMenu()
{
    int menuOption;

    do
    {
        printf("\n----------------- MENU ALUNOS --------------------");
        printf("\nSelecione uma opcao abaixo:");
        printf("\n0 - Encerrar Programa");
        printf("\n1 - Cadastrar Aluno");
        printf("\n2 - Buscar Alunos");
        printf("\n3 - Atualizar Aluno");
        printf("\n4 - Excluir aluno");
        printf("\n5 - Voltar Para o Menu Principal");
        printf("\n>> ");
        scanf("%d", &menuOption);

        switch(menuOption)
        {
            case 0:
                printf("\n[!] Programa Encerrado!");
                return;

            case 1:
                createStudent();
                break;

            case 2:
                {
                    int option;
                    printf("\n----------------- SUBMENU LISTAR ALUNOS ----------------");
                    printf("\n>> Selecione uma opcao abaixo:");
                    printf("\n0 - Voltar");
                    printf("\n1 - Listar todos os alunos");
                    printf("\n2 - Listar aluno por id");
                    printf("\n3 - Listar alunos por letra");
                    printf("\n4 - Listar alunos por sexo");
                    printf("\n5 - Listar alunos por data de aniversário");
                    printf("\n>> ");
                    scanf("%d", &option);

                    switch(option)
                    {
                        case 0:
                            break;
                        case 1:
                            listStudents();
                            break;
                        case 2:
                            listStudentsById();
                            break;
                        case 3:
                            listStudentsByLetter();
                            break;
                        case 4:
                            listStudentsBySex();
                            break;
                        case 5:
                            listStudentsByBirthDate();
                            break;
                        default:
                            printf("\n-------------------");
                            printf("\n[!] Opcao invalida!");
                            printf("\n-------------------");
                            break;
                    }
                }
                break;

            case 3:
                {
                    int id;
                    printf("\n >> Digite o id do aluno para atualizar:");
                    printf("\n>> ");
                    scanf("%d", &id);
                    updateStudent(id);
                }
                break;

            case 4:
                {
                    int id;
                    printf("\n >> Digite o id do aluno que deseja deletar:");
                    printf("\n>> ");
                    scanf("%d", &id);
                    deleteStudentById(id);
                }
                break;

            case 5:
                printf("\n-------------------------------");
                printf("\n >> Voltar para menu principal.");
                printf("\n-------------------------------");
                return;

            default:
                printf("\n------------------------------------");
                printf("\n[!] Opcao invalida! Tente novamente.");
                printf("\n------------------------------------");
                break;
        }

    } while (menuOption != 0);
}

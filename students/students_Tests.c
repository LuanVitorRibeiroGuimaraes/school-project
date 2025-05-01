#include "students.h"

void testFunctionsMenu()
{
    int menuOption;

    do
    {
        printf("\n----------------------MENU DE TESTES -----------------------");
        printf("\n0 - Sair");
        printf("\n1 - Cadastrar Aluno\n");
        printf("\n2 - Testar: Listar todos os alunos");
        printf("\n3 - Testar: Listar aluno por ID");
        printf("\n4 - Testar: Listar alunos por letra inicial");
        printf("\n5 - Testar: Listar alunos por sexo");
        printf("\n6 - Testar: Listar alunos por data de nascimento");
        printf("\n7 - Testar: Deletar aluno por id");
        printf("\n8 - Testar: Atualizar aluno por id");
        printf("\n>> ");
        printf("\n------------------------------------------------------------");
        scanf("%d", &menuOption);

        switch (menuOption)
        {
            case 0:
                printf("\nSaindo...");
                break;

            case 1:
                createStudent();
                break;

            case 2:
                listStudents();
                break;

            case 3:
            {
                listStudentsById();
                break;
            }

            case 4:
                listStudentsByLetter();
                break;

            case 5:
            {
                listStudentsBySex();
                break;
            }

            case 6:
                listStudentsByBirthDate();
                break;

            case 7:
                deleteStudentById();
                break;

            case 8:
                updateStudent();
                break;
                
            default:
                printf("\n[!] Opcao invalida!");
        }
    }
    while (menuOption != 0);
}


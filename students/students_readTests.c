#include "students.h"

void testReadFunctionsMenu()
{
    int menuOption;

    do
    {
        printf("\n------------- MENU DE TESTES READ (LEITURA) -------------\n");
        printf("0 - Sair\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Testar: Listar todos os alunos\n");
        printf("3 - Testar: Listar aluno por ID\n");
        printf("4 - Testar: Listar alunos por letra inicial\n");
        printf("5 - Testar: Listar alunos por sexo\n");
        printf("6 - Testar: Listar alunos por data de nascimento\n");
        printf("7 - Testar: Deletar aluno por id\n");
        printf("8 - Testar: Atualizar aluno por id\n");
        printf("---------------------------------------------------------\n");
        printf(">> ");
        scanf("%d", &menuOption);

        switch (menuOption)
        {
            case 0:
                printf("Saindo...\n");
                break;

            case 1:
                createStudent();
                break;

            case 2:
                listStudents(); //funcionando
                break;

            case 3:
            {
                listStudentsById(); //funcionando
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
                // listStudentsByBirthDate();
                printf("Função ainda não implementada.\n");
                break;

            case 7:
                deleteStudentById();
                break;

            case 8:
                updateStudent();
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
    }
    while (menuOption != 0);
}

int main()
{
    testReadFunctionsMenu();
}

#include "students.h"

void studentMenu()
{
    int menuOption;

    do
    {
        printf("\n----------------- MENU ALUNOS ----------------\n");
        printf("Selecione uma opcao abaixo:\n");
        printf("0 - Fechar menu\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Buscar Alunos\n");
        printf("3 - Atualizar Aluno\n");
        printf("4 - Excluir aluno\n");
        printf("5 - Voltar Para o Menu Principal\n");
        printf("----------------------------------------------------\n");
        printf("\n>> ");
        scanf("%d", &menuOption);

        if (menuOption == 0)
        {
            printf("\nPrograma Encerrado!");
            return;
        }

        if (menuOption == 1)
        {
            createStudent();
            continue;
        }

        if (menuOption == 2)
        {

            int option;

            printf("\n----------------- SUBMENU LISTAR ALUNOS ----------------\n");
            printf("Selecione uma opcao abaixo:\n");
            printf("0 - Voltar\n");
            printf("1 - Listar todos os alunos\n");
            printf("2 - Listar aluno por id\n");
            printf("3 - Listar alunos por letra\n");
            printf("4 - Listar alunos por sexo\n");
            printf("5 - Listar alunos por data de aniversário\n");
            printf("\n>> ");
            scanf("%d", &option);
            
            if (option == 0)
            {
                continue;
            }

            if (option == 1)
            {
                int option;

                do
                {
                    printf("\nSelecione uma opcao abaixo:\n");
                    printf("0 - Voltar\n");
                    printf("1 - Listar todos os alunos\n");
                    printf("\n>> ");
                    scanf("%d", &option);
                }
                while (option != 0 && option != 1);

                if (option == 0)
                    continue;

                if (option == 1)
                    listStudents();
            }

            if (menuOption == 2)
            {
                int option;

                do
                {
                    printf("\nSelecione uma opcao abaixo:\n");
                    printf("0 - Voltar\n");
                    printf("1 - Listar aluno por id\n");
                    printf("\n>> ");
                    scanf("%d", &option);
                }
                while (option != 0 && option != 1);

                if (option == 0)
                    continue;

                if (option == 1)
                {
                    int id = 0;

                    printf("Digite o id o aluno que deseja atualizar: ");
                    scanf("%d", &id);

                    listStudentsById(id);
                }
            }

            if (menuOption == 3)
            {
                int option;

                do
                {
                    printf("\n---------------------------");
                    printf("\nSelecione uma opcao abaixo:");
                    printf("\n0 - Voltar");
                    printf("\n1 - Listar alunos por letra");
                    printf("\n>> ");
                    printf("\n---------------------------");
                    scanf("%d", &option);
                }
                while (option != 0 && option != 1);

                if (option == 0)
                    continue;

                if (option == 1)
                    listStudentsByLetter();
            }

            if (menuOption == 4)
            {
                int option;

                do
                {
                    printf("\nSelecione uma opcao abaixo:\n");
                    printf("0 - Voltar\n");
                    printf("1 - Listar aluno por sexo\n");
                    printf("\n>> ");
                    scanf("%d", &option);
                }
                while (option != 0 && option != 1);

                if (option == 0)
                    continue;

                if (option == 1)
                {
                    char sex;

                    do
                    {
                        printf("\nDigite o sexo ('M' ou 'F') para listar os alunos:");
                        printf("\n>> ");
                        scanf("%c", &sex);
                    }
                    while (sex != 'm' && sex != 'M' && sex != 'f' && sex != 'F');

                    listStudentsBySex(sex);
                }
            }

            if (menuOption == 5)
            {
                int option;

                do
                {
                    printf("\nSelecione uma opcao abaixo:\n");
                    printf("0 - Voltar\n");
                    printf("1 - Listar aluno por data de aniversario\n");
                    printf("\n>> ");
                    scanf("%d", &option);
                }
                while (option != 0 && option != 1);

                if (option == 0)
                    continue;

                // if (option == 1)
                //     listStudentsByBirthDate();
            }
            
        }

        if (menuOption == 3)
        {
            int option;

            do
            {
                printf("\nSelecione uma opcao abaixo:\n");
                printf("0 - Voltar\n");
                printf("1 - Atualizar Aluno\n");
                printf("\n>> ");
                scanf("%d", &option);
            }
            while (option != 0 && option != 1);

            if (option == 0)
            {
                continue;
            }

            if (option == 1)
            {
                int id;

                printf("\nDigite o id do aluno para atualizar:\n");
                printf("\n>> ");
                scanf("%d", &id);

                updateStudent(id);
            }
            
            
        }

        if (menuOption == 4)
        {
            int option;

            do
            {
                printf("\nSelecione uma opcao abaixo:\n");
                printf("0 - Voltar\n");
                printf("1 - Deletar Aluno\n");
                printf("\n>> ");
                scanf("%d", &option);
            }
            while (option != 0 && option != 1);

            if (option == 0)
                continue;

            if (option == 1)
            {
                int id;

                printf("\nDigite o id do aluno que deseja deletar:\n");
                printf("\n>> ");
                scanf("%d", &id);

                deleteStudentById(id);
            }
        }

        if (menuOption  = 5)
        {
            printf("\n---------------------------------------------------------\n");
            printf("voltar para menu principal");
            printf("\n---------------------------------------------------------\n");
        }
    }
    while (menuOption != 0);
}

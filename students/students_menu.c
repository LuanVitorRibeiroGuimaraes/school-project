#include "students.h"

void studentMenu()
{
    int option;

    printf("Selecione uma opcao abaixo:\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Buscar Alunos\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Excluir aluno");
    scanf("%d", &option);

    if (option == 1)
    {
        createStudent();
    }

    if (option == 2)
    {
        printf("Selecione uma opcao abaixo:\n");
        printf("0 - Voltar");
        printf("1 - Listar todos os alunos");
        printf("2 - Listar aluno por id\n");
        printf("3 - Listar alunos por letra\n");
        printf("4 - Listar alunos por sexo\n");
        printf("5 - Listar alunos por data de aniversário");
        scanf("%d", &option);
        
        if (option == 0)
        {
            studentMenu();
        }
            

        if (option == 1)
        {
            int option;

            do
            {
                printf("Selecione uma opcao abaixo:\n");
                printf("0 - Voltar\n");
                printf("1 - Listar todos os alunos\n");
                scanf("%d", &option);
            }
            while (option != 0 && option != 1);

            if (option == 0)
                studentMenu();

            if (option == 1)
                listStudents();
        }
            
        
        if (option == 2)
        {
            int option;

            do
            {
                printf("Selecione uma opcao abaixo:\n");
                printf("0 - Voltar\n");
                printf("1 - Listar aluno por id\n");
                scanf("%d", &option);
            }
            while (option != 0 && option != 1);

            if (option == 0)
                studentMenu();

            if (option == 1)
            {
                int id;

                printf("Digite o id o aluno que deseja atualizar: ");
                scanf("%d", id);

                listStudentsById(id);
            }
        }

        if (option == 3)
        {
            int option;

            do
            {
                printf("Selecione uma opcao abaixo:\n");
                printf("0 - Voltar\n");
                printf("1 - Listar alunos por letra\n");
                scanf("%d", &option);
            }
            while (option != 0 && option != 1);

            if (option == 0)
                studentMenu();

            if (option == 1)
                listStudentsByLetter();
        }

        if (option == 4)
        {
            int option;

            do
            {
                printf("Selecione uma opcao abaixo:\n");
                printf("0 - Voltar\n");
                printf("1 - Listar aluno por sexo\n");
                scanf("%d", &option);
            }
            while (option != 0 && option != 1);

            if (option == 0)
                studentMenu();

            if (option == 1)
            {
                char sex;

                do
                {
                    printf("Digite o sexo ('M' ou 'F') para listar os alunos:");
                    scanf("%c", &sex);
                }
                while (sex != 'm' && sex != 'M' && sex != 'f' && sex != 'F');

                listStudentsBySex(sex);
            }
        }

        if (option == 5)
        {
            int option;

            do
            {
                printf("Selecione uma opcao abaixo:\n");
                printf("0 - Voltar\n");
                printf("1 - Listar aluno por data de aniversario\n");
                scanf("%d", &option);
            }
            while (option != 0 && option != 1);

            if (option == 0)
                studentMenu();

            if (option == 1)
                listStudentsByBirthDate();
        }
        
    }

    if (option == 3)
    {
        int option;

        do
        {
            printf("Selecione uma opcao abaixo:\n");
            printf("0 - Voltar\n");
            printf("1 - Atualizar Aluno\n");
            scanf("%d", &option);
        }
        while (option != 0 && option != 1);

        if (option == 0)
        {
            studentMenu();
        }

        if (option == 1)
        {
            int id;

            printf("Digite o id do aluno para atualizar: ");
            scanf("%d", &id);

            updateStudent(id);
        }
        
        
    }

    if (option == 4)
    {
        int option;

        do
        {
            printf("Selecione uma opcao abaixo:\n");
            printf("0 - Voltar\n");
            printf("1 - Deletar Aluno\n");
            scanf("%d", &option);
        }
        while (option != 0 && option != 1);

        if (option == 0)
            studentMenu();

        if (option == 1)
        {
            int id;

            printf("Digite o id do aluno que deseja deletar: ");
            scanf("%d", &id);

            deleteStudentById(id);
        }
    }
}   

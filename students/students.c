#include "students/students.h"
#include "../validators/validators.h"

//precisa testar

int studentQnt = 0;
Students students[SIZE_STUDENTS];

void createStudent() //adicionar verificar se campo está vazio ou não
{

    int studentId; 
    char name[100];
    char sex;
    char birthDate[10];
    char cpf[14];

    if (studentQnt == SIZE_STUDENTS)
    {
        printf("Nao e possuivel cadastrar mais alunos!");
    }

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &studentId);

    getchar();

    printf("Digite o nome do aluno: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; //trocar o \n do final pelo \0


    printf("Digite o sexo do aluno: ");
    scanf("%c", &sex);

    getchar();

    printf("Digite a data de aiversario: ");
    fgets(birthDate, sizeof[10]; stdin);
    birthDate[strcspn(birthDate, "\n")] = ' \0';

    // getchar();

    // printf("Digite o CPF do aluno: ");
    // fgets(cpf, sizeof(cpf), stdin);
    // name[strcspn(name, "\n")] = '\0'; //trocar o \n do final pelo \0
    // //validateCpf(cpf);

    //em C, strings são arrays de caracteres, e você não pode atribuir arrays diretamente assim
    //é preciso copiar o conteúdo de uma string para outra


    students[studentQnt].studentId = studentId;
    strcpy(students[studentQnt].name, name);
    students[studentQnt].sex = sex;
    strcpy(students[studentQnt].birthDate, birthDate);
    // strcpy(students[studentQnt].cpf, cpf);

    studentQnt+= 1;

    printf("Aluno cadastrado com sucesso!\n");
}

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
            while (option != 0 || option != 1);

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
            while (option != 0 || option != 1);

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
            while (option != 0 || option != 1);

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
            while (option != 0 || option != 1);

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
                while (sex != 'm' || sex != 'M' || sex != 'f' || sex != 'F');

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
            while (option != 0 || option != 1);

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
        while (option != 0 || option != 1);

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
        while (option != 0 || option != 1);

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

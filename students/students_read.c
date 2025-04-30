#include "students.h"

//testar todos os métodos

void listStudents() //funcionando
{
    if (studentQnt == 0)
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados!");
        printf("\n---------------------------------------------------\n");
        return;
    }

        for (int i = 0; i < studentQnt; i++)
        {
            printf("\n-------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d \nSexo: %c",students[i].name, students[i].studentId, students[i].cpf, students[i].birthDate, students[i].sex);
            printf("\n-------------------------------------");
        }
}

void listStudentsById() //funcionando
{
    if (studentQnt == 0) //ok
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados!");
        printf("\n---------------------------------------------------\n");
        return;
    }

    int id;
    int found = 0;

    printf("Digite a matricula do aluno que deseja consultar: ");
    printf("\n>> ");
    scanf("%d", &id);
    getchar();

    int toFind = id;

    for (int i = 0; i < studentQnt; i++)
    {   
        if (toFind == students[i].studentId)
        {
            printf("\n-------------------------------------");
                printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d \nSexo: %c",
                       students[i].name, students[i].studentId, students[i].cpf,
                       students[i].birthDate, students[i].sex);
                printf("\n-------------------------------------");
                found = 1;
                break;
        }
    }

    if (!found) 
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados com essa letra!\n");
        printf("\n----------------------------------------------------\n");
    }
            
}

void listStudentsByLetter() //funcionando
{
    if (studentQnt == 0) {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados!");
        printf("\n---------------------------------------------------\n");
        return;
    }
    
    int qtn;
    printf("Quantas letras deseja filtrar? ");
    printf("\n>> ");
    scanf("%d", &qtn);
    getchar();
    
    char letter[qtn];
    
    for (int i = 0; i < qtn; i++) {
        printf("Digite a %do letra: ", i + 1);
        letter[i] = getchar();
        getchar(); //pegar o \n
        letter[i] = toupper(letter[i]);
    }
    
    int found = 0;
    char firstLetter;
    
    for (int i = 0; i < studentQnt; i++) { //percorre todos os alunos

        firstLetter = toupper(students[i].name[0]); //pega a primeira letra de cada aluno
    

        /* no segundo for, eu percorro as letras que foram guardadas dentro do letter, 
        percorrendo até a quantidade de letras e comparando a primeira letra de cada 
        aluno encontrado antes com as letras que estão dentro do letter. Assim que encontrar, printar*/

        for (int j = 0; j < qtn; j++) {
            if (firstLetter == letter[j]) {
                printf("\n-------------------------------------");
                printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d \nSexo: %c",
                       students[i].name, students[i].studentId, students[i].cpf,
                       students[i].birthDate, students[i].sex);
                printf("\n-------------------------------------");
                found = 1;
                break;
            }
        }
    }
    
    if (!found) {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados com essas letras!\n");
        printf("----------------------------------------------------\n");
    }
    
}

void listStudentsBySex() //funcionando
{
    if (studentQnt == 0) //ok
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados!");
        printf("\n---------------------------------------------------\n");
        return;
    }

    char sex;
    int found = 0;

    while (true)
    {
        printf("Digite o sexo ('M' ou 'F') para filtrar os alunos: ");
        printf("\n>> ");
        sex = toupper(getchar());

        if (validateSex(sex) == 0)
        {
            break;
        }
    }

    char toFind = sex;
        
    for (int i = 0; i < studentQnt; i++)
    {
        if (toFind == students[i].sex)
        {
            printf("\n-------------------------------------");
                printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d \nSexo: %c",
                       students[i].name, students[i].studentId, students[i].cpf,
                       students[i].birthDate, students[i].sex);
            printf("\n-------------------------------------");
            found = 1;
        }
    }

    if (!found)
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos com esse sexo!\n");
        printf("\n---------------------------------------------------\n");
    }
}

void listStudentsBybirthDate()
{
    if (studentQnt == 0)
    {
        printf("\n----------------------------------------------------\n");
        printf("Nao ha alunos cadastrados!\n");
        printf("\n---------------------------------------------------\n");
        return;
    }
}
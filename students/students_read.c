#include "students.h"

void listStudents()
{
    if (studentQnt == 0)
    {
        printf("\n--------------------------");
        printf("\nNao ha alunos cadastrados!");
        printf("\n--------------------------");
        return;
    }

        for (int i = 0; i < studentQnt; i++)
        {
            printf("\n----------------------------------------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d \nSexo: %c",students[i].name, students[i].studentId, students[i].cpf, students[i].birthDate, students[i].sex);
            printf("\n----------------------------------------------------------------------");
        }
}

void listStudentsById()
{
    if (studentQnt == 0)
    {
        printf("\n--------------------------");
        printf("\nNao ha alunos cadastrados!");
        printf("\n--------------------------");
        return;
    }

    int id;
    int found = 0;

    printf("\n-------------------------------------------------");
    printf("\nDigite a matricula do aluno que deseja consultar:");
    printf("\n>> ");
    printf("\n-------------------------------------------------");
    scanf("%d", &id);
    getchar();

    int toFind = id;

    for (int i = 0; i < studentQnt; i++)
    {   
        if (toFind == students[i].studentId)
        {
            printf("\n----------------------------------------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d \nSexo: %c",students[i].name, students[i].studentId, students[i].cpf, students[i].birthDate, students[i].sex);
            printf("\n----------------------------------------------------------------------");
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("\n-----------------------------------------");
        printf("\nNao ha alunos cadastrados com essa letra!");
        printf("\n-----------------------------------------");
    }
            
}

void listStudentsByLetter()
{
    if (studentQnt == 0)
    {
        printf("\n------------------------------");
        printf("\n[!] Nao Ha Alunos Cadastrados!");
        printf("\n------------------------------");
        return;
    }
    
    int qtn;
    printf("\n------------------------------");
    printf("\nQuantas Letras Deseja Filtrar?");
    printf("\n>> ");
    printf("\n------------------------------");
    scanf("%d", &qtn);
    getchar();
    
    char letter[qtn];
    
    for (int i = 0; i < qtn; i++) {
        printf("\n-----------------------");
        printf("\n >> Digite a %do Letra:", i + 1);
        printf("\n-----------------------");
        letter[i] = getchar();
        getchar();
        letter[i] = toupper(letter[i]);
    }
    
    int found = 0;
    char firstLetter;
    
    for (int i = 0; i < studentQnt; i++) {

        firstLetter = toupper(students[i].name[0]);

        for (int j = 0; j < qtn; j++) {
            if (firstLetter == letter[j]) {
                printf("\n----------------------------------------------------------------------");
                printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d \nSexo: %c",students[i].name, students[i].studentId, students[i].cpf,students[i].birthDate, students[i].sex);
                printf("\n----------------------------------------------------------------------");
                found = 1;
                break;
            }
        }
    }
    
    if (!found)
    {
        printf("\n-------------------------");
        printf("\n[!] Aluno Nao Encontrado.");
        printf("\n-------------------------");
    }
    
}

void listStudentsBySex()
{
    if (studentQnt == 0)
    {
        printf("\n------------------------------");
        printf("\n[!] Nao Ha Alunos Cadastrados!");
        printf("\n------------------------------");
        return;
    }

    char sex;
    int found = 0;

    while (true)
    {
        printf("\n--------------------------------------------------");
        printf("\nDigite o Sexo ('M' ou 'F') Para Filtrar os Alunos:");
        printf("\n>> ");
        printf("\n--------------------------------------------------");
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
            printf("\n----------------------------------------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d \nSexo: %c",students[i].name, students[i].studentId, students[i].cpf,students[i].birthDate, students[i].sex);
            printf("\n----------------------------------------------------------------------");
            found = 1;
        }
    }

    if (!found)
    {
        printf("\n-------------------------");
        printf("\n[!] Aluno Nao Encontrado.");
        printf("\n-------------------------");
    }
}

void listStudentsByBirthDate()
{
    if (studentQnt == 0)
    {
        printf("\n------------------------------");
        printf("\n[!] Nao Ha Alunos Cadastrados!");
        printf("\n------------------------------");
        return;
    }

    int day, month, year;
    int valid;

    do
    {
        printf("\n----------------------------------");
        printf("\nDigite a Data de Nascimento: ");
        printf("\n >> Dia (DD): ");
        scanf("%d", &day);

        printf("\n >> Mes (MM): ");
        scanf("%d", &month);

        printf("\n >> Ano (AAAA): ");
        scanf("%d", &year);
        valid = validateData(day, month, year);
    } while (!valid);

    bool found = false;

    printf("\n---------------------------------------------");
    printf("\nAlunos Com data De Nascimento %02d/%02d/%04d:", day, month, year);
    printf("\n---------------------------------------------");

    for (int i = 0; i < studentQnt; i++)
    {
        if (!students[i].active) continue;

        if (students[i].birthDay == day &&
            students[i].birthMonth == month &&
            students[i].birthYear == year)
        {
            printf("\nNome: %s", students[i].name);
            printf("\nMatricula: %d", students[i].studentId);
            printf("\nSexo: %s", students[i].sex);
            printf("\n-----------------------------------------------");
            found = true;
        }
    }

    if (!found)
    {
        printf("\n------------------------------------------");
        printf("\n[!] Nenhum Aluno Encontrado Com Essa Data.");
        printf("\n------------------------------------------");
    }

    printf("\n");
}

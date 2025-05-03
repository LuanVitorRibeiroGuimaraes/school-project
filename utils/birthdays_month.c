#include "utils.h"

void birthdaysMonth(){
   
    int lMonth;
    int lCont = 0;
    char buffer[100];

    printf("\n >> Digite o Mes Atual: ");
    printf("\n >> ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &lMonth);

    if (lMonth <= 0 || lMonth >= 13)
    {
        printf("\n-------------------------");
        printf("\n[!] Digite Um Mes Valido.");
        printf("\n-------------------------");
        return; 
    }
    

    for(int i = 0; i < teacherQnt; i ++){
        if(teachers[i].birthMonth == lMonth){

            printf("\n-------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d/%d/%d \nSexo: %c \nCargo: %s",
                   teachers[i].name, teachers[i].teacherId, teachers[i].cpf, teachers[i].birthDay, teachers[i].birthMonth, teachers[i].birthYear, teachers[i].sex, teachers[0].cargo);
            printf("\n-------------------------------------");
            lCont++;
        }
    }


    for(int i = 0; i < studentQnt; i ++){
        if(students[i].birthMonth == lMonth){

            printf("\n-------------------------------------");
            printf("\nNome: %s \nMatricula: %d \nCPF: %s \nData de Nascimento: %d/%d/%d \nSexo: %c ",
                   students[i].name, students[i].studentId, students[i].cpf, students[i].birthDay, students[i].birthMonth, students[i].birthYear, students[i].sex);
            printf("\n-------------------------------------");
            lCont++;
        }
    }


    if (lCont == 0)
    {
        printf("\n---------------------------------------------");
        printf("\n[!] Nenhuma Pessoa Com Aniversario Nesse Mes.");
        printf("\n---------------------------------------------");
        return;
    }
}

#ifndef VALIDATORS_H
#define VALIDATORS_H

#define SIZE_CPF 15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



void validateCpf();
void formatCpf(char cpf[]);
void validadebirthDate(char birthDate[10]); //não implementado
void validateSemester(); //não implementado

//? Validadores de Professores
int validateTeacherId(int pId);
int validateTeachersSex(char pSex); 
int validateTeachersName(char name[]);

#endif 

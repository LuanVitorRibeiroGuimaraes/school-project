#ifndef VALIDATORS_H
#define VALIDATORS_H

#define SIZE_CPF 15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../students/students.h"
#include "../teachers/teachers.h" 



void validateCpf();
void formatCpf(char cpf[]); //precisa implementar
void formatCpf();
void validadebirthDate(char birthDate[10]); //precisa implementar
int validateName(char name[]); //funcionando
int validateTeacherId(int id); //funcionando
int validateStudentId(int id); //funcionando
int validateSex(char Sex); //funcionando

#endif

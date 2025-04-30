#ifndef VALIDATORS_H
#define VALIDATORS_H

#define SIZE_CPF 15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../students/students.h"
#include "../teachers/teachers.h" 



int validateCpf(char *cpf);
void formatCpf(char cpf[]); 
void formatCpf();
void validadebirthDate(char birthDate[10]); 
int validateName(char name[]); 
int validateTeacherId(int id); 
int validateStudentId(int id); 
int validateSex(char Sex);
int validateInt();
int leapYear(int year);
int validateData(int day, int month, int year);

#endif

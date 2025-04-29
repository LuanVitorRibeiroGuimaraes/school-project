#ifndef SUBJECT_H
#define SUJECT_H

// #include "teachers/teachers.h"

typedef struct
{
    char name[50];
    int subjectCode;
    int semester;
    // Teacher teacher;
} Subject;

void createSubject();
void updateSubject();
void deleteSubject();
void listSubjects();



#endif

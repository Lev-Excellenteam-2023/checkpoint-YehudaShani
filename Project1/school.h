#pragma once
#include "studentNode.h"

/*
* class that represents a School
*/
typedef struct School
{
	StudentNode_t* students[12][10];
}School_t ;

School_t * createSchool();

void addStudent(School_t* school, StudentNode_t* studentNode, char* year, char* section);

void printSchool(School_t* school);

void eraseSchool(School_t* school);

void insertNewStudent(School_t* school);

void deleteStudent(School_t* school, char* firstName, char* lastName, char* year, char* section);

void updateStudent(School_t* school, char* firstName, char* lastName, char* year, char* section, int index, char* grade);

void findAndPrintStudent(School_t* school, char* firstName, char* lastName);

void printTopTenPerClass(School_t* school, int index);
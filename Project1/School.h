#pragma once
#include "studentNode.h"

typedef struct School
{
	StudentNode_t* students[12][10];
}School_t ;

School_t * createSchool();

void addStudent(School_t* school, StudentNode_t* studentNode, char* year, char* section);

void printSchool(School_t* school);
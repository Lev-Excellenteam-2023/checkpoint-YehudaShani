#pragma once
#include "studentNode.h"

typedef struct School
{
	StudentNode_t* students[12][10];
}School_t ;

void addStudent(School_t* school, StudentNode_t* studentNode, char* year, char* section);
#pragma once
#include "student.h"

/*
* Class representing a Student Node
*/
typedef struct StudentNode {
	Student_t* student;
	struct StudentNode* next;
} StudentNode_t;

StudentNode_t* createStudentNode(Student_t* student);

void eraseWholeList(StudentNode_t* studentNode);
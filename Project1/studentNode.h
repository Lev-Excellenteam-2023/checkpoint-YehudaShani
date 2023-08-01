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

void eraseStudentNode(StudentNode_t* studentNode, char* firstName, char* lastName);

StudentNode_t* findStudentNode(StudentNode_t* studentNode, char* firstName, char* lastName);

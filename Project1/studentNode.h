#pragma once
#include "student.h"

typedef struct StudentNode {
	Student_t* student;
	struct studentNode* next;
} StudentNode_t;

StudentNode_t* createStudentNode(Student_t* student);

void eraseWholeList(StudentNode_t* studentNode);
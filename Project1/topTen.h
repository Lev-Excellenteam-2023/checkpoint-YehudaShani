#pragma once
#include "studentNode.h"

typedef struct topTen{
	StudentNode_t* topStudents[10];
	int gradeIndex;
	int lowestGrade;
	int lowestGradeStudentIndex;
	int amountOfStudents;
} topTen_t;

topTen_t* createTopTen();

void addStudentToTopTen(topTen_t* topTen, StudentNode_t* studentNode);
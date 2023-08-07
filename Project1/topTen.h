#pragma once
#ifndef TOP_TEN_H
#define TOP_TEN_H

#include "student.h"

struct TopTen {
	Student_t* topStudents[10];
	int gradeIndex;
	int lowestGrade;
	int lowestGradeStudentIndex;
	int amountOfStudents;
} typedef TopTen_t;

TopTen_t* createTopTen(int gradeIndex);

void addStudentToTopTen(TopTen_t* topTen, Student_t* student);

void restartTopTen(TopTen_t* topTen);

void updateLowest(TopTen_t* topTen);

#endif

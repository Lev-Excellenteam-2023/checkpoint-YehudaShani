#pragma once

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

void deleteTopTen(TopTen_t* topTen);
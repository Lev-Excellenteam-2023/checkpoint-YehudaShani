#include "topTen.h"
#include <stdio.h>
#include <stdlib.h>


TopTen_t* createTopTen(int gradeIndex){
	TopTen_t* topTen = (TopTen_t*)malloc(sizeof(TopTen_t));
	topTen->gradeIndex = gradeIndex;
	topTen->amountOfStudents = 0;
	topTen->lowestGrade = 0;
	for (int i = 0; i < 10; i++) {
		topTen->topStudents[i] = NULL;
	}
	return topTen;
}

void addStudentToTopTen(TopTen_t* topTen, Student_t* student) {
	if (topTen->amountOfStudents < 10) {
		topTen->topStudents[topTen->amountOfStudents] = student;
		topTen->amountOfStudents++;
		return;
	}
	if (atoi(student->grades[topTen->gradeIndex]) > topTen->lowestGrade) {
		topTen->topStudents[topTen->lowestGradeStudentIndex] = student;
		topTen->lowestGrade = atoi(student->grades[topTen->gradeIndex]);
		for (int i = 0; i < 10; i++) {
			if (atoi(topTen->topStudents[i]->grades[topTen->gradeIndex]) < topTen->lowestGrade) {
				topTen->lowestGrade = atoi(topTen->topStudents[i]->grades[topTen->gradeIndex]);
				topTen->lowestGradeStudentIndex = i;
			}
		}
	}
}

void deleteTopTen(TopTen_t* topTen)
{
	for (int i = 0; i < 10; i++) {
		if (topTen->topStudents[i] != NULL) {
			eraseStudent(topTen->topStudents[i]);
		}
	}
}



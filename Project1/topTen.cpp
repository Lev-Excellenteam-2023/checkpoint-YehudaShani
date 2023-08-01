#include "topTen.h"


topTen_t* createTopTen(){
	topTen_t* topTen = (topTen_t*)malloc(sizeof(topTen_t));
	topTen->amountOfStudents = 0;
	topTen->gradeIndex = 0;
	topTen->lowestGrade = 0;
	for (int i = 0; i < 10; i++) {
		topTen->topStudents[i] = NULL;
	}
	return topTen;
};

void addStudentToTopTen(topTen_t* topTen, StudentNode_t* studentNode) {
	if (topTen->amountOfStudents < 10) {
		topTen->topStudents[topTen->amountOfStudents] = studentNode;
		topTen->amountOfStudents++;
		return;
	}
	if (atoi(studentNode->student->grades[topTen->gradeIndex]) > topTen->lowestGrade) {
		topTen->topStudents[topTen->lowestGradeStudentIndex] = studentNode;
		topTen->lowestGrade = atoi(studentNode->student->grades[topTen->gradeIndex]);
		for (int i = 0; i < 10; i++) {
			if (atoi(topTen->topStudents[i]->student->grades[topTen->gradeIndex]) < topTen->lowestGrade) {
				topTen->lowestGrade = atoi(topTen->topStudents[i]->student->grades[topTen->gradeIndex]);
				topTen->lowestGradeStudentIndex = i;
			}
		}
	}
};
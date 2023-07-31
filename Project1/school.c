#include "school.h"

School_t* createSchool() {
	School_t* school = (School_t*)malloc(sizeof(School_t));
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 10; j++) {
			school->students[i][j] = NULL;
		}
	}
	return school;
}


void addStudent(School_t* school, StudentNode_t* studentNode, char* year, char* section) {
	studentNode->next = school->students[atoi(year) - 1][atoi(section) - 1];
	school -> students[atoi(year) - 1][atoi(section) - 1] = studentNode;
}

void printSchool(School_t* school) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 10; j++) {
			StudentNode_t* current = school->students[i][j];
			while (current != NULL) {
				printStudent(current->student);
				current = current->next;
			}
		}
	}
}
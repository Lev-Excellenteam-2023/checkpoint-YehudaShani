#include "school.h"

void addStudent(School_t* school, StudentNode_t* studentNode, char* year, char* section) {
	studentNode->next = school->students[atoi(year) - 1][atoi(section) - 1];
	school -> students[atoi(year) - 1][atoi(section) - 1] = studentNode;
}
#define _CRT_SECURE_NO_WARNINGS

#include "school.h"

/*
* Constructor for school class
*/
School_t* createSchool() {
	School_t* school = (School_t*)malloc(sizeof(School_t));
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 10; j++) {
			school->students[i][j] = NULL;
		}
	}
	FILE* file = fopen("students_with_class.txt", "r");

	if (file == NULL) {
		printf("Error opening the file.\n");
		exit(1);
	}

	char buffer[100]; // Assuming each line has at most 99 characters, adjust the size as needed
	while (fgets(buffer, sizeof(buffer), file) != NULL) {

		char params[15][20];
		int numParams = 0;
		int offset = 0;

		while (sscanf(buffer + offset, "%49s", params[numParams]) == 1) {
			numParams++;

			// Move the offset to the next word (plus 1 to skip the delimiter)
			offset += snprintf(NULL, 0, "%s", params[numParams - 1]) + 1;

			if (numParams >= 15) {
				break; // Stop if we have 15 parameters
			}
		}


		Student_t* student = createStudent(params[0], params[1], params[2],
			params[3], params[4], params[5], params[6], params[7], params[8], params[9], params[10], params[11],
			params[12], params[13], params[14]);

		StudentNode_t* studentNode = createStudentNode(student);
		addStudentNode(school, studentNode, params[3], params[4]);
	}

	return school;
}

/*
* Function adds student to year-class of choice
* Adds student in the beggining and defines its "next" to be the beggining of original list
*/
void addStudentNode(School_t* school, StudentNode_t* studentNode, char* year, char* section) {
	studentNode->next = school->students[atoi(year) - 1][atoi(section) - 1];
	school -> students[atoi(year) - 1][atoi(section) - 1] = studentNode;
}

/*
* Function prints all students in school in ascending year-class order
*/
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

/*
* Function deletes all linked lists (year-class) in school and then releases itself
*/
void eraseSchool(School_t* school) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 10; j++) {
			eraseWholeList(school->students[i][j]);
		}
	}
	free(school);
}

/*
* Function receives student's details from user, creates a student and adds it to school
*/
void insertNewStudent(School_t* school) {
	printf("Enter student's details:\n");
	char* params[15];
	for (int i = 0; i < 15; i++) {
		params[i] = (char*)malloc(sizeof(char) * 20);
	}
	printf("Enter student's first name:\n");
	scanf("%s", params[0]);
	printf("Enter student's last name:\n");
	scanf("%s", params[1]);
	printf("Enter student's phone number:\n");
	scanf("%s", params[2]);
	printf("Enter student's year:\n");
	scanf("%s", params[3]);
	printf("Enter student's section:\n");
	scanf("%s", params[4]);
	printf("Enter student's grades:\n");
	for (int i = 5; i < 15; i++) {
		scanf("%s", params[i]);
	}
	Student_t* student = createStudent(params[0], params[1], params[2],
				params[3], params[4], params[5], params[6], params[7], params[8], params[9], params[10], params[11],
				params[12], params[13], params[14]);
	StudentNode_t* studentNode = createStudentNode(student);
	addStudentNode(school, studentNode, params[3], params[4]);

	for (int i = 0; i < 15; i++) {
		free(params[i]);
	}
}



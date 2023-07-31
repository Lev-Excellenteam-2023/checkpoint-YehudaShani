#include "student.h"

Student_t* createStudents(char* firstName, char* lastName, char* phoneNumber, char* year, char* section, char* grade0, char* grade1,
	char* grade2, char* grade3, char* grade4, char* grade5, char* grade6, char* grade7, char* grade8,
	char* grade9){
	Student_t* student = malloc(sizeof(struct Student));
	strcpy(student->firstName, firstName);
	strcpy(student->lastName, lastName);
	strcpy(student->phoneNumber, phoneNumber);
	strcpy(student->year, year);
	strcpy(student->section, section);
	student->grades[0] = grade0;
	student->grades[1] = grade1;
	student->grades[2] = grade2;
	student->grades[3] = grade3;
	student->grades[4] = grade4;
	student->grades[5] = grade5;
	student->grades[6] = grade6;
	student->grades[7] = grade7;
	student->grades[8] = grade8;
	student->grades[9] = grade9;

	return student;
}

void printStudent(Student_t* student)
{
	printf("First Name: %s\n", student->firstName);
	printf("Last Name: %s\n", student->lastName);
	printf("Phone Number: %s\n", student->phoneNumber);
	printf("Year: %s\n", student->year);
	printf("Section: %s\n", student->section);
	printf("Grades: ");
	for (int i = 0; i < 10; i++) {
		printf("%s ", student->grades[i]);
	}
	printf("\n");
}

void eraseStudent(Student_t* student) {

	free(student);
}

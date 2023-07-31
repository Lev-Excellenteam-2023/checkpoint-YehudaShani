#include "student.h"

Student_t* createStudents(char* firstName, char* lastName, int phoneNumber, int year, int section, int* grades) {
	Student_t* student = malloc(sizeof(struct Student));
	strcpy(student->firstName, firstName);
	strcpy(student->lastName, lastName);
	student->phoneNumber = phoneNumber;
	student->year = year;
	student->section = section;
	for (int i = 0; i < 10; i++) {
		student->grades[i] = grades[i];
	}
	return student;
}

void printStudent(Student_t* student)
{
	printf("First Name: %s\n", student->firstName);
	printf("Last Name: %s\n", student->lastName);
	printf("Phone Number: %d\n", student->phoneNumber);
	printf("Year: %d\n", student->year);
	printf("Section: %d\n", student->section);
	printf("Grades: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", student->grades[i]);
	}
	printf("\n");
}


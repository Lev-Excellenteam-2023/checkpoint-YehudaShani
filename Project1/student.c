#include "student.h"
#include <stdio.h>
#include <stdlib.h>


/*
* Constructor for Student class
*/
Student_t* createStudent(char* firstName, char* lastName, char* phoneNumber, char* year, char* section, char* grade0, char* grade1,
	char* grade2, char* grade3, char* grade4, char* grade5, char* grade6, char* grade7, char* grade8,
	char* grade9){
	Student_t* student = malloc(sizeof(struct Student));
	strcpy(student->firstName, firstName);
	strcpy(student->lastName, lastName);
	strcpy(student->phoneNumber, phoneNumber);
	strcpy(student->year, year);
	strcpy(student->section, section);
	strcpy(student->grades[0], grade0);
	strcpy(student->grades[1], grade1);
	strcpy(student->grades[2], grade2);
	strcpy(student->grades[3], grade3);
	strcpy(student->grades[4], grade4);
	strcpy(student->grades[5], grade5);
	strcpy(student->grades[6], grade6);
	strcpy(student->grades[7], grade7);
	strcpy(student->grades[8], grade8);
	strcpy(student->grades[9], grade9);

	return student;
}

/*
* Function for printing all student info
*/
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

/*
* Function erases students allocated memory
*/
void eraseStudent(Student_t* student) {
	free(student);
}

/*
* Function calculates average of student grades
*/
double calculateAverage(Student_t* student) {
	double sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += atoi(student->grades[i]);
	}
	return sum / 10;
}

/*
* function returns a string representation of a student
*/
char* studentToString(Student_t* student) {
	char str[1000];
	sprintf(str, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
				student->firstName, student->lastName, student->phoneNumber, student->year, student->section, student->grades[0], student->grades[1],
				student->grades[2], student->grades[3], student->grades[4], student->grades[5], student->grades[6], student->grades[7],
				student->grades[8], student->grades[9]);
	return str;
}



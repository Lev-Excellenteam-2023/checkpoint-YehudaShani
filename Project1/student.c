#include "student.h"

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

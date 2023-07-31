#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	char firstName[20];
	char lastName[20];
	char phoneNumber[11];
	char year[3];
	char section[3];
	char* grades[10];
} Student_t;

Student_t* createStudents(char* firstName, char* lastName, char* phoneNumber, char* year, char* section, char* grade0, char* grade1,
							char* grade2, char* grade3, char* grade4, char* grade5, char* grade6, char* grade7, char* grade8,
							char* grade9);

void printStudent(Student_t* student);
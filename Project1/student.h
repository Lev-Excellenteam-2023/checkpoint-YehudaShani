#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	char firstName[20];
	char lastName[20];
	char phoneNumber;
	char year;
	char section;
	char grades[10];
} Student_t;

Student_t* createStudents(char* firstName, char* lastName, int phoneNumber, int year, int section, int* grades);

void printStudent(Student_t* student);
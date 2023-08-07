#pragma once
#ifndef STUDENT_H
#define STUDENT_H

/*
* Class for representing a student
*/
typedef struct Student {
	char firstName[20];
	char lastName[20];
	char phoneNumber[11];
	char year[3]; 
	char section[3];
	char grades[10][4];
} Student_t;


void printStudent(Student_t* student);

void eraseStudent(Student_t* student);

Student_t* createStudent(char* firstName, char* lastName, char* phoneNumber, char* year, char* section, char* grade0, char* grade1,
							char* grade2, char* grade3, char* grade4, char* grade5, char* grade6, char* grade7, char* grade8,
							char* grade9);

double calculateAverage(Student_t* student);

char* studentToString(Student_t* student);

#endif 
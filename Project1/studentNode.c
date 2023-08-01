#include "studentNode.h"
#include <stdio.h>
#include <stdlib.h>

/*
* Constructor for StudentNode
*/
StudentNode_t* createStudentNode(Student_t* student) {
	StudentNode_t* studentNode = (StudentNode_t*)malloc(sizeof(StudentNode_t));
	studentNode->student = student;
	studentNode->next = NULL;
	return studentNode;
}

/*
* Destructor for linked list of studentNodes, called recursively
*/
void eraseWholeList(StudentNode_t* studentNode) {
	if (studentNode == NULL)
		return;
	if (studentNode->next != NULL) {
		eraseWholeList(studentNode->next);
	}
	eraseStudent(studentNode->student);
	free(studentNode);
}

/*
* Function deletes student node from linked list of studentNodes
*/
void eraseStudentNode(StudentNode_t* studentNode, char* firstName, char* lastName) {
	StudentNode_t* current = studentNode;
	StudentNode_t* prev = NULL;
	while (current != NULL) {
		if (strcmp(current->student->firstName, firstName) == 0 && strcmp(current->student->lastName, lastName) == 0) {
			if (prev == NULL) {
				studentNode = current->next;
			}
			else {
				prev->next = current->next;
			}
			eraseStudent(current->student);
			free(current);
			return;
		}
		prev = current;
		current = current->next;
	}
}

/*
* Function finds student node in linked list of studentNodes
*/
StudentNode_t* findStudentNode(StudentNode_t* studentNode, char* firstName, char* lastName) {
	StudentNode_t* current = studentNode;
	while (current != NULL) {
		if (strcmp(current->student->firstName, firstName) == 0 && strcmp(current->student->lastName, lastName) == 0) {
			return current;
		}
		current = current->next;
	}
	printf("Student not found\n");
	return NULL;
}


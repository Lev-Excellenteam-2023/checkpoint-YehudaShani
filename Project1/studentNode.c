#include "studentNode.h"

StudentNode_t* createStudentNode(Student_t* student) {
	StudentNode_t* studentNode = (StudentNode_t*)malloc(sizeof(StudentNode_t));
	studentNode->student = student;
	studentNode->next = NULL;
	return studentNode;
}

void eraseWholeList(StudentNode_t* studentNode) {
	if (studentNode == NULL) {
		return;
	}
	eraseWholeList(studentNode->next);
	eraseStudent(studentNode->student);
	free(studentNode);
}

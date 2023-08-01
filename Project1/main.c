#define _CRT_SECURE_NO_WARNINGS
#include "school.h"
#include <stdio.h>


/*
* Program simulates school list
* A node is created for each student and every year-class has its own linked list of Student Nodes
* All students are printed and then deleted
*/
int main(){

    School_t* school = createSchool();

    addStudent(school);

    printSchool(school);
    eraseSchool(school);

    return 0;
}
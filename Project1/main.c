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
    
    insertNewStudent(school);
    deleteStudent(school, "Riley", "Pringle", "3", "4");
    updateStudent(school, "yehuda", "shani", "1", "1", 0, "100");
    findAndPrintStudent(school, "yehuda", "shani");
    printSchool(school);
    eraseSchool(school);
    return 0;
}
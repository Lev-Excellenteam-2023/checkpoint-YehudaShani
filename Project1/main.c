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
    FILE* file = fopen("students_with_class.txt", "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    char buffer[100]; // Assuming each line has at most 99 characters, adjust the size as needed
    while (fgets(buffer, sizeof(buffer), file) != NULL) {

        char params[15][20];
        int numParams = 0;
        int offset = 0;

        while (sscanf(buffer + offset, "%49s", params[numParams]) == 1) {
            numParams++;

            // Move the offset to the next word (plus 1 to skip the delimiter)
            offset += snprintf(NULL, 0, "%s", params[numParams - 1]) + 1;

            if (numParams >= 15) {
                break; // Stop if we have 15 parameters
            }
        }


        Student_t* student = createStudent(params[0], params[1], params[2],
            params[3], params[4], params[5], params[6], params[7], params[8], params[9], params[10], params[11],
            params[12], params[13], params[14]);

        StudentNode_t* studentNode = createStudentNode(student);
        addStudent(school, studentNode, params[3], params[4]);
    }

    printSchool(school);
    eraseSchool(school);

    fclose(file);
    return 0;
}
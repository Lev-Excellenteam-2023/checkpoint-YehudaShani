#define _CRT_SECURE_NO_WARNINGS
#include "school.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Program simulates school list
* A node is created for each student and every year-class has its own linked list of Student Nodes
* All students are printed and then deleted
*/


void getNameAndClass();
void getName();

char userInput[15][30];
int userIndexInput = 0;

void clear_stdin_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Keep reading and discarding characters until newline or EOF is encountered
    }
}

void getInput(char* dst, int max_size) {
    char* input = NULL;
    int len = 0;
    size_t len_size = 0;
    fgets(input, max_size, stdin);
    if (len_size == -1)
        return;
    if (len_size < max_size) {
        input[len_size - 1] = '\0';
        strncpy(dst, input, len_size);
    }
    else {
        input[max_size - 1] = '\0';
        strncpy(dst, input, max_size);
        len_size = max_size;
    }
    free(input);
}

enum menu_inputs {
    Insert = '0',
    Delete = '1',
    Edit = '2',
    Search = '3',
    Showall = '4',
    Top10 = '5',
    UnderperformedStudents = '6',
    Average = '7',
    Export = '8',
    Exit = '9'
};

void menu() {
    char option;
    int inputGrade = 0;
    School_t* school = createSchool();
    do {
        printf("\n|School Manager<::>Home|\n");
        printf("--------------------------------------------------------------------------------\n");
        //printf("Welcome to ( %s ) School!\nYou have inserted ( %zu ) students.\n\n", school.name, school.numOfStudents);
        printf("\t[0] |--> Insert\n");
        printf("\t[1] |--> Delete\n");
        printf("\t[2] |--> Edit\n");
        printf("\t[3] |--> Search\n");
        printf("\t[4] |--> Show All\n");
        printf("\t[5] |--> Top 10 students per course\n");
        printf("\t[6] |--> Underperformed students\n");
        printf("\t[7] |--> Average per course\n");
        printf("\t[8] |--> Export\n");
        printf("\t[9] |--> Exit\n");
        printf("\n\tPlease Enter Your Choice (0-9): ");
        option = getc(stdin);
        fflush(stdin);
        getc(stdin);
        switch (option) {
        case Insert:
            insertNewStudent(school);
            clear_stdin_buffer();
            break;
        case Delete:
            getNameAndClass();
            deleteStudent(school, userInput[0], userInput[1], userInput[2], userInput[3]);
            userIndexInput = 0;
        case Edit:
            getNameAndClass();
            printf("Please enter the course index you want to change: ");
            scanf("%d", &inputGrade);
            printf("Please enter the new grade: ");
            getInput(userInput[userIndexInput], 30);
            updateStudent(school, userInput[0], userInput[1], userInput[2], userInput[3], inputGrade, userInput[4]);
            userIndexInput = 0;
            break;
        case Search:
            getName();
            findAndPrintStudent(school, userInput[0], userInput[1]);
            userIndexInput = 0;
            break;
        case Showall:
            printSchool(school);
            break;
        case Top10:
            printf("Please enter the course index you want to see the top 10 students: ");
            scanf("%d", &inputGrade);
            printTopTenPerClass(school, inputGrade);
            break;
        case UnderperformedStudents:
            printUnderPerformingStudents(school);
            break;
        case Average:
            printf("Please enter the course index you want to see the average: ");
            scanf("%d", &inputGrade);
            printAverageSubjectPerClass(school, inputGrade);
            break;
        case Export:
            exportDatabase(school);
            break;
        case Exit:
            eraseSchool(school);
            break;
        default:
            printf("\nThere is no item with symbol \"%c\".Please enter a number between 1-10!\nPress any key to continue...",
                option);
            getc(stdin);
            getc(stdin);
            break;
        }
    } while (option != Exit);
}
int main(){
    School_t* school = createSchool();
    menu();
    return 0;
}

void getNameAndClass() {
    getName();
	printf("Enter student's year:\n");
	getInput(userInput[userIndexInput], 30);
	userIndexInput++;
	printf("Enter student's section:\n");
	getInput(userInput[userIndexInput], 30);
	userIndexInput++;
}

void getName() {
	printf("Enter student's first name:\n");
	getInput(userInput[userIndexInput], 30);
	userIndexInput++;
	printf("Enter student's last name:\n");
	getInput(userInput[userIndexInput], 30);
	userIndexInput++;
}
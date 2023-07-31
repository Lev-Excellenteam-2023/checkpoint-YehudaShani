#include "school.h"

int main(){

    School_t* school = malloc(sizeof(struct School));

    FILE* file;
    if (fopen_s(&file, "students_with_class.txt", "r") != 0) {
        printf("Error opening the file.\n");
        return 1;
    }
    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    char buffer[100]; // Assuming each line has at most 99 characters, adjust the size as needed

    int i = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL && i < 100) {
        // Process the line (in this example, just print it
        char params[15][20];
        i++;
        int numParams = 0;
        int offset = 0;
        while (sscanf_s(buffer + offset, "%49s", params[numParams], sizeof(params[numParams])) == 1) {
            numParams++;

            // Move the offset to the next word (plus 1 to skip the delimiter)
            offset += snprintf(NULL, 0, "%s", params[numParams - 1]) + 1;
            printf("%s ", params[numParams - 1]);



            if (numParams >= 15) {
                break; // Stop if we have 15 parameters
            }
        }

        //print all params
        for (int i = 0; i < numParams; i++) {
			printf("%s ", params[i]);
		}


        school->students[atoi(params[3])][atoi(params[4])] = createStudents(params[0], params[1], params[2],
            params[3], params[4], params[5], params[6], params[7], params[8], params[9], params[10], params[11],
            params[12], params[13], params[14]);

        printf("\n");
        printStudent(school->students[atoi(params[3])][atoi(params[4])]);


    }

    fclose(file);
    return 0;
}
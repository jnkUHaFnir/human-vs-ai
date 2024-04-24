#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The student structure
typedef struct student {
    char name[50];
} Student;

// Global parameters
int studentCount = 0;
Student *students = NULL;

// Function declarations
void addNewStudent();

int main() {
    int loop = 1;
    char in;
    int ch;
    
    printf("Welcome.\nPlease choose from the following options:\n");

    while (loop) {
        printf("\t[1] Add a new student\n");
        printf("\t[9] Exit\n");

        scanf(" %c", &in);
       
        while ((ch = getchar()) != '\n');

        switch (in) {
            case '1':
                addNewStudent();
                break;
            case '9':
                loop = 0;
                break;
            default:
                printf("------\nOption not found.\n------\n");
                break;
        }
    }

    free(students);
    return 0;
}

void addNewStudent() {
    Student *temp;

    temp = (Student*)realloc(students, sizeof(Student) * (studentCount + 1));

    if (temp == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        return;
    }

    students = temp;

    printf("Enter the name of the student: ");
    if (fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return;
    }

    // Remove the trailing newline character
    size_t length = strlen(students[studentCount].name);
    if (students[studentCount].name[length - 1] == '\n') {
        students[studentCount].name[length - 1] = '\0';
    }

    studentCount++;
}

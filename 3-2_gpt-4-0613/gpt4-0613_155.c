#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char *name;
    char *surname;
    char *UUN;
    char *department;
    char gender;
    int age;
} Student;

int main(void)  {
    int i;
    Student students[6];

    students[0].name = "John";
    //...reste of your code for first 3 students...//

    char temp[100]; // temporary string to hold the input
    for (i = 3; i < 6; i++) {
        printf("Enter your name: ");
        scanf("%s", temp);
        students[i].name = malloc(strlen(temp) + 1); // +1 for the null terminator
        strcpy(students[i].name, temp);

        //...repeat the pattern for the rest of the fields...//
    }

    //Remember to free allocated memory when you're done using it//
    for (i = 3; i < 6; i++) {
        free(students[i].name);
        free(students[i].surname);
        free(students[i].UUN);
        free(students[i].department);
    }

    return EXIT_SUCCESS;
}

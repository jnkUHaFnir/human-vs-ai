#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    char surname[MAX_LEN];
    char UUN[MAX_LEN];
    char department[MAX_LEN];
    char gender;
    int age;
} student_t;

int main(void)
{
    int i;
    student_t students[6];

    strcpy(students[0].name, "John");
    strcpy(students[0].surname, "Bishop");
    strcpy(students[0].UUN, "s1234");
    strcpy(students[0].department, "Inf");
    students[0].gender = 'm';
    students[0].age = 18;
    // ... additional student initialization here
    for (i = 3; i < 6; i++) {
        printf("Enter your name: ");
        scanf("%s", students[i].name);
        printf("Enter your surname: ");
        scanf("%s", students[i].surname);
        printf("Enter your UUN: ");
        scanf("%s", students[i].UUN);
        printf("Enter your department: ");
        scanf("%s", students[i].department);
        printf("Enter your gender: ");
        scanf(" %c", &students[i].gender); // mind the space before %c
        printf("Enter your age: ");
        scanf("%d", &students[i].age);
    }
    return EXIT_SUCCESS;
}
``` 

In this version, we have actual space for our strings within each student struct, meaning that `scanf` has a valid location to write to. 

Note: The change from `student_t[0].name = "John"` to `strcpy(student[0].name, "John")`. As `student_t[0].name` is now an array rather than a pointer, you need to use the `strcpy` function to copy the string into your array. 

For entering user data `scanf("%s", students[i].name);` is used instead of `scanf(" %s", students[i].name);`.

Additional Note: Using `scanf` for string input can be unsafe as it may lead to buffer overflow. Consider other methods (like fgets) for more practical uses.

Also, don't forget to put the space before `%c` to catch any newline character left by the previous `scanf`.

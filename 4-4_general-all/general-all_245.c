#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The student table
typedef struct students {
    char name[50];
} students;

// Global params
int scount = 0;
students *s = NULL;

// Basic functions
void addNewStudent();

int main()
{
    int loop = 1;
    char in;
    int ch;
    printf("Willkommen.\nWahlen Sie bitte von die folgenden Optionen:\n");
    while (loop)
    {
        printf("\t[1] Neue Student eingeben\n");
        printf("\t[9] Programm beenden\n");

        scanf(" %c", &in);
        while ((ch = getchar()) != '\n');
        switch (in)
        {
        case '1':
            addNewStudent();
            break;
        case '9':
            loop = 0;
            break;
        default: printf("------\nOption nicht gefunden.\n------\n");
            break;
        }
    }

    // Free memory for each student's name
    for (int i = 0; i < scount; i++) {
        free(s[i].name);
    }
    // Free memory for the array of students
    free(s);

    return 0;
}

void addNewStudent()
{
    if (scount == 0)
    {
        s = (students*)malloc(sizeof(students));
    }
    else
    {
        s = (students*)realloc(s, sizeof(students) * (scount + 1)); // reallocating memory for one more student
    }

    if (s == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Geben Sie Bitte die Name:\n");
    fgets(s[scount].name, sizeof(s[scount].name), stdin);
    s[scount].name[strcspn(s[scount].name, "\n")] = '\0'; // remove newline character if present

    scount++;
}

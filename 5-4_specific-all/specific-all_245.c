#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The student table
typedef struct student {
    char name[50];
} student;

// Global params
int scount = 0;
student *s = NULL;

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
        default:
            printf("------\nOption nicht gefunden.\n------\n");
            break;
        }
    }

    free(s);
    return 0;
}

void addNewStudent()
{
    if (scount == 0)
    {
        s = (student*)malloc(sizeof(student));
    }
    else
    {
        s = (student*)realloc(s, sizeof(student) * (scount + 1));
        if (s == NULL)
        {
            printf("Memory reallocation failed.\n");
            return;
        }
    }

    printf("Geben Sie Bitte die Name:\n");
    if (fgets(s[scount].name, sizeof(s[scount].name), stdin) != NULL)
    {
        // Remove the newline character from the input
        s[scount].name[strcspn(s[scount].name, "\n")] = '\0';
        scount++;
    }
    else
    {
        printf("Error reading input.\n");
    }
}

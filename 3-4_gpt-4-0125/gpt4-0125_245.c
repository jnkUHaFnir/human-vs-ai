#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct students {
    char name[50];
} students;

//Global params
int scount = 0;
students *s = NULL; // Initialize to NULL for clarity

//Basic functions
void addNewStudent();

int main()
{
    int loop = 1;
    char in;
    int ch;
    printf("Willkommen.\n Wahlen Sie bitte von die folgenden Optionen:\n");
    while (loop)
    {
        printf("\t[1] Neue Student eingeben\n");
        printf("\t[9] Programm beenden\n");

        scanf(" %c", &in);
        while ((ch = getchar()) != '\n' && ch != EOF); // EOF check for robustness
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
    free(s); // Free the allocated memory
    return 0;
}

void addNewStudent()
{
    students *temp = realloc(s, sizeof(students) * (scount + 1)); // Allocate/reallocate memory
    if (temp == NULL)
    {
        printf("Fehler bei der Speicherallokation\n");
        return; // Exit the function if memory allocation fails
    }
    s = temp; // Assign the newly allocated memory back to s

    printf("Geben Sie Bitte die Name:\n");
    if (fgets(s[scount].name, sizeof(s[scount].name), stdin) != NULL)
    {
        // Remove the newline character if present
        size_t len = strlen(s[scount].name);
        if (len > 0 && s[scount].name[len - 1] == '\n') {
            s[scount].name[len - 1] = '\0';
        }
    }
    else
    {
        printf("Eingabefehler\n");
        return; // Handle fgets input error
    }

    scount++; // Increase the count of students only after successful addition
}

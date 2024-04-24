#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct students {
    char name[50];
} students;

int scount = 0;
students *s = NULL;

void addNewStudent();

int main()
{
    int loop = 1;
    char in;
    int ch;
    printf("Willkommen.\nWählen Sie bitte von den folgenden Optionen:\n");
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

    if (s != NULL) {
        free(s);
    }
    return 0;
}

void addNewStudent()
{
    if (s == NULL) {
        s = (students*)malloc(sizeof(students));
    } else {
        s = (students*)realloc(s, sizeof(students) * (scount + 1));
    }

    if (s == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    printf("Geben Sie bitte den Namen:\n");
    fgets(s[scount].name, sizeof(s[scount].name), stdin);

    // Remove the newline character
    s[scount].name[strcspn(s[scount].name, "\n")] = 0;

    scount++;
}

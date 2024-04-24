s = realloc(s, sizeof(students) * scount);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct students {
    char name[50];
} students;

int scount = 0;
students *s;

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
    free(s);
    return 0;
}

void addNewStudent()
{
    int index = 0;
    if (scount == 0)
    {
        s = malloc(sizeof(students));
    }
    else
    {
        students* temp = realloc(s, sizeof(students) * scount);
        if (temp == NULL) {
            fprintf(stderr, "Error: Memory allocation failed\n");
            return;
        }
        s = temp;
    }

    printf("Geben Sie Bitte den Namen ein:\n");
    fgets(s[scount].name, sizeof(s[scount].name), stdin);

    while (s[scount].name[index] != '\n')
    {
        index++;
    }
    s[scount].name[index] = '\0';
    scount++;
}

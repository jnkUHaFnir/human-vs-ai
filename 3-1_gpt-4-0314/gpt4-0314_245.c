#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//The student table
typedef struct students {
    char name[50];
} students;

//Global params
int scount = 0;
students *s;

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
        s = (students*)malloc(sizeof(students));
    }
    else
    {
        s = (students*)realloc(s, sizeof(students) * (scount + 1)); //Assign the result of realloc to s, and allocate size for the new student
    }

    printf("Geben Sie Bitte die Name:\n");
    fgets(s[scount].name, sizeof(s[scount].name), stdin);

    //Remove the newline character from the input
    s[scount].name[strcspn(s[scount].name, "\n")] = 0;

    scount++;
}

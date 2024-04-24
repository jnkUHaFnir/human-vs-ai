#include <stdio.h>
#include <stdlib.h>

char* createList();

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    char input[50];
    int check; // Changed type to int
    do {
        check = scanf("%49s", input); // Added limit to prevent buffer overflow and changed the loop control
        if(check == 1) {  // Check if scanf successfully read a string
            printf("%s\n", input);
        }
    } while (check != EOF); // Continue until EOF

    fflush(stdout);

    char* myAnswer = createList();
    printf("%s\n", myAnswer);
    
    free(myAnswer); // Don't forget to free allocated memory!

    return 0;
}

char* createList()
{
    char* msg = malloc(6 * sizeof(char));
    if (msg != NULL) { // Always check if malloc was successful
        msg[0] = 'A';
        msg[1] = 'B';
        msg[2] = 'C';
        msg[3] = 'D';
        msg[4] = 'E';
        msg[5] = '\0';
    }
    return msg;
}

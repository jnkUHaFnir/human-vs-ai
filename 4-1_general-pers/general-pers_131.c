#include <stdio.h>
#include <stdlib.h>

char* createList();

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    
    char input[50];
    int check;
    
    while ((check = scanf("%49s", input)) != EOF) {
        if (check == 1) {
            printf("%s\n", input);
        } else {
            fprintf(stderr, "Error reading input.\n");
            break;
        }
    }

    fflush(stdout);

    char* myAnswer = createList();
    if (myAnswer != NULL) {
        printf("%s\n", myAnswer);
        free(myAnswer); // Don't forget to free the memory allocated in createList()
    } else {
        fprintf(stderr, "Error creating list.\n");
    }

    return 0;
}

char* createList()
{
    char* msg = malloc(6 * sizeof(char));
    if (msg != NULL) {
        msg[0] = 'A';
        msg[1] = 'B';
        msg[2] = 'C';
        msg[3] = 'D';
        msg[4] = 'E';
        msg[5] = '\0';
    }
    return msg;
}

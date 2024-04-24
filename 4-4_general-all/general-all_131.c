#include <stdio.h>
#include <stdlib.h>

char* createList();

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    char input[50];
    int check;
    for (int i = 0; (check = scanf("%49s", input)) != EOF; ++i) {
        if (check == 0) {
            scanf("%*c"); // Clear the invalid input
        } else {
            printf("%s\n", input);
        }
    }

    fflush(stdout);

    char* myAnswer = createList();
    printf("%s\n", myAnswer);

    free(myAnswer); // Don't forget to free the memory allocated in createList()

    return 0;
}

char* createList() {
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

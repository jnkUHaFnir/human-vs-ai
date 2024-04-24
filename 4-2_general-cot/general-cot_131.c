#include <stdio.h>
#include <stdlib.h>

char* createList();
void clearInputBuffer();

int main(void)
{
    char input[50];
    char check = 'a';
    while (check != EOF) {
        check = scanf("%s", input);
        if (check != EOF) {
            printf("%s\n", input);
            clearInputBuffer(); // Clear input buffer after reading
        }
    }

    fflush(stdout);

    char* myAnswer = createList();
    printf("%s\n", myAnswer);
    free(myAnswer); // Free allocated memory

    return 0;
}

char* createList(){
    char* msg = malloc(6*sizeof(char));
    if (msg != NULL) { // Check if memory allocation was successful
        msg[0]='A';
        msg[1]='B';
        msg[2]='C';
        msg[3]='D';
        msg[4]='E';
        msg[5]='\0';
    }
    return msg;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

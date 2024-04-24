#include <stdio.h>
#include <stdlib.h>

char* createList();

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    char input[50];
    int check; // Change check to int to properly store scanf return value

    while ((check = scanf("%s", input)) != EOF) {
        printf("%s\n", input);
    }

    fflush(stdout);

    char* myAnswer = createList();
    printf("%s\n", myAnswer);

    free(myAnswer); // Don't forget to free memory allocated in createList

    return 0;
}

char* createList(){
    char* msg = malloc(6*sizeof(char));
    if (msg != NULL) {
        msg[0]='A';
        msg[1]='B';
        msg[2]='C';
        msg[3]='D';
        msg[4]='E';
        msg[5]='\0';
    }
    return msg;
}

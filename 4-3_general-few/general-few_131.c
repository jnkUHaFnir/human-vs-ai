#include <stdio.h>
#include <stdlib.h>

char* createList(){
    char* msg = malloc(6*sizeof(char));
    msg[0]='A';
    msg[1]='B';
    msg[2]='C';
    msg[3]='D';
    msg[4]='E';
    msg[5]='\0';
    return msg;
}

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    char input[50];
    char check = 'a';

    while (fgets(input, sizeof(input), stdin) != NULL) {
        printf("%s", input);
    }

    fflush(stdout);

    char* myAnswer = createList();
    printf("%s\n", myAnswer);

    free(myAnswer);

    return 0;
}

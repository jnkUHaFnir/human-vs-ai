#include <stdio.h>
#include <stdlib.h>

char* createList();

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    char input[50];
    int idx = 0;
    char check = getchar(); // Read one character
    
    while (check != EOF) { // Continue until reaching EOF
        input[idx++] = check;
        check = getchar();
    }
    input[idx] = '\0';

    printf("%s\n", input);

    fflush(stdout);

    char* myAnswer = createList();
    printf("%s\n", myAnswer);

    return 0;
}

//-----------------------------------------------------------------------------

char* createList(){
    char* msg = malloc(6 * sizeof(char));
    msg[0] = 'A';
    msg[1] = 'B';
    msg[2] = 'C';
    msg[3] = 'D';
    msg[4] = 'E';
    msg[5] = '\0';
    return msg;
}

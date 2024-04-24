#include <stdio.h>
#include <stdlib.h>

char* createList();

int main(void)
{
    setvbuf (stdout, NULL, _IONBF, 0);
    char input[50];
    int check = 1; // Corrected data type to int and initial value to 1

    while (check == 1){ // Check for successful reading
        check = scanf("%49s", input); // Limit the input length to avoid buffer overflow
        if(check == 1) {
            printf("%s\n", input);
        }
    }

    fflush(stdout);

    char* myAnswer = createList();
    printf("%s\n", myAnswer);

    free(myAnswer); // Don't forget to free the memory allocated by malloc

    return 0;
}

char* createList(){
    char* msg = malloc(6*sizeof(char));
    if(msg == NULL) {
        // Handle malloc failure here
        exit(1);
    }
    msg[0]='A';
    msg[1]='B';
    msg[2]='C';
    msg[3]='D';
    msg[4]='E';
    msg[5]='\0';
    return msg;
}

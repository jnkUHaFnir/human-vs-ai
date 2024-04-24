#include <stdio.h>
#include <stdlib.h>

char* createList();

int main(void)
{
    setvbuf (stdout, NULL, _IONBF, 0);
    char input[50];
    int check = 1;
    while(check > 0){
        check = scanf("%49s", input);
        printf("%s\n",input);
    }

    char* myAnswer = createList();
    printf("%s\n", myAnswer);
    free(myAnswer);

    return 0;
}

char* createList(){
    char* msg = malloc(6*sizeof(char));
    if (msg == NULL) {
        perror("Malloc failed");
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

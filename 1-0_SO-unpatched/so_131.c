    #include <stdio.h>
    #include <stdlib.h>
    char* createList();
    int main(void)
    {
        setvbuf (stdout, NULL, _IONBF, 0);
        char input[50];
        int check = 'a';
        for(;;){
            check = scanf("%s", input);
            if (check == EOF) break;
            printf("%s\n",input);
        }
        fflush(stdout);
        char* myAnswer = createList();
        printf("%s\n", myAnswer);
        return 0;
    }
    //-----------------------------------------------------------------------------
    
    char* createList(){
        char* msg = (char *) malloc(6*sizeof(char));
        msg[0]='A';
        msg[1]='B';
        msg[2]='C';
        msg[3]='D';
        msg[4]='E';
        msg[5]='\0';
        return msg;
    }
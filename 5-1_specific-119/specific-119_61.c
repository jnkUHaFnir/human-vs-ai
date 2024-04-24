#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct  Person{
    char *name;
    char *surname;
    char *address;
    char *number;
} Person;

char *getString(void);

int main(void) {
    struct Person *rub = NULL, *ttmp = NULL;
    int idx=0,i,j;
    char c;
    char *tmp = NULL;
    do{
        printf("*******************************\ni - Insert new\n");
        printf("n - Find by name\n");
        printf("c - Find by surname\n");
        printf("e - Delete\n");
        printf("p - Print list\n");
        printf("0 - Exit\n*******************************\n");
        c = getchar();
        getchar();
        
        switch(c){
            case 'i':
                ttmp = (struct Person *) realloc(rub, (idx+1)*sizeof(Person));
                if(ttmp == NULL){
                    printf("Cannot allocate more memory.\n");
                    exit(1);
                }
                else
                    rub = ttmp;

                printf("Nome: ");
                tmp = getString();
                rub[idx].name = strdup(tmp);
                free(tmp);  // Free the temporary buffer
                
                printf("Surname: ");
                tmp = getString();
                rub[idx].surname = strdup(tmp);
                free(tmp);

                printf("Address: ");
                tmp = getString();
                rub[idx].address = strdup(tmp);
                free(tmp);

                printf("Number: ");
                tmp = getString();
                rub[idx].number = strdup(tmp);
                free(tmp);

                idx++;
                for(j=0;j<idx;j++){
                    printf("%d) %s %s\n%s\n%s\n-------------------\n", j+1, rub[j].name,rub[j].surname,rub[j].address,rub[j].number);
                }
                break;
            case 'n':
                printf("What name are you looking for? ");
                tmp = getString();
                for(j=0;j<idx;j++){
                    if(strcmp(rub[j].name,tmp) == 0){
                        printf("%s\n%s\n%s\n%s\n", rub[j].name,rub[j].surname,rub[j].address,rub[j].number);
                    }
                }
                free(tmp);
                break;
            // Other cases remain the same
        }
    }
    while(c != '0');

    // Free allocated memory before exiting
    for(i=0;i<idx;i++){
        free(rub[i].name);
        free(rub[i].surname);
        free(rub[i].address);
        free(rub[i].number);
    }
    free(rub);

    return 0;
}

char * getString(void){
    char *stringa = NULL;
    size_t len = 0;
    ssize_t read;

    // Read input using fgets to prevent buffer overflow
    read = getline(&stringa, &len, stdin);

    // Remove newline character if present
    if (read > 0 && stringa[read-1] == '\n') {
        stringa[read-1] = '\0';
    }
    
    return stringa;
}

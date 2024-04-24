#include <stdio.h>
#include <stdlib.h>

// Change the signature of the function to accept a double pointer
void getString(char ** string);

int main(void){

    char * str = NULL;

    printf("Write something:\n");
    getString(&str);  // Pass the address of str
    printf("You wrote:\n");
    printf("%s\n", str);
    free(str);

    return 0;
}

// Modify the function to dereference string to update the original pointer
void getString(char ** string){
    char ch;
    int length = 0;

    do{
        scanf("%c", &ch);
        if(length == 0){
            *string = (char *) malloc(sizeof(char));
        } else {
            *string = (char *) realloc(*string, (length + 1) * sizeof(char));
        }
        if(*string == NULL){
            printf("ERROR: memory could not be allocated!!\n");
            exit(1);  // Since you can't allocate, you should probably exit.
        }

        (*string)[length] = ch;
        length++;
    } while(ch != '\n');

    (*string)[length - 1] = '\0';
}

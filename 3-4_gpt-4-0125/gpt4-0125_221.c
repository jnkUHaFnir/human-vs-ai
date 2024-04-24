#include <stdio.h>
#include <stdlib.h>

void getString(char ** string); // Notice the double pointer

int main(void){
    char * str = NULL;

    printf("Write something:\n");
    getString(&str); // Pass the address of str
    printf("You wrote:\n");
    printf("%s\n", str);
    free(str); // Don't forget to free the allocated memory

    return 0;
}

void getString(char ** string){
    char ch;
    int length = 0;
    *string = NULL; // Initialize the dereferenced pointer to NULL

    do{
        scanf("%c", &ch);
        if(length == 0){
            *string = (char *) malloc(sizeof(char));
        } else {
            *string = (char *) realloc(*string, (length + 1) * sizeof(char));
        }
        if(*string == NULL){
            printf("ERROR: memory could not be allocated!!\n");
            return;
        }

        (*string)[length] = ch;
        length++;
    } while(ch != '\n');

    (*string)[length - 1] = '\0'; // Replace the last character (newline) with a string terminator
}

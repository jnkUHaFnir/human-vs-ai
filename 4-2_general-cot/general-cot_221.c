#include <stdio.h>
#include <stdlib.h>

void getString(char ** string);

int main(void){
    char * str = NULL;

    printf("Write something:\n");
    getString(&str);
    printf("You wrote:\n");
    printf("%s\n", str);
    free(str);

    return 0;
}

void getString(char ** string) {
    char ch;
    int length = 0;
    
    *string = (char *) malloc(sizeof(char)); // Allocate memory for the first character
    
    do {
        scanf("%c", &ch);
        
        char * temp = (char *) realloc(*string, (length + 1) * sizeof(char)); // Reallocate memory
        if(temp == NULL){
            printf("ERROR: memory could not be allocated!!\n");
            break;
        } else {
            *string = temp;
        }
        
        (*string)[length] = ch; // Update the value
        length++;
    } while(ch != '\n');

    (*string)[length - 1] = '\0'; // Add null terminator
}

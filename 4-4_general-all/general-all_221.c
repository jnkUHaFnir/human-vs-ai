#include <stdio.h>
#include <stdlib.h>

void getString(char ** string);

int main(void){
    char * str = NULL;

    printf("Write something:\n");
    getString(&str); // Pass the address of the pointer
    printf("You wrote:\n");
    printf("%s\n", str);
    free(str);

    return 0;
}

void getString(char ** string){
    char ch;
    int length = 0;
    *string = NULL; // Initialize the pointer before reallocating

    do {
        scanf("%c", &ch);
        if(ch == '\n') {
            break;
        }
        (*string) = (char *) realloc((*string), (length + 1) * sizeof(char)); // Dereference the pointer
        if((*string) == NULL){
            printf("ERROR: memory could not be allocated!!\n");
            return;
        }
        
        (*string)[length] = ch;
        length++;
    } while(1);

    (*string)[length] = '\0';
}

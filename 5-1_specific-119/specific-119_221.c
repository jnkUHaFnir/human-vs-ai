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

void getString(char ** string){
    char ch;
    int length = 0;
    *string = (char *) malloc(sizeof(char));

    if(*string == NULL){
        printf("ERROR: memory could not be allocated!!\n");
    }
  
    do{
        scanf("%c", &ch);
        *string = (char *) realloc(*string, (length + 1) * sizeof(char));

        if(*string == NULL){
            printf("ERROR: memory could not be allocated!!\n");
        }

        (*string)[length] = ch;
        length++;
    } while(ch != '\n');

    (*string)[length - 1] = '\0';
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** str_split(char* str, char delimiter){
    char **token_array = malloc(sizeof(char*));
    int num_tokens = 0;
    
    char* token = strtok(str, &delimiter);
    while(token != NULL){
        token_array = realloc(token_array, (num_tokens + 1) * sizeof(char*));
        token_array[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, &delimiter);
    }
    
    token_array = realloc(token_array, (num_tokens + 1) * sizeof(char*));
    token_array[num_tokens] = NULL; //add a null terminator at the end
    
    return token_array;
}

int main(){
    char* str = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    char** tokens = str_split(str, ',');
    
    int i = 0;
    while(tokens[i] != NULL){
        printf("%s\n", tokens[i]);
        i++;
    }
    
    // free memory allocated for tokens
    free(tokens);
    
    return 0;
}

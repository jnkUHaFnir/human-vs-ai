struct tuple_t *tuple_create2(int tuple_dim, char **tuple_data){
    // Allocate memory for the tuple struct
    struct tuple_t *t = (struct tuple_t *) malloc(sizeof(struct tuple_t));
    if(t == NULL)
        return NULL;

    // Allocate memory for the tuple elements
    t->tuple = (char **) malloc(tuple_dim * sizeof(char *));
    if(t->tuple == NULL){
        free(t);
        return NULL;
    }

    // Copy the tuple data into the allocated memory
    for (int i = 0; i < tuple_dim; i++){
        t->tuple[i] = strdup(tuple_data[i]);
        if(t->tuple[i] == NULL){
            // Clean up allocated memory if strdup fails
            for (int j = 0; j < i; j++){
                free(t->tuple[j]);
            }
            free(t->tuple);
            free(t);
            return NULL;
        }
    }

    t->tuple_dimension = tuple_dim;
    
    return t;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char s[4];
    strcpy(s, "ABC");
    printf("%s\n", s);
    sprintf(s, "DEF");
    printf("%s\n", s);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tuple_t {
    int tuple_dimension; 
    char **tuple;        
};

struct tuple_t *tuple_create2(int tuple_dim, char **tuple){
    struct tuple_t *t = (struct tuple_t *) malloc(sizeof(struct tuple_t));

    if(t == NULL)
        return NULL;

    t->tuple_dimension = tuple_dim;

    t->tuple = (char**)malloc(tuple_dim * sizeof(char*));
    if(t->tuple == NULL) {
        free(t);
        return NULL;
    }

    for(int i = 0; i < tuple_dim; i++) {
        t->tuple[i] = (char*)malloc(strlen(tuple[i]) + 1);
        if(t->tuple[i] == NULL) {
            // Clean up allocated memory before returning
            for(int j = 0; j < i; j++) {
                free(t->tuple[j]);
            }
            free(t->tuple);
            free(t);
            return NULL;
        }
        strcpy(t->tuple[i], tuple[i]);
    }

    return t;
}

void tuple_destroy(struct tuple_t *t) {
    for(int i = 0; i < t->tuple_dimension; i++) {
        free(t->tuple[i]);
    }
    free(t->tuple);
    free(t);
}

int testRemoveMeio() {
    int result, i;
    struct list_t *list = list_create();

    char *tdata[3] = {"   ", "2014", "Fixe!"};
    struct tuple_t *t = tuple_create2(3, tdata);
    struct tuple_t *tdups[4];

    struct entry_t *entries[4];

    if (t == NULL) {
        // Handle allocation failure
        return -1;
    }

    strcpy(t->tuple[0], "abc"); // copy content instead of modifying string literal

    tdups[0] = tuple_dup(t);
    entries[0] = entry_create(tdups[0]);
    list_add(list, entries[0]);

    //extra code similar to above
    
    tuple_destroy(t); // Cleanup allocated memory
    
    return 0;
}

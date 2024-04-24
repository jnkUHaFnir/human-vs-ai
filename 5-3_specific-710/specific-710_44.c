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

    t->tuple = (char **)malloc(tuple_dim * sizeof(char *));
    if(t->tuple == NULL) {
        free(t);
        return NULL;
    }

    for(int i = 0; i < tuple_dim; i++) {
        t->tuple[i] = strdup(tuple[i]);
        if(t->tuple[i] == NULL) {
            for(int j = 0; j < i; j++) {
                free(t->tuple[j]);
            }
            free(t->tuple);
            free(t);
            return NULL;
        }
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

int testRemoveMeio(){

    int result, i;
    struct list_t *list = list_create();

    char *tdata[3] = {"   ", "2014", "Fixe!"};
    struct tuple_t *t = tuple_create2(3, tdata);
    struct tuple_t *tdups[4];
    struct entry_t *entries[4];

    // Check if tuple creation was successful
    if(t == NULL) {
        return -1;
    }

    tdups[0] = tuple_create2(t->tuple_dimension, t->tuple);
    
    // Check if tuple duplication was successful
    if(tdups[0] == NULL) {
        tuple_destroy(t);
        return -1;
    }

    // Now you can safely modify the tuple
    strcpy(t->tuple[0], "abc");

    entries[0] = entry_create(tdups[0]);
    list_add(list, entries[0]);

    // Remember to free the memory allocated
    tuple_destroy(t);
    tuple_destroy(tdups[0]);

    return 0;
}

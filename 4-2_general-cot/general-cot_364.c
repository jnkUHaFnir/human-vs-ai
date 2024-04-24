#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *data;
    struct node *left;
    struct node *right;
};

void delete(struct node **root){
    char array[13];
    struct node *toDelete = NULL;
    printf ("Please specify a name to delete\n");
    scanf("%s", array);
    // To delete the node, we need to pass the address of the root pointer
    removeChild(root, array); 
}

void removeChild(struct node **root, char* name) {
    if ((*root) == NULL) {
        return;
    }

    removeChild(&((*root)->left), name);
    removeChild(&((*root)->right), name);

    if (strcmp((*root)->data, name) == 0) {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        }
    }
}

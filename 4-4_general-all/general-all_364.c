#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *data;
    struct node *left;
    struct node *right;
} *child;

struct node* createNode(char *data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = strdup(data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void freeNode(struct node* target) {
    // Free data
    free(target->data);
    target->data = NULL;

    // Free node
    free(target);
    target = NULL;
}

void deleteNode(struct node* root, struct node* target) {
    if (root == NULL) {
        return;
    }

    if (root->left == target) {
        root->left = NULL;
        freeNode(target);
    }

    if (root->right == target) {
        root->right = NULL;
        freeNode(target);
    }

    deleteNode(root->left, target);
    deleteNode(root->right, target);
}

void delete(struct node* root) {
    char array[13];
    struct node* toDelete = NULL;

    printf("Please specify a name to delete: ");
    scanf("%s", array);

    // Find the node to delete
    toDelete = scan(root, array);

    if (toDelete == NULL) {
        printf("ERROR -- Node does not exist\n");
    } else {
        deleteNode(root, toDelete);
    }
}


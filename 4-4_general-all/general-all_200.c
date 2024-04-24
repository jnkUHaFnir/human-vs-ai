#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
  struct TreeNode *leftPtr;
  char data[9];
  struct TreeNode *rightPtr;
};

typedef struct TreeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, char value[]);
TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, char key[]);

int main(void) {
    int i;
    const char * items[] = { "cea", "riz", "mac", "roz", "bee", "lea", "tee", "pee", "see" };
    char searchKey[10];
    TreeNodePtr rootPtr = NULL;
    TreeNodePtr searchResultPtr;

    printf("The strings being placed in the tree are:\n");

    for (i = 0; i < 9; i++) {
        insertNode(&rootPtr, items[i]);
        printf("%s\t", items[i]);
    }

    printf("\n\nEnter a string to search for: ");
    scanf("%s", searchKey);
    searchResultPtr = binaryTreeSearch(rootPtr, searchKey);

    if (searchResultPtr == NULL) {
        printf("\n%s was not found in the tree.\n\n", searchKey);
    } else {
        printf("\n%s was found in the tree.\n\n", searchResultPtr->data);
    }

    getchar();
    getchar();
    return 0;
}

void insertNode(TreeNodePtr *treePtr, char value[]) {
    if (*treePtr == NULL) {
        *treePtr = malloc(sizeof(TreeNode));

        if (*treePtr != NULL) {
            strcpy((*treePtr)->data, value);
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        } else {
            printf("%s not inserted. No memory available.\n", value);
        }
    } else {
        if (strcmp(value, (*treePtr)->data) < 0) {
            insertNode(&((*treePtr)->leftPtr), value);
        } else if (strcmp(value, (*treePtr)->data) > 0) {
            insertNode(&((*treePtr)->rightPtr), value);
        } else {
            printf("Duplicate value %s\n", value);
        }
    }
}

TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, char key[]) {
    if (treePtr == NULL) {
        return NULL;
    } else if (strcmp(key, treePtr->data) == 0) {
        return treePtr;
    } else if (strcmp(key, treePtr->data) < 0) {
        return binaryTreeSearch(treePtr->leftPtr, key);
    } else {
        return binaryTreeSearch(treePtr->rightPtr, key);
    }
}

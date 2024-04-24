#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TreeNode structure definition */
struct TreeNode
{
    struct TreeNode *leftPtr; /* pointer to left subtree */
    char data[9];            /* node data */
    struct TreeNode *rightPtr;/* pointer to right subtree */
};

typedef struct TreeNode TreeNode;
typedef TreeNode *TreeNodePtr;

/* function prototypes */
void insertNode(TreeNodePtr *treePtr, char value[]);
TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, char key[]);

int main(void)
{
    int i;
    const char *item[] = {"cea", "riz", "mac", "roz", "bee", "lea", "tee", "pee", "see"};
    char searchKey[9]; /* Increased size to accommodate 9 characters plus null terminator */
    TreeNodePtr rootPtr = NULL;
    TreeNodePtr searchResultPtr;

    printf("The strings being placed in the tree are:\n");

    for (i = 0; i < 9; i++) { // Corrected loop condition
        printf("%s\t", item[i]);
        insertNode(&rootPtr, item[i]);
    }

    printf("\nEnter a string to search for: ");
    scanf("%8s", searchKey); // Read up to 8 characters to avoid buffer overflow
    searchResultPtr = binaryTreeSearch(rootPtr, searchKey);

    if (searchResultPtr == NULL) {
        printf("\n%s was not found in the tree.\n\n", searchKey);
    } else {
        printf("\n%s was found in the tree.\n\n", searchResultPtr->data);
    }

    return 0;
}

/* insert a node into the tree */
void insertNode(TreeNodePtr *treePtr, char value[])
{
    if (*treePtr == NULL)
    {
        *treePtr = malloc(sizeof(TreeNode));
      
        if (*treePtr != NULL)
        {
            strcpy((*treePtr)->data, value);
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        } 
        else
        {
            printf("%s not inserted. No memory available.\n", value);
        }
    }
    else
    {
        if (strcmp(value, (*treePtr)->data) < 0)
        {
            insertNode(&((*treePtr)->leftPtr), value);
        }
        else if (strcmp(value, (*treePtr)->data) > 0)
        {
            insertNode(&((*treePtr)->rightPtr), value);
        }
        else
        {
            printf("Duplicate value: %s\n", value);
        }
    }
}

/* search for key in tree */
TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, char key[])
{
    if (treePtr == NULL)
    {
        return NULL;
    }
    else if (strcmp(treePtr->data, key) == 0)
    {
        return treePtr;
    }
    else if (strcmp(key, treePtr->data) < 0)
    {
        return binaryTreeSearch(treePtr->leftPtr, key);
    }
    else // (strcmp(key, treePtr->data) > 0)
    {
        return binaryTreeSearch(treePtr->rightPtr, key);
    }
}

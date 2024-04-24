#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Tree {
    int val;
    char *word;
    struct Tree *left;
    struct Tree *right;
} Tree;

void show(Tree *hd) {
    if (hd != NULL) {
        show(hd->left);
        show(hd->right);
        printf("%s -- %d\n", hd->word, hd->val);
    }
}

void zero(Tree *aTree) {
    if (aTree == NULL)
        return;

    zero(aTree->left);
    zero(aTree->right);
    free(aTree->word); // Free word memory before freeing the node
    free(aTree);  
}

int alpha(const char *word1, const char *word2) {
    return strcmp(word1, word2);
}

Tree *create(const char *word) {
    Tree *temp = (Tree*)malloc(sizeof(Tree));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    temp->left = NULL;
    temp->right = NULL;
    temp->val = 1;
    temp->word = strdup(word); // Use strdup to allocate memory and copy string
    return temp;
}

Tree *insert(Tree *aTree, const char *word) {
    if (aTree == NULL) {
        aTree = create(word);
    } else {
        int cmp = alpha(aTree->word, word);
        if (cmp == 0) {
            aTree->val++;
        } else if (cmp > 0) {
            aTree->left = insert(aTree->left, word);
        } else {
            aTree->right = insert(aTree->right, word);
        }
    }
    return aTree;
}

int main(int argc, char *argv[]) {
    Tree *myTree = NULL;
    char buffer[256] = {0};
    int i;
    FILE *fp = fopen(argv[1], "r");
    if (fp) {
        char temp;
        while ((temp = fgetc(fp)) != EOF) {
            temp = toupper(temp);
            if (isalpha(temp)) {
                buffer[i++] = temp;
            } else {
                if (i > 0) {
                    buffer[i] = '\0'; // Null-terminate the string
                    puts(buffer);
                    myTree = insert(myTree, buffer);
                    i = 0;
                    memset(buffer, 0, sizeof(buffer));
                }
            }
        }
        fclose(fp);
    } else {
        fprintf(stderr, "Failed to open file\n");
        return EXIT_FAILURE;
    }

    show(myTree);
    zero(myTree); // Free memory used by the binary tree

    return 0;
}

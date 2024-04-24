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
    free(aTree->word);
    free(aTree);  
}

int alpha(const char *word1, const char *word2) {
    return strcmp(word1, word2);
}

Tree *create(const char *word) {
    Tree *temp = (Tree*)malloc(sizeof(Tree));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    temp->left = temp->right = NULL;
    temp->val = 1;
    temp->word = strdup(word);

    if (temp->word == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    return temp;
}

Tree *insert(Tree *aTree, const char *word) {
    if (aTree == NULL) {
        return create(word);
    }

    int comparison = alpha(aTree->word, word);
    
    if (comparison > 0) {
        aTree->left = insert(aTree->left, word);
    } else if (comparison < 0) {
        aTree->right = insert(aTree->right, word);
    } else {
        aTree->val++;
    }

    return aTree;
}

int main(int argc, char *argv[]) {
    Tree *myTree = NULL;
    char buffer[256] = { 0 };
    char temp = 0;
    int i = 0;
    FILE *fp = fopen(argv[1], "r");
    if (fp)  {
        while ((temp = getc(fp)) != EOF) {
            temp = toupper((unsigned char)temp);
            if (isalpha((unsigned char)temp)) {
                buffer[i] = temp;
                i++;
            } else {
                if (buffer[0] != 0) {
                    printf("%s\n", buffer);
                    myTree = insert(myTree, buffer);
                    memset(buffer, 0, sizeof(buffer));
                    i = 0;
                }
            }
        }
        fclose(fp);
    } else {
        fprintf(stderr, "Unable to open file.\n");
        return 1;
    }

    show(myTree);

    // Free the memory used by the tree
    zero(myTree);

    return 0;
}

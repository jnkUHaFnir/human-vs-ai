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

int alpha(char *word1, char *word2) {
    if (word1[0] == 0 && word2[0] == 0)
        return 2;
    else if (word1[0] == word2[0])
        return alpha(&word1[1], &word2[1]);
    else if (word1[0] < word2[0])
        return 1;
    else
        return 0;
}

Tree *create(char *word) {
    Tree *temp = (Tree*)malloc(sizeof(Tree));
    temp->left = temp->right = NULL;
    temp->val = 1;
    temp->word = (char*)malloc(strlen(word) + 1); // Allocate memory for the word
    strcpy(temp->word, word);
    return temp;
}

Tree *insert(Tree *aTree, char *word) {
    if (aTree == NULL) {
        aTree = create(word);
    } else {
        int cmp = alpha(aTree->word, word);
        if (cmp == 0) {
            aTree->left = insert(aTree->left, word);
        } else if (cmp == 1) {
            aTree->right = insert(aTree->right, word);
        } else {
            aTree->val++;
        }
    }
    return aTree;
}

int main(int argc, char *argv[]) {
    Tree *myTree = NULL;
    char buffer[256] = { 0 };
    int i = 0;
    FILE *fp = fopen(argv[1], "r");

    if (fp) {
        char temp;
        while ((temp = getc(fp)) != EOF) {
            temp = toupper(temp);
            if (isalpha(temp)) {
                buffer[i] = temp;
                i++;
            } else {
                if (buffer[0] != 0) {
                    puts(buffer);
                    myTree = insert(myTree, buffer);
                    memset(buffer, 0, sizeof(buffer));
                    i = 0;
                }
            }
        }
        fclose(fp);
    } else {
        printf("Error opening file.\n");
        return 1;
    }

    show(myTree);
    zero(myTree); // Free memory allocated for the tree nodes
    return 0;
}

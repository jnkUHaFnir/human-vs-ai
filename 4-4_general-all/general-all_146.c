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
        printf("%s -- %d\n", hd->word, hd->val);
        show(hd->right);
    }
}

void zero(Tree *aTree) {
    if (aTree == NULL)
        return;

    zero(aTree->left);
    zero(aTree->right);
    free(aTree->word); // Free the word as well
    free(aTree);    
}

int alpha(const char *word1, const char *word2) {
    if (*word1 == '\0' && *word2 == '\0')
        return 2;
    else if (*word1 == *word2)
        return alpha(word1 + 1, word2 + 1);
    else if (*word1 < *word2)
        return 1;
    else
        return 0;
}

Tree *create(const char *word) {
    Tree *temp = (Tree*)malloc(sizeof(Tree));
    temp->left = temp->right =  NULL;
    temp->val = 1;
    temp->word = strdup(word);
    return temp;
}

Tree *insert(Tree *aTree, const char *word) {
    if (aTree == NULL) {
        aTree = create(word);
    } else {
        int comparison = alpha(aTree->word, word);
        if (comparison == 0) {
            aTree->left = insert(aTree->left, word);
        } else if (comparison == 1) {
            aTree->right = insert(aTree->right, word);
        } else if (comparison == 2) {
            aTree->val++;
        }
    }
    return aTree;
}

int main(int argc, char *argv[]) {
    Tree *myTree = NULL;
    char buffer[256] = { 0 };
    char temp = 0;
    int i = 0;
    FILE *fp = fopen(argv[1], "r");
    if (fp) {
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
        show(myTree);
        zero(myTree); // Free the memory to avoid memory leaks
    } else {
        printf("Failed to open file.\n");
    }
    return 0;
}

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

    free(aTree->word); // Free the allocated word memory
    free(aTree);
}

int alpha(const char *word1, const char *word2) {
    if (word1[0] == 0 && word2[0] == 0)
        return 2;
    else if (word1[0] == word2[0])
        return alpha(&word1[1], &word2[1]);
    else if (word1[0] < word2[0])
        return 1;
    else
        return 0;
}

Tree *create(const char *word) {
    Tree *temp = (Tree*)malloc(sizeof(Tree));
    temp->left = temp->right = NULL;
    temp->val = 1;

    size_t length = strlen(word);
    temp->word = (char*)malloc(length + 1); // Allocate memory for word + null terminator
    strcpy(temp->word, word);

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
        } else {
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
        while ((temp = fgetc(fp)) != EOF) {
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
    }

    show(myTree);

    // Clean up the memory
    zero(myTree);

    return 0;
}

#include <stdio.h>
#include <string.h>

#define BUFFSIZE 81
#define MAX_WORD_SIZE 30

int main() {
    FILE *file;
    char buffer[BUFFSIZE];
    char bigWord[MAX_WORD_SIZE];

    file = fopen("in.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fgets(buffer, BUFFSIZE, file) != NULL) {
        char currWord[MAX_WORD_SIZE];
        char *token;
        int bigSize = 0;

        token = strtok(buffer, " \t\n");
        while (token != NULL) {
            strcpy(currWord, token);
            int currSize = strlen(currWord);
            if (currSize > bigSize) {
                strcpy(bigWord, currWord);
                bigSize = currSize;
            }
            token = strtok(NULL, " \t\n");
        }

        if (bigSize > 0) { // Check to avoid printing empty lines
            printf("Biggest word in line: %s\n", bigWord);
        }
    }

    fclose(file);

    return 0;
}

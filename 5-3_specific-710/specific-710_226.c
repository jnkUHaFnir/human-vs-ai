#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFSIZE 256
#define MAX_WORD_LENGTH 30

int main() {
    FILE *file;
    char buffer[BUFFSIZE];
    char bigWord[MAX_WORD_LENGTH];
    char currWord[MAX_WORD_LENGTH];
    char *token;
    int lineNum = 0;
    int bigSize = 0;

    file = fopen("in.txt", "r");
    
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fgets(buffer, BUFFSIZE, file) != NULL) {
        lineNum++;
        bigSize = 0;
        token = strtok(buffer, " \n\t");
        
        while (token != NULL) {
            strcpy(currWord, token);
            int currSize = strlen(currWord);
            
            if (currSize > bigSize) {
                strcpy(bigWord, currWord);
                bigSize = currSize;
            }
            token = strtok(NULL, " \n\t");
        }
        printf("Line %d's biggest word: %s\n", lineNum, bigWord);
    }

    fclose(file);

    return 0;
}

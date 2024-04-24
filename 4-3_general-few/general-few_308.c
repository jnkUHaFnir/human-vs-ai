#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp = fopen("file.txt", "r");
    if (fp == NULL){
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    char string[100];
    char found[100];
    const char fetch[11] = "learning";

    while(fgets(string, 100, fp) != NULL) {
        strcpy(found, string);
        char *result = strstr(found, fetch);
        if(result != NULL) {
            printf("Found word: %s\n", fetch);
            printf("Remaining part of the sentence: %s\n", result + strlen(fetch));
        }
    }
    
    fclose(fp);
    return 0;
}

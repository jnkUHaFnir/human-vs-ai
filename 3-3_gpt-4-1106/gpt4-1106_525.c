#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trim(char *str) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    if(*str == 0)  // All spaces?
        return;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Write new null terminator character
    *(end+1) = 0;
}

int main() {
    char *scanWord[10] = { /* your words here */ };
    char *currentWord[10] = { /* your words here */ };
    int scoreCurrent = 0;
    int countX = 0;

    while(countX < 10){
        trim(scanWord[countX]);
        trim(currentWord[countX]);
        if(strcmp(scanWord[countX], currentWord[countX]) == 0)
            {scoreCurrent += 2;}
        countX++;
    }

    printf("Score: %d\n", scoreCurrent);

    return 0;
}
printf("Comparing \"%s\" with \"%s\"\n", scanWord[countX], currentWord[countX]);

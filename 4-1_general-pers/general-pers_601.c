#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *input(void) {
    int n = 1;
    char *str = malloc(sizeof(char));
    *str = '\0';
    char *temp = str; // Store the original pointer
    
    while ((*temp = getchar()) != '\n') {
        n++;
        str = realloc(str, sizeof(char) * n);
        temp = str + n - 1; // Update temp to point to the new end of the string
    }
    
    return str;
}

int main(int argc, char const *argv[]) {
    char *str = input();
    printf("%s", str);
    free(str);
    return 0;
}

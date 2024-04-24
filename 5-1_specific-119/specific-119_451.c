#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char global[100]; // Assuming a maximum sentence length of 100 characters

int main () {
    printf("Please Enter Text: \n");
    fgets(global, sizeof(global), stdin); // Using fgets to read a complete sentence

    // Remove newline character if present
    size_t len = strlen(global);
    if (len > 0 && global[len-1] == '\n') {
        global[len-1] = '\0';
    }

    printf("%s\n", global);

    return 0;
}

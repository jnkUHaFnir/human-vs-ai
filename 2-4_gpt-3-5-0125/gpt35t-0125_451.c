#include <stdio.h>
#include <string.h>

char global[100]; // Define global as a character array

int main () {

    printf("Please Enter Text: \n");
    fgets(global, sizeof(global), stdin); // Read the entire line including whitespace

    printf("%s", global); // Print out the entire sentence

    return 0;
}

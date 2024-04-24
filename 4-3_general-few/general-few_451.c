#include <stdio.h>
#include <string.h>

char global[100]; // Define a global array to store the sentence

int main() {
    printf("Please Enter Text: \n");
    fgets(global, sizeof(global), stdin); // Use fgets to read a full sentence

    printf("%s", global); // Print the full sentence stored in global

    return 0;
}

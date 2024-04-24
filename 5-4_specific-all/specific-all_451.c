#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char global[100]; // Assuming a maximum of 100 characters for the sentence

int main() {

    printf("Please Enter Text: \n");
    fgets(global, sizeof(global), stdin);

    printf("%s", global);

    return 0;
}

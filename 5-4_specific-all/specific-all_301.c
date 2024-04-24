#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom object in C
typedef struct {
    char data[50]; // assuming 50 is the maximum length of object's data
} SolObject;

int main() {
    // Simulating a list of objects
    SolObject objects[3];
    strcpy(objects[0].data, "Object1 ");
    strcpy(objects[1].data, "Object2 ");
    strcpy(objects[2].data, "Object3 ");

    char* result = (char*)malloc(1); // Allocate initial memory for an empty string
    result[0] = '\0'; // Null-terminate the string

    // Build string out of variable-length data
    for (int i = 0; i < 3; i++) {
        strcat(result, objects[i].data);
    }

    // Some parts are conditional
    if (freezeCount < 0) {
        strcat(result, "]");
    } else {
        strcat(result, ")");
    }

    // Print the final result
    printf("%s\n", result);

    // Don't forget to free the dynamically allocated memory
    free(result);

    return 0;
}

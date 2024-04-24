#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenateStrings(int freezeCount) {
    char* result = malloc(sizeof(char));
    result[0] = '\0';

    // .. build string out of variable-length data
    // Assuming 'this' is an array of SolObject objects
    SolObject* objects = ...; // your array initialization

    for (int i = 0; i < size_of_this; i++) {
        char* objectString = toString(objects[i]);
        result = realloc(result, strlen(result) + strlen(objectString) + 1);
        strcat(result, objectString);
        free(objectString);
    }

    // .. some parts are conditional
    char appendString[2];
    if (freezeCount < 0)
        sprintf(appendString, "]");
    else
        sprintf(appendString, ")");

    result = realloc(result, strlen(result) + strlen(appendString) + 1);
    strcat(result, appendString);

    return result;
}

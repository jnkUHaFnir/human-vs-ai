#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ConvertToString(char** subject, const char* insert) {
    char* temp = (char*)malloc(strlen(*subject) + strlen(insert) + 1);
    strcpy(temp, *subject);
    strcat(temp, insert);
    free(*subject); // Free the previous memory
    *subject = temp;
}

int main() {
    int frontVib = GetWord(&FrontVIB, 0);
    int rearVib = GetWord(&RearVIB, 0);

    char* rvString = (char*)malloc(10); // Allocate memory for dynamic strings
    char* fvString = (char*)malloc(10);

    // Initialize strings
    strcpy(rvString, "*RV");
    strcpy(fvString, "*FV");

    char dataStr[4];
    snprintf(dataStr, 4, "%03d", 200); // Convert integer to string

    // Append the word to the strings
    ConvertToString(&rvString, dataStr);
    ConvertToString(&fvString, dataStr);

    // Append "#" to the strings
    ConvertToString(&rvString, "#");
    ConvertToString(&fvString, "#");

    // Display the constructed strings
    printf("%s\n", rvString);
    printf("%s\n", fvString);

    // Free dynamically allocated memory
    free(rvString);
    free(fvString);

    return 0;
}

void ConvertToString(char** subject, const char* insert) {
    char* temp = (char*)malloc(strlen(*subject) + strlen(insert) + 1);
    strcpy(temp, *subject);
    strcat(temp, insert);
    free(*subject); // Free the previous memory
    *subject = temp;
}

unsigned short GetWord(unsigned short* address, int offset) {
    return *(address + offset);
}

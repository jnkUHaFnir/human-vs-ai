#include <stdio.h>
#include <string.h>

int main() {
    const char* var = "VariableContent";
    const char* foo = "FooContent";
    const char* bar = "BarContent";
    char message[256]; // Ensure this array is large enough to hold the result
    char message2[256];
    
    // Building the first message
    strcpy(message, "TEXT ");   // Copy the initial part of the message
    strcat(message, var);       // Concatenate the variable part

    // Check the first message
    printf("message: %s\n", message);

    // Building the second message
    strcpy(message2, "TEXT ");  // Copy the initial part of the message
    strcat(message2, foo);      // Concatenate the foo part
    strcat(message2, " TEXT "); // Concatenate additional text
    strcat(message2, bar);      // Concatenate the bar part

    // Check the second message
    printf("message2: %s\n", message2);

    return 0;
}

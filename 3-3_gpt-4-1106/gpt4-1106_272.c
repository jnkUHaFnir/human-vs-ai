#include <stdio.h>
#include <string.h>  // Include string.h for strcmp

int main() {
    int b = 10; // or whatever number of times you want to loop
    char names[50][32];  // array of 50 names, each can be up to 31 chars + null terminator
    char states[50][3];  // array of 50 states, each can be 2 chars + null terminator
    
    // Example input loop - you will replace this with actual user input
    strcpy(names[0], "John Doe");
    strcpy(states[0], "tx");
    strcpy(names[1], "Jane Smith");
    strcpy(states[1], "ca");
    // Fill in other names and states as necessary
    
    for (int i = 0; i < b; i++) {
        if (strcmp(states[i], "tx") == 0) {  // Compare using strcmp
            printf("Name: %s\n", names[i]);  // Print the name if the state is "tx"
        }
    }

    return 0;
}

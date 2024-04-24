#include <stdio.h>
#include <string.h>
#include <assert.h>

int main() {
    char buf1[16] = {0};
    char buf2[16] = {0};

    // Attempt to print the entire string into buf1
    int n = snprintf(buf1, sizeof(buf1), "Lorem ipsum %d dolor sit", 123456);
    assert(strcmp(buf1, "Lorem ipsum 123") == 0);  // Ensure the initial condition is true

    // Check if the entire string fit into the buffer
    if (n >= sizeof(buf1)) {
        // Calculate the remaining characters to print, including the null terminator
        int remaining = n + 1 - sizeof(buf1);  // +1 for the null terminator adjustment
        
        // If your formatted string or calculation of 'n' changes, ensure n - (sizeof(buf1)-1) doesn't go below zero
        int offset = n - remaining;  // Calculate how many characters were actually written, excluding null terminator

        // Attempt to print the remainder into buf2
        snprintf(buf2, sizeof(buf2), "%s", &"Lorem ipsum 123456 dolor sit"[offset]);
    }

    assert(strcmp(buf2, "456 dolor sit") == 0);  // Verify the expected result

    return 0;
}

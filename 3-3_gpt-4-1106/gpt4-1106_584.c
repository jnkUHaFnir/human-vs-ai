#include <stdio.h>
#include <string.h>
#include <assert.h>

int main() {
    char buf1[16] = {0};
    char buf2[16] = {0};
    
    // Attempt to print the string to the first buffer.
    int n = snprintf(buf1, sizeof buf1, "Lorem ipsum %d dolor sit", 123456);
    assert(strcmp(buf1, "Lorem ipsum 123") == 0);  // ok
    
    // Check if the entire content was written. If not, continue in buf2.
    if (n >= sizeof buf1) {
        // Calculate the number of characters that were not copied.
        int chars_not_copied = n - (sizeof buf1 - 1);  // Minus null terminator

        // Start printing from where snprintf left off by passing an offset
        // into the string to the format specifier.
        // Be mindful of the precision specifier to avoid buffer overflow.
        snprintf(buf2, sizeof buf2, "%.*s", chars_not_copied, "Lorem ipsum 123456 dolor sit" + (n - chars_not_copied));
    }

    assert(strcmp(buf2, "456 dolor sit") == 0);  // expected result
    
    return 0;
}

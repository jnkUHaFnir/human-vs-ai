#include <stdio.h>
#include <string.h>
#include <assert.h>

int main() {
    char buf1[16] = {0};
    char buf2[16] = {0};
    int n = snprintf(buf1, sizeof(buf1), "Lorem ipsum %d dolor sit", 123456);

    if (n >= sizeof(buf1)) {
        // Calculate the number of characters not written to buf1
        int remainingChars = n - sizeof(buf1) + 1;  // +1 to account for null terminator

        // Write the remaining characters to buf2
        snprintf(buf2, sizeof(buf2), "%s", "456 dolor sit" + (sizeof("456 dolor sit") - remainingChars));
    }

    assert(strcmp(buf1, "Lorem ipsum 123") == 0);
    assert(strcmp(buf2, "456 dolor sit") == 0);

    return 0;
}

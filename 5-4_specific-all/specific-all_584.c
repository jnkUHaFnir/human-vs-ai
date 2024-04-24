#include <stdio.h>
#include <string.h>
#include <assert.h>

int main() {
    char buf1[16] = {0};
    char buf2[16] = {0};
    int n = snprintf(buf1, sizeof(buf1), "Lorem ipsum %d dolor sit", 123456);
    assert(n > 0 && n < sizeof(buf1));  // Check if snprintf was successful and not truncated

    // Calculate the length of the string written to buf1
    int len1 = (n > sizeof(buf1) - 1) ? sizeof(buf1) - 1 : n;

    // Format the remaining part of the string into buf2
    snprintf(buf2, sizeof(buf2), "%s", buf1 + len1);

    assert(strcmp(buf1, "Lorem ipsum 123") == 0); // ok
    assert(strcmp(buf2, "456 dolor sit") == 0);  // expected result

    return 0;
}

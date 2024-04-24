#include <stdio.h>
#include <string.h>

char buf1[16] = {0};
char buf2[16] = {0};
int n = snprintf(buf1, sizeof(buf1), "Lorem ipsum %d dolor sit", 123456);

assert(strcmp(buf1, "Lorem ipsum 123") == 0);  // ok

// Continuing printing to buf2 if snprintf didn't have enough space in buf1
if (n >= sizeof(buf1)) {
    n -= sizeof(buf1) - 1;  // Adjusting for the characters already written
    snprintf(buf2, sizeof(buf2), "%s", "456 dolor sit" + sizeof("456") - n);
}

assert(strcmp(buf2, "456 dolor sit") == 0);  // expected result

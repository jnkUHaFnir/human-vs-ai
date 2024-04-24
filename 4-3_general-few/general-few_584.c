#include <stdio.h>
#include <string.h>

char buf1[16] = {0};
char buf2[16] = {0};
int n = snprintf(buf1, sizeof buf1, "Lorem ipsum %d dolor sit", 123456);
assert(strcmp(buf1, "Lorem ipsum 123") == 0);  // ok

// Calculate remaining characters and print to the second buffer
int remaining = snprintf(NULL, 0, "%d dolor sit", 123456) + 1; // +1 to consider the null terminator
snprintf(buf2, sizeof buf2, "%*.*s", remaining, remaining, "123456 dolor sit");

assert(strcmp(buf2, "456 dolor sit") == 0);  // expected result

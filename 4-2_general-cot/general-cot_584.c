#include <stdio.h>
#include <string.h>

char buf1[16] = {0};
char buf2[16] = {0};
int n = snprintf(buf1, sizeof buf1, "Lorem ipsum %d dolor sit", 123456);

if (n >= sizeof(buf1)) {
    snprintf(buf2, sizeof(buf2), "%s", buf1 + sizeof(buf1) - 1);
}

assert(strcmp(buf1, "Lorem ipsum 123") == 0);  // ok
assert(strcmp(buf2, "456 dolor sit") == 0);  // expected result

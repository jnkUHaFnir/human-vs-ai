char buf1[16] = {0};
char buf2[16] = {0};
int n = snprintf(buf1, sizeof buf1, "Lorem ipsum %d dolor sit", 123456);
assert(strcmp(buf1, "Lorem ipsum 123") == 0);  // ok

if (n >= sizeof(buf1)) {
    n -= sizeof(buf1) - 1;  // adjust the count for characters written to buf1
    snprintf(buf2, sizeof buf2, "%.*s", n, "Lorem ipsum 123456" + sizeof(buf1) - 1);
}

assert(strcmp(buf2, "456 dolor sit") == 0);  // expected result

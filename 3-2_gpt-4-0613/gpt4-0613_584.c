int n = snprintf(buf1, sizeof buf1, "Lorem ipsum %d dolor sit", 123456);
assert(strcmp(buf1, "Lorem ipsum 123") == 0);  // ok

char fmt[] = "Lorem ipsum %d dolor sit";
int len = strlen(fmt); 
if(n > len) {
    n = len; // to prevent negative number for snprintf 
}
snprintf(buf2, sizeof buf2, fmt+n, 123456);
assert(strcmp(buf2, "456 dolor sit") == 0);  // expected result

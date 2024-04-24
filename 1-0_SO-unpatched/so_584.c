    char buf1[16] = {0};
    char buf2[16] = {0};
    int n = snprintf(buf1, sizeof(buf1), "Lorem ipsum %d dolor sit", 123456);
    
    if (n > 15) {
        char* t = malloc(n+1);
        if (t) {
            n = snprintf(t, n, "Lorem ipsum %d dolor sit", 123456);
            strncpy(buf2, t+sizeof(buf1)-1, sizeof(buf2));
            free(t);
        }
        //might fail the subsequent assert if malloc failed
    }
    
    assert(strcmp(buf1, "Lorem ipsum 123") == 0);  // ok
    assert(strcmp(buf2, "456 dolor sit") == 0);  // expected result
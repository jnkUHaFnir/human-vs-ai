int remaining = n - strlen(buf1);  // Calculate remaining characters to print
if (remaining > 0) {
    snprintf(buf2, sizeof(buf2), "%.*s", remaining, "Lorem ipsum 123456" + strlen("Lorem ipsum 123"));
}

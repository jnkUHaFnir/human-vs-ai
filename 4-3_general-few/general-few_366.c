void pass_check(char *str) {
    const char *fref = "www";

    char *start = strstr(str, fref); // Find the "www" substring
    if (start != NULL) {
        char *end = strstr(start, ".edu"); // Find the ".edu" substring after "www"
        if (end != NULL) {
            printf("Output: %.*s\n\n", (int)(end - start) + 4, start);
        } else {
            printf("Web address starting with www. and ending with .edu not found\n");
        }
    } else {
        printf("Web address starting with www. not found\n");
    }
}

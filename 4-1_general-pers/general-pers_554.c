if (fgets(sentence, 11, stdin) != NULL) {
    char *p = strchr(sentence, '\n');
    if (p != NULL) {
        *p = '\0';
    }
}
if (fgets(sentence, 11, stdin) != NULL) {
    char *token = strtok(sentence, "\n");
}
if (fgets(sentence, 11, stdin) != NULL) {
    size_t pos = strcspn(sentence, "\n");
    sentence[pos] = '\0';
}

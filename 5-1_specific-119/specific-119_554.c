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
    sentence[strcspn(sentence, "\n")] = '\0';
}

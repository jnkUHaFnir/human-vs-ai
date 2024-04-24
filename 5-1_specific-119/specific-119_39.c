if (fgets(sentence, 11, stdin) != NULL) {
    p = strchr(sentence, '\n');
    if (p) *p = '\0';
}
if (fgets(sentence, 11, stdin) != NULL)
    token = strtok(sentence, "\n");
if (fgets(sentence, 11, stdin) != NULL)
    sentence[strcspn(sentence, "\n")] = '\0';

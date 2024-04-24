char *p = strchr(sentence, '\n');
if (p != NULL) {
    *p = '\0';
}
char *token = strtok(sentence, "\n");
sentence[strcspn(sentence, "\n")] = '\0';

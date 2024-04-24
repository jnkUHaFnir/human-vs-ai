for (size_t i = 0; i < strlen(cAFirst); i++) {
fgets(cAFirst, 25, stdin);
cAFirst[strcspn(cAFirst, "\n")] = '\0'; // remove newline character
char *token = strtok(cAFirst, " ");
while (token != NULL) {
    for (size_t i = 0; i < strlen(token); i++) {
        // count uppercase and lowercase letters
    }
    token = strtok(NULL, " ");
}
printf("Uppercase Letters=%i \nLowercase Letters=%i \n", uc, lc);

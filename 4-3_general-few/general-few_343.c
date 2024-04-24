do {
    if (scanf("%s", name) == 1) {
        int i;
        int isValid = 1;
        for (i = 0; name[i] != '\0'; i++) {
            if (!isalpha(name[i])) {
                isValid = 0;
                break;
            }
        }
        if (isValid) {
            break;
        } else {
            printf("Invalid character. Please enter a valid name.\n");
        }
    } else {
        printf("Invalid input. Please enter a valid name.\n");
        // clear the input buffer
        scanf("%*[^\n]");
        scanf("%*c");
    }
} while (1);
int i;
for (i = 0; name[i] != '\0'; i++) {
    if (name[i] == ' ') {
        if (isalpha(name[i + 1])) {
            name[i + 1] = toupper(name[i + 1]);
        }
    } else {
        name[i] = tolower(name[i]);
    }
}
name[0] = toupper(name[0]);

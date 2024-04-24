do {
    if (scanf("%s", name) == 1) {
        int valid = 1;
        for (int i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i])) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            break;
        } else {
            printf("Please enter a valid name.\n");
        }
    } else {
        printf("Please enter a valid name.\n");
    }
} while (1);
do {
    scanf("%s", name);
    int valid = 1;
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            valid = 0;
            break;
        }
    }
    if (valid) {
        break;
    } else {
        printf("Invalid character. Please enter a valid name.\n");
    }
} while (1);
name[0] = toupper(name[0]);
for (int i = 1; i < strlen(name); i++) {
    name[i] = tolower(name[i]);
    if (name[i - 1] == ' ') {
        name[i] = toupper(name[i]);
    }
}

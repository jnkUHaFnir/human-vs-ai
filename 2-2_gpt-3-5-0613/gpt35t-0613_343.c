do {
    if (scanf("%s", name) == 1) {
        int valid = 1;
        for (int i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i])) {
                valid = 0;
                break;
            }
        }
        if (valid)
            break;
    }
    printf("Please enter a valid name.\n");
} while (1);
// Convert all letters to lowercase except the first one
for (int i = 1; i < strlen(name); i++) {
    name[i] = tolower(name[i]);
}

// Make the first letter uppercase
name[0] = toupper(name[0]);

// Capitalize the first letter of each word (if preceded by a space)
for (int i = 1; i < strlen(name); i++) {
    if (name[i - 1] == ' ') {
        name[i] = toupper(name[i]);
    }
}

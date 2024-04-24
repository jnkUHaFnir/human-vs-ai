do {
    if (fgets(name, sizeof(name), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        exit(1);
    }
    name[strcspn(name, "\n")] = '\0'; // Remove the newline character
} while (!is_valid_name(name));
int is_valid_name(const char* name) {
    for (size_t i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            return 0; // Character is not alphabetic
        }
    }
    return 1; // All characters are alphabetic
}
// Convert all letters to lowercase except the first letter
for (size_t i = 0; i < strlen(name); i++) {
    name[i] = tolower(name[i]);
}

// Capitalize the first letter
name[0] = toupper(name[0]);

// Capitalize the first letter after a space
for (size_t x = 1; name[x] != '\0'; x++) {
    if (name[x - 1] == ' ') {
        name[x] = toupper(name[x]);
    }
}

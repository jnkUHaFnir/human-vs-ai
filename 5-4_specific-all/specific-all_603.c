#define MAX_LENGTH 100 

char name[MAX_LENGTH];
int check;

do {
    check = 0;
    if (scanf("%99s", name) != 1) {
        printf("Please enter a valid name.\n");
        while (getchar() != '\n');
        continue;
    }

    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            printf("Invalid character. Please enter a valid name.\n");
            check = 1;
            break;
        }
    }
} while (check == 1);

// Convert to lowercase
for (int i = 0; name[i]; i++) {
    name[i] = tolower(name[i]);
}

// Capitalize first letter
name[0] = toupper(name[0]);
for (int i = 1; name[i]; i++) {
    if (name[i - 1] == ' ') {
        name[i] = toupper(name[i]);
    }
}

printf("Processed Name: %s\n", name);

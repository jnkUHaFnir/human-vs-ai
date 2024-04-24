struct Person {
    char name[50];
};
int compare_strings(char a[], char b[]) {
    int i = 0;

    while (a[i] == b[i]) {
        if (a[i] == '\0' || b[i] == '\0') break;
        i++;
    }

    if (a[i] == '\0' && b[i] == '\0') return 0;
    else return -1;
}
int main() {
    struct Person person;

    // Assign the name of the person (you can also use strcpy)
    strcpy(person.name, "Steve xyz");

    // Get user input
    char inputName[50];
    printf("Enter the name: ");
    fgets(inputName, sizeof(inputName), stdin);
    // Remove newline character
    inputName[strcspn(inputName, "\n")] = '\0';
    if (compare_strings(person.name, inputName) == 0) {
        printf("Names match!\n");
    } else {
        printf("Name mismatch!\n");
    }

    return 0;
}

char temp;
scanf(" %c", &temp); // note the space before %c to consume any leading whitespace, including newline

// Clear input buffer to handle the newline character left by scanf
int c;
while ((c = getchar()) != '\n' && c != EOF) {}

fgets(variable1, 50, stdin);
strtok(variable1, "\n");

printf("%s ", variable1);

if (1) {
    scanf(" %c", &temp); // note the space before %c to consume any leading whitespace, including newline

    // Clear input buffer to handle the newline character left by scanf
    while ((c = getchar()) != '\n' && c != EOF) {}

    fgets(variable2, 50, stdin);
    strtok(variable2, "\n");

    printf("%s ", variable2);
}

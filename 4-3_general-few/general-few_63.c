char temp;
scanf(" %c", &temp);  // Notice the leading space in the format string to consume whitespace

fgets(variable1, 50, stdin);
strtok(variable1, "\n");

printf("%s ", variable1);

if (1) {
    scanf(" %c", &temp);  // Consume the newline character left in the input stream
    fgets(variable2, 50, stdin);
    strtok(variable2, "\n");

    printf("%s ", variable2);
}

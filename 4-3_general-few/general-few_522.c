char temp;
scanf(" %c", &temp); // Add a space before %c to consume newline
fgets(variable1, 50, stdin);
strtok(variable1, "\n");

printf("%s ", variable1);

if (1) {
    scanf(" %c", &temp); // Add a space before %c to consume newline
    fgets(variable2, 50, stdin);
    strtok(variable2, "\n");

    printf("%s ", variable2);
}

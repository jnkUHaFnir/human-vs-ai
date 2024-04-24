char temp;
scanf(" %c", &temp); // Notice the space before %c to consume the newline character

fgets(variable1, 50, stdin);
strtok(variable1, "\n");

printf("%s ", variable1);

if (1) {
    // Clearing the input buffer before reading a new character
    while ((getchar()) != '\n');
    
    scanf(" %c", &temp); // Notice the space before %c to consume the newline character

    fgets(variable2, 50, stdin);
    strtok(variable2, "\n");

    printf("%s ", variable2);
}

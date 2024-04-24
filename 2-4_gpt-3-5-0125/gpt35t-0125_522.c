char temp;
scanf("%c",&temp);
getchar(); // consume the newline character

fgets(variable1,50,stdin);
strtok(variable1, "\n");

printf("%s ", variable1);

if (1) {
    scanf("%c",&temp);
    getchar(); // consume the newline character
    fgets(variable2,50,stdin);
    strtok(variable2, "\n");

    printf("%s ", variable2);
}

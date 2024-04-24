do {
    int valid = 1;
    scanf("%s", name); // Use 'name' instead of '&name'

    for (i = 0; i < strlen(name); i++) {
        if (isalpha(name[i]) == 0) {
            printf("Invalid character. Please enter a valid name.\n");
            valid = 0;
            break;
        }
    }
} while (valid == 0);
//all to lower except the first letter
for (i = 1; i < strlen(name); i++) {
    name[i] = tolower(name[i]);
}

//first letter to upper
name[0] = toupper(name[0]); // Use 'name[0]' instead of 'name[i]'
x = 1;
while (name[x] != '\0'){
    // if the letter before is a whitespace, even the first letter, it should place the first letter of a name upper
    if (name[x - 1] == ' ')
        name[x] = toupper(name[x]);
    x++;
}

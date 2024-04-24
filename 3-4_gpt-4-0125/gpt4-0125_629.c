char name[100];  // Example size, adjust as needed
int check;
do{
    printf("Please enter a name: ");
    scanf("%99s", name);  // Reading up to 99 characters to leave room for the terminating null character
    check = 0;
    for(int i = 0; name[i] != '\0'; i++){  // Iterating over each character until the null terminator
        if(!isalpha((unsigned char)name[i])){  // Casting to unsigned char in case isalpha doesn't like plain chars on some platforms
            printf("Invalid character. Please enter a valid name.\n");
            check = 1;
            break;
        }
    }
}while(check == 1);
// Ensure the first character is uppercase if it's alphabetic
if(isalpha((unsigned char)name[0])) {
    name[0] = toupper((unsigned char)name[0]);
}

// Process the rest of the characters
for(int i = 1; name[i] != '\0'; i++){
    if(isalpha((unsigned char)name[i])){
       if(name[i-1] == ' ') {
           name[i] = toupper((unsigned char)name[i]);
       } else {
           name[i] = tolower((unsigned char)name[i]);
       }
    }
}

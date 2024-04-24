char* flip_string(char *string){
    int i = strlen(string) - 1;
    int j = 0;

    char* temp = malloc(strlen(string) + 1); // Allocate memory for the reversed string
    strcpy(temp, string); // Copy original string to temp

    for(; i>=0; i--){
        temp[j] = string[i];
        j++;
    }
    temp[j] = '\0'; // Add null terminator to end of the reversed string

    return temp;
}

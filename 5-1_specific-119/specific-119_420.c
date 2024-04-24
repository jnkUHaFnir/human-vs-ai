char* flip_string(char *string){
    int i = strlen(string) - 1; // Start from the end of the string
    int j = 0;

    char* temp = malloc(strlen(string) + 1); // Allocate memory for temp (+1 for the null terminator)
    temp[strlen(string)] = '\0'; // Add null terminator at the end

    for(i; i >= 0; i--){
        temp[j] = string[i];
        j++;
    }

    return temp;
}
int main(int argc, char *argv[]){
    char* reversed = flip_string(argv[1]);
    puts(reversed);
    free(reversed); // Free allocated memory
    printf("This is the end of the program\n");
    return 0;
}

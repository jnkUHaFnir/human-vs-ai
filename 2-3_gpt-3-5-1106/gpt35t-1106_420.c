char* flip_string(char *string){
    int length = strlen(string);
    char* temp = (char*)malloc((length + 1) * sizeof(char)); // +1 for the null terminator

    for(int i = 0; i < length; i++){
        temp[i] = string[length - i - 1];
    }
    temp[length] = '\0'; // adding null terminator

    return temp;
}
int main(int argc, char *argv[]){
    char* reversed = flip_string(argv[1]);
    puts("Reversed string:");
    puts(reversed);
    free(reversed); // don't forget to free the allocated memory
    printf("This is the end of the program\n");
    return 0;
}

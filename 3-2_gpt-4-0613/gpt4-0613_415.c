void removeLastThree(char* input, char* output) {
    unsigned int x;
    for (x = 0; x < (strlen(input) - 3); x++){
        output[x] = input[x];
    }
    output[x] = '\0'; // don't forget to end string
}
int main(void){
    char* input = "filename.jpg";
    char output[strlen(input)]; // make sure the output array is big enough
    removeLastThree(input, output);
    printf("%s\n", output);
    return 0;
}
char* removeLastThree(char* input) {
    unsigned int x;
    char* output = (char*)malloc(strlen(input) - 2); // allocate space
    for (x = 0; x < (strlen(input) - 3); x++){
        output[x] = input[x];
    }
    output[x] = '\0'; // don't forget to end string
    return output;
}

int main() {
    char* filename = "filename.jpg";
    char* newFilename = removeLastThree(filename);
    printf("%s\n", newFilename);
    free(newFilename); // free the memory of newFilename when done
    return 0;
}

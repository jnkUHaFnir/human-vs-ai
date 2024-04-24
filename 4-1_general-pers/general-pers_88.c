char source[1000000] = {0}; // Initialize buffer with null bytes

FILE *fp = fopen("TheFile.txt", "r");
if (fp != NULL) {
    char buffer[1024]; // Temporary buffer to read file contents

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        strncat(source, buffer, sizeof(source) - strlen(source) - 1); // Concatenate at most sizeof(source) - strlen(source) - 1 characters
    }

    fclose(fp);
}
for (int x = 0; x < sizeof(source) && source[x] != '\0'; x++) {
    // Process chars
}

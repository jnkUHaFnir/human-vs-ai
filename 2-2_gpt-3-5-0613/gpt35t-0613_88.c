char source[1000000] = {0}; // Initialize the buffer to avoid undefined behavior

FILE *fp = fopen("TheFile.txt", "r");
if (fp != NULL) {
    char line[100]; // Temporary buffer to read each line from the file

    while (fgets(line, sizeof(line), fp) != NULL) {
        strcat(source, line); // Append each line to the source buffer
    }

    fclose(fp);
}
for (int x = 0; source[x] != '\0'; x++) {
    char c = source[x];
    // Process each character
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Presuming 'in' is your file pointer and has already been opened for reading.
    FILE *in = fopen("yourfile.txt", "r");
    if (in == NULL) {
        perror("Failed to open file");
        return 1;
    }

    // Step 1: Count lines in the file
    int count = 0;
    char c;
    while ((c = getc(in)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }
    if (c != '\n') { // Handle the case where the file does not end with a newline but has data
        count++;
    }

    // Step 2: Reset the file pointer
    fseek(in, 0, SEEK_SET);

    // Step 3: Dynamically allocate memory for the array of pointers
    char **lines = (char **)malloc(count * sizeof(char *));
    if (lines == NULL) {
        perror("Failed to allocate memory for line pointers");
        fclose(in);
        return 1;
    }

    char line[50]; // Assuming no line exceeds 49 characters + '\0'
    int i = 0;
    while (fgets(line, sizeof(line), in) != NULL && i < count) {
        lines[i] = strdup(line);
        if (lines[i] == NULL) {
            perror("Failed to duplicate line");
            // A more robust implementation would free any already allocated lines here
            fclose(in);
            return 1;
        }
        i++;
    }

    // Now you can access your lines:
    for (int j = 0; j < count; j++) {
        printf("%s", lines[j]); // Do something to each line
        free(lines[j]); // Remember to free each strdup'ed line when done
    }
    free(lines); // Finally, free the array of pointers itself

    fclose(in); // Don't forget to close your file
    return 0;
}

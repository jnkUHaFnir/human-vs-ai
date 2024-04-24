#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        char* line_without_digits = (char*) calloc(len, sizeof(char));
        int j = 0;

        for(int i = 0; i < read; i++) {
            // Here we're just copying non-digits and spaces to the new line
            if(isdigit(line[i])==0 || isspace(line[i])!=0) {
                line_without_digits[j] = line[i];
                j++;
            }
        }

        printf("%s", line_without_digits); // Printing the line without digits

        free(line_without_digits);
    }

    free(line);
    fclose(file);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_line(FILE* fin) {
    // Implementation of read_line() assumed here
    // Return a dynamically allocated string or NULL if no more lines
}

int main() {
    FILE* fin = fopen("file1.txt", "r");
    char* url = NULL;
    
    if (fin) 
    {
        char* line;
        while ((line = read_line(fin)) != NULL) 
        {
            if (strstr(line, "url=") != NULL) 
            {
                url = strdup(line); // Duplicate the line and assign it to url
                fprintf(stdout, "%s\n", url);
            }
            free(line); // Free the original line
        }
    }

    printf("line is: %s\n", url);

    // Make sure to free the memory allocated by strdup
    free(url);

    fclose(fin);

    return 0;
}

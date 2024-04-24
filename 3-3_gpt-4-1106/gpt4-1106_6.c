#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Make sure you have a function called read_line implemented that reads lines from the file
// and returns a dynamically allocated string that must be freed after use.

int main() {
    FILE *fin = fopen("file1.txt", "r");
    char *line;
    char *url = NULL;

    if (fin) {
        while ((line = read_line(fin))) {
            char *found_url = strstr(line, "url=");
            if (found_url != NULL) {
                fprintf(stdout, "%s\n", found_url);

                // Free the previous url
                free(url);

                // Make a copy of the data
                url = strdup(found_url + 4); // +4 to skip over the "url=" part if desired
            }
            free(line);
        }
    }

    if (url != NULL) {
        printf("url is:%s\n", url);
        free(url); // Free the duplicated string once we're done using it
    } else {
        printf("No URL found.\n");
    }

    fclose(fin);
    return 0;
}

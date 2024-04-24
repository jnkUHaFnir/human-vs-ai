#include <stdio.h>

int main() {
    FILE *f = fopen("textfile", "r");
    
    if (!f) {
        printf("error");
    } else {
        char line1[100]; // assuming a maximum line length of 100 characters
        char line2[100]; // assuming a maximum line length of 100 characters
        int i = 0;
        char c;
        
        // Read and store characters for the first line
        while ((c = fgetc(f)) != '\n') {
            if (c == EOF) { // handle end of file
                break;
            }
            line1[i] = c;
            i++;
        }
        line1[i] = '\0'; // terminate the string
        
        // Reset the counter and read and store characters for the second line
        i = 0;
        while ((c = fgetc(f)) != '\n') {
            if (c == EOF) { // handle end of file
                break;
            }
            line2[i] = c;
            i++;
        }
        line2[i] = '\0'; // terminate the string
        
        // Print the stored lines
        printf("line1 = \"%s\"\n", line1);
        printf("line2 = \"%s\"\n", line2);
        
        fclose(f);
    }
    
    return 0;
}

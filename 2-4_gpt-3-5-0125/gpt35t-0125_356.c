#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool output_sugar(const char *fmt, int jobid, const char *jobname, struct job *j) {
    char buffer[256]; // Assuming a buffer size of 256 for simplicity
    char *temp;
    char *p;
    
    // Copy format string to buffer for manipulation
    strcpy(buffer, fmt);
    
    // Tokenize the format string and format the output path
    p = buffer;
    while ((temp = strchr(p, '%')) != NULL) {
        // Check for valid format specifier
        switch (*(temp + 1)) {
            case 'd':
                snprintf(j->outpath, sizeof(j->outpath), buffer, jobid);
                break;
            case 's':
                snprintf(j->outpath, sizeof(j->outpath), buffer, jobname);
                break;
            case '%':
                // Do nothing, skip %%
                break;
            default:
                return false; // Invalid format specifier
        }
        p = temp + 2; // Move to next format specifier
    }
    
    return true;
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool output_sugar(const char *fmt, int jobid, const char *jobname, struct job *j) {
    char temp[255]; // Assuming a maximum path length of 255 characters
    int res;

    // Copy the format string to a temporary buffer for parsing
    strncpy(temp, fmt, sizeof(temp)-1);
    temp[sizeof(temp)-1] = '\0';

    // Check for valid placeholders in the format string
    char *ptr = temp;
    while (*ptr) {
        if (*ptr == '%') {
            char placeholder = *(ptr+1);
            if (placeholder != 'd' && placeholder != 's' && placeholder != '%') {
                return false; // Invalid placeholder found
            }
        }
        ptr++;
    }

    // Determine the correct order and values for snprintf based on placeholders
    if (strstr(temp, "%d") && strstr(temp, "%s")) {
        res = snprintf(j->outpath, sizeof(j->outpath), temp, jobid, jobname);
    } else if (strstr(temp, "%d")) {
        res = snprintf(j->outpath, sizeof(j->outpath), temp, jobid);
    } else if (strstr(temp, "%s")) {
        res = snprintf(j->outpath, sizeof(j->outpath), temp, jobname);
    } else {
        res = snprintf(j->outpath, sizeof(j->outpath), temp);
    }

    // Check if snprintf was successful and return accordingly
    if (res < 0 || res >= sizeof(j->outpath)) {
        return false; // Error in formatting the output path
    }

    return true; // Output path formatted successfully
}

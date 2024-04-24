#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool output_sugar(const char *fmt, int jobid, const char *jobname, struct job *j) {
    char tmp[256]; // Assuming a reasonable maximum length for the path
    char formatSpecifier[3]; // To store the format specifiers found
    int numArgs = 0;
    bool isValidFormat = true;

    // Read cfg->pathfmt to determine format specifiers
    for (int i = 0; i < strlen(fmt) && numArgs < 2; i++) {
        if (fmt[i] == '%' && i + 1 < strlen(fmt)) {
            if (fmt[i + 1] == 'd' || fmt[i + 1] == 's') {
                formatSpecifier[numArgs++] = fmt[i + 1];
            } else if (fmt[i + 1] == '%') {
                // Skip if it's an escaped '%' character
                i++;
            } else {
                // Invalid format specifier found
                isValidFormat = false;
                break;
            }
        }
    }

    // Verify correct number of valid format specifiers found
    if (numArgs == 0 || numArgs > 2) {
        isValidFormat = false;
    }

    if (isValidFormat) {
        if (numArgs == 1) {
            // Single argument format
            if (formatSpecifier[0] == 'd') {
                snprintf(tmp, sizeof(tmp), fmt, jobid);
            } else {
                snprintf(tmp, sizeof(tmp), fmt, jobname);
            }
        } else {
            // Two argument format
            snprintf(tmp, sizeof(tmp), fmt, jobid, jobname);
        }

        // Validate the final output path before proceeding
        if (strlen(tmp) < sizeof(j->outpath)) {
            strcpy(j->outpath, tmp);
            return true;
        }
    }

    return false;
}

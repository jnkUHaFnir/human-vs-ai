#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidFormatSpecifier(const char *fmt) {
    // Check if the format specifier is valid.
    // A valid specifier is one of %% (escaped %), %d, or %s.
    return (strcmp(fmt, "%%") == 0 || strcmp(fmt, "%d") == 0 || strcmp(fmt, "%s") == 0);
}

bool containsValidFormatSpecifiers(const char *fmt) {
    // Iterate through the format string and check if all specifiers are valid.
    while (*fmt != '\0') {
        if (*fmt == '%') {
            // We found a format specifier.
            fmt++; // Move past the '%'
            if (!isValidFormatSpecifier(fmt)) {
                // fmt now points to the character after '%', check next two chars.
                return false;
            }
            if (*fmt == '%') {
                fmt++;  // Skip the escaped '%'
            }
        }
        fmt++;
    }
    return true;
}

bool output_sugar(const char *fmt, int jobid, const char *jobname, char outpath[]) {
    if (fmt == NULL || !containsValidFormatSpecifiers(fmt)) {
        // The format string is either NULL or contains invalid format specifiers.
        return false;
    }
    
    // First, we need to count the number of specifiers.
    int num_d = 0, num_s = 0;
    const char *p = fmt;
    while (*p != '\0') {
        if (*p == '%') {
            p++; // Move past '%'.
            if (*p == 'd') {
                num_d++; // Increment count for '%d'.
            }
            if (*p == 's') {
                num_s++; // Increment count for '%s'.
            }
        }
        if (*p != '\0') {
            p++; // Move to next character.
        }
    }
    
    // Now we know how many of each specifier there are, we can format the string.
    if (num_d == 0 && num_s == 0) {
        // No format specifiers, copy the string as is.
        strcpy(outpath, fmt);
    } else if (num_d == 1 && num_s == 0) {
        snprintf(outpath, PATH_MAX, fmt, jobid);
    } else if (num_d == 0 && num_s == 1) {
        snprintf(outpath, PATH_MAX, fmt, jobname);
    } else if (num_d == 1 && num_s == 1) {
        // Here you need to detect the order in which the placeholders appear.
        if (strstr(fmt, "%d") < strstr(fmt, "%s")) {
            // %d comes before %s
            snprintf(outpath, PATH_MAX, fmt, jobid, jobname);
        } else {
            // %s comes before %d
            snprintf(outpath, PATH_MAX, fmt, jobname, jobid);
        }
    } else {
        // More than one occurrence of either '%d' or '%s' which is invalid for this scenario.
        return false;
    }
    
    return true;
}

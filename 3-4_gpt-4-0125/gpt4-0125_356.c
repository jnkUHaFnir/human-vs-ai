#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_valid_format(const char *format) {
    // Basic validation could be enhanced as needed
    while (*format) {
        if (*format == '%') {
            format++;  // Move to specifier
            // Acceptable specifiers
            if (*format != 'd' && *format != 's' && *format != '%') {
                return false;
            }
        }
        format++;
    }
    return true;
}

bool output_sugar(const char *format, int jobid, const char *jobname, char *output, size_t max_len) {
    if (!format || !output || !is_valid_format(format)) {
        return false;
    }

    int num_d = 0, num_s = 0;
    const char *p = format;
    while (*p) {
        if (*p == '%') {
            p += (*(p + 1) == 'd') ? (++num_d,2) : (*(p + 1) == 's') ? (++num_s,2) : (++p,1);
        } else {
            p++;
        }
    }

    if (num_d > 1 || num_s > 1) {
        // Handle error: Too many format specifiers
        return false;
    }

    if (num_d == 1 && num_s == 1) {
        // Detect order
        char first_specifier = strchr(format, '%')[1]; // Get the character following the first '%'
        if (first_specifier == 'd') {
            snprintf(output, max_len, format, jobid, jobname);
        } else {
            snprintf(output, max_len, format, jobname, jobid);
        }
    } else if (num_d == 1) {
        snprintf(output, max_len, format, jobid);
    } else if (num_s == 1) {
        snprintf(output, max_len, format, jobname);
    } else {
        strncpy(output, format, max_len);
        output[max_len - 1] = '\0'; // Ensuring null-termination
    }

    return true;
}

// Assume 'job' structure and related logic are defined elsewhere

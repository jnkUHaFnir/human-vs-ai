#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool output_sugar(const char *fmt, int jobid, const char *jobname, struct job *j) {
    int num_placeholders = 0;
    bool valid_format = true;

    const char *p = fmt;
    while (*p) {
        if (*p == '%') {
            if (*(p+1) == 'd') {
                num_placeholders++;
            } else if (*(p+1) == 's') {
                num_placeholders++;
            } else if (*(p+1) != '%' && *(p+1) != 0) {
                // Invalid format - % followed by something other than 's', 'd', or '%'
                valid_format = false;
                break;
            }
            p++;
        }
        p++;
    }

    if (valid_format) {
        char output_path[256]; // Adjust the size as needed
        int chars_written = 0;

        if (num_placeholders == 0) {
            chars_written = snprintf(output_path, sizeof(output_path), fmt);
        } else if (num_placeholders == 1) {
            chars_written = snprintf(output_path, sizeof(output_path), fmt, jobid);
        } else if (num_placeholders == 2) {
            chars_written = snprintf(output_path, sizeof(output_path), fmt, jobid, jobname);
        }

        if (chars_written > 0 && chars_written < sizeof(output_path)) {
            // Successfully formatted the output path
            // Copy output_path to j->outpath
            strncpy(j->outpath, output_path, sizeof(j->outpath));
            return true;
        }
    }

    // Invalid format or snprintf error
    return false;
}

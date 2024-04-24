#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool output_sugar(const char *fmt, int jobid, const char *jobname, struct job *j) {
    char tmp[256]; // Assuming a reasonable max length for the formatted path
    char *p;
  
    int num_d = 0;
    int num_s = 0;

    // Count the occurrences of %d and %s in the format string
    for (p = strchr(fmt, '%'); p != NULL; p = strchr(p+1, '%')) {
        if (*(p+1) == 'd') {
            num_d++;
        } else if (*(p+1) == 's') {
            num_s++;
        } else if (*(p+1) != '%') {
            // Invalid placeholder found
            return false;
        }
    }

    // Make sure the format string is valid
    if (num_d > 1 || num_s > 1) {
        return false;
    }

    // Format the output path accordingly based on the format string
    if (num_d == 1 && num_s == 1) {
        snprintf(tmp, sizeof(tmp), fmt, jobid, jobname);
    } else if (num_d == 1) {
        snprintf(tmp, sizeof(tmp), fmt, jobid);
    } else if (num_s == 1) {
        snprintf(tmp, sizeof(tmp), fmt, jobname);
    } else {
        snprintf(tmp, sizeof(tmp), fmt);
    }

    // Copy the formatted path to the struct job
    strncpy(j->outpath, tmp, sizeof(j->outpath));

    return true;
}

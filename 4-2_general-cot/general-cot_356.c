#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool output_sugar(const char *fmt, int jobid, const char *jobname, struct job *j) {
    int num_placeholders = 0;
    
    const char *ptr = fmt;
    while ((ptr = strchr(ptr, '%')) != NULL) {
        if (*(ptr + 1) == 'd' || *(ptr + 1) == 's') {
            num_placeholders++;
        } else if (*(ptr + 1) != '%' && *(ptr + 1) != '\0') {
            // Invalid placeholder found
            return false;
        }
        ptr++;
    }

    char format[50]; // Assuming a reasonable limit for the final format string
    switch (num_placeholders) {
        case 0:
            snprintf(j->outpath, sizeof(j->outpath), fmt);
            break;
        case 1:
            snprintf(format, sizeof(format), fmt, (num_placeholders == 1) ? jobid : jobname);
            snprintf(j->outpath, sizeof(j->outpath), format);
            break;
        case 2:
            snprintf(format, sizeof(format), fmt, jobid, jobname);
            snprintf(j->outpath, sizeof(j->outpath), format);
            break;
        default:
            // More than 2 placeholders not supported
            return false;
    }

    return true;
}

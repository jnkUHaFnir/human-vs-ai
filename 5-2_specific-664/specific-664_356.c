#include <stdbool.h>
#include <stdio.h>

bool output_sugar(const char *fmt, int jobid, const char *jobname, struct job *j) {
    int num_placeholders = 0;
    int arg_order[2] = {0};  // Maximum of 2 arguments

    // Parse the format string to determine the number and order of arguments needed
    for (const char *ptr = fmt; *ptr; ++ptr) {
        if (*ptr == '%' && (*(ptr + 1) == 'd' || *(ptr + 1) == 's')) {
            arg_order[num_placeholders++] = (*(ptr + 1) == 'd') ? jobid : jobname;
        }
    }

    // Check for any invalid placeholder
    if (num_placeholders > 2) {
        return false;
    }

    // Determine the order of arguments and pass them to snprintf()
    if (num_placeholders == 2) {
        snprintf(j->outpath, sizeof(j->outpath), fmt, arg_order[0], arg_order[1]);
    } else if (num_placeholders == 1) {
        snprintf(j->outpath,sizeof(j->outpath), fmt, arg_order[0]);
    } else {
        snprintf(j->outpath,sizeof(j->outpath), fmt);
    }

    return true;
}

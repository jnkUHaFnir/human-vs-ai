#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool output_sugar(const char *fmt, int jobid, const char *jobname, struct job *j) {
    const char* fmt_ptr = fmt;
    char buf[256]; // Adjust size as needed

    // Prepare default format string
    const char* default_fmt = "/tmp/output";

    // Define variables to hold the format arguments
    int jobid_used = 0;
    int jobname_used = 0;
    bool valid_format = true;

    // Loop through the format string
    while (*fmt_ptr) {
        if (*fmt_ptr == '%' && *(fmt_ptr + 1)) {
            if (*(fmt_ptr + 1) == 'd') {
                snprintf(buf, sizeof(buf), fmt, jobid);
                jobid_used = 1;
            } else if (*(fmt_ptr + 1) == 's') {
                snprintf(buf, sizeof(buf), fmt, jobname);
                jobname_used = 1;
            } else {
                valid_format = false;
                break;
            }
            break;
        }
        fmt_ptr++;
    }

    if (!valid_format) {
        return false;
    }

    // Check if both jobid and jobname are used
    if (jobid_used && jobname_used) {
        // Both used, format accordingly
        snprintf(j->outpath, sizeof(j->outpath), "%s", buf);
    } else if (jobid_used) {
        // Only jobid used
        snprintf(j->outpath, sizeof(j->outpath), "%s/%s", buf, jobname);
    } else if (jobname_used) {
        // Only jobname used
        snprintf(j->outpath, sizeof(j->outpath), "%s/%d", buf, jobid);
    } else {
        // Neither jobid nor jobname used, use default format
        snprintf(j->outpath, sizeof(j->outpath), "%s", default_fmt);
    }

    return true;
}

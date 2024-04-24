#include <stdio.h>

bool output_sugar(const char *fmt, int jobid, const char *jobname, struct job *j) {
    char buffer[256]; // adjust the buffer size as needed

    if (fmt contains "%d" and fmt contains "%s") {
        snprintf(buffer, sizeof(buffer), fmt, jobid, jobname);
    } else if (fmt contains "%d") {
        snprintf(buffer, sizeof(buffer), fmt, jobid);
    } else if (fmt contains "%s") {
        snprintf(buffer, sizeof(buffer), fmt, jobname);
    } else {
        snprintf(buffer, sizeof(buffer), fmt);
    }

    // do something with the formatted string in buffer
    // return true or false based on sanity checks

    return true;
}

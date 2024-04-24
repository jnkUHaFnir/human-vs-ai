bool output_sugar(const char *fmt, int jobid, const char *jobname, struct job *j) {
    // Step 2
    char outputString[MAX_OUTPUT_LENGTH];

    // Step 3
    bool hasJobId = false;
    bool hasJobName = false;

    // Step 4
    const char *jobIdPlaceholder = strstr(fmt, "%d");
    const char *jobNamePlaceholder = strstr(fmt, "%s");

    // Step 5
    if (jobIdPlaceholder != NULL) {
        hasJobId = true;
        snprintf(jobIdPlaceholder, 3, "%d", jobid);
    }

    // Step 6
    if (jobNamePlaceholder != NULL) {
        hasJobName = true;
        snprintf(jobNamePlaceholder, 3, "%s", jobname);
    }

    // Step 7
    if (strchr(fmt, '%') != NULL) {
        return false;
    }

    // Step 8
    if (hasJobId && hasJobName) {
        snprintf(outputString, MAX_OUTPUT_LENGTH, fmt, jobid, jobname);
    } else if (hasJobId) {
        snprintf(outputString, MAX_OUTPUT_LENGTH, fmt, jobid);
    } else if (hasJobName) {
        snprintf(outputString, MAX_OUTPUT_LENGTH, fmt, jobname);
    } else {
        snprintf(outputString, MAX_OUTPUT_LENGTH, fmt);
    }

    // Do something with the formatted output string (e.g., assign it to j->outpath)

    return true;
}
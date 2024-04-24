#include <stdio.h>

bool output_sugar(const char *fmt, int jobid, const char *jobname, struct job *j)
{
    char tmp_s[256];
    int tmp_d;
    
    if (sscanf(fmt, "%[^%]%%d%%s", tmp_s, tmp_s) == 2) {
        // We have two format specifiers, %d then %s
        sprintf(j->outpath, fmt, jobid, jobname);
    } else if (sscanf(fmt, "%[^%]%%s%%d", tmp_s, tmp_d) == 2) {
        // We have two format specifiers, %s then %d
        sprintf(j->outpath, fmt, jobname, jobid);
    } else if (sscanf(fmt, "%[^%]%%d", tmp_s) == 1) {
        // We have one format specifier, %d
        sprintf(j->outpath, fmt, jobid);
    } else if (sscanf(fmt, "%[^%]%%s", tmp_s) == 1) {
        // We have one format specifier, %s
        sprintf(j->outpath, fmt, jobname);
    } else {
        // We have no format specifiers or unrecognized format
        if (strchr(fmt,'%%') != NULL){
            //We have % without s or d after
            return false;
        }else{
            snprintf(j->outpath, sizeof(j->outpath), "%s", fmt);
        }
    }

    return true;
}

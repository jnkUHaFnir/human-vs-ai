#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool output_sugar(const char *fmt, int jobid, const char *jobname, struct job *j) {
    char temp[255]; // Assuming a maximum path length of 255 characters
    char *temp_ptr = temp;
    const char *ptr = fmt;
    
    while (*ptr) {
        if (*ptr == '%') {
            ptr++;
            if (*ptr == 'd') {
                temp_ptr += snprintf(temp_ptr, sizeof(temp) - (temp_ptr - temp), "%d", jobid);
            } else if (*ptr == 's') {
                temp_ptr += snprintf(temp_ptr, sizeof(temp) - (temp_ptr - temp), "%s", jobname);
            } else if (*ptr == '%') {
                *temp_ptr++ = '%';
            } else {
                // Invalid format specifier
                return false;
            }
        } else {
            *temp_ptr++ = *ptr;
        }
        
        ptr++;
    }
    
    *temp_ptr = '\0';
    
    snprintf(j->outpath, sizeof(j->outpath), "%s", temp);
    
    return true;
}

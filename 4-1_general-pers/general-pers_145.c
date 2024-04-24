#include <stdlib.h>
#include <string.h>

// Assuming maximum size of "selectedNotice=%s&" is 50 bytes including null terminator

int download_size, i, m;
m = atoi(lr_eval_string("{DownloadableRecords_FundingNotices_count}"));

// Allocate memory for the buffer
char* r_buf = (char*)malloc(m * 50 + 1); // Assuming worst-case size
if (r_buf == NULL) {
    lr_error_message("Memory allocation failed. Exiting.");
    return -1;
}
r_buf[0] = '\0'; // Initialize the buffer

for (i = 1; i <= m; i++) {
    char temp[50]; // Temporary buffer to hold "selectedNotice=%s&"
    sprintf(temp, "selectedNotice=%s&", lr_paramarr_idx("DownloadableRecords_FundingNotices", i));
    
    // Concatenate temp to r_buf
    strcat(r_buf, temp);
}

// Save the final string
lr_save_string(r_buf, "dpAllRecords");

// Free the allocated memory
free(r_buf);

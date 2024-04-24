#include <stdlib.h>
#include <string.h>

int download_size, i, m;
m = atoi(lr_eval_string("{DownloadableRecords_FundingNotices_count}"));

// Allocate initial memory for the buffer
size_t buf_size = 1024; // Initial size
char *r_buf = (char *)malloc(buf_size);
if (r_buf == NULL) {
    lr_error_message("Failed to allocate memory for r_buf.");
    return -1;
}
r_buf[0] = '\0'; // Initialize buffer to empty string

for (i = 1; i <= m; i++) {
    // Resize the buffer if needed
    size_t new_size = strlen(r_buf) + strlen("selectedNotice=") + strlen(lr_paramarr_idx("DownloadableRecords_FundingNotices", i)) + strlen("&") + 1;
    if (new_size > buf_size) {
        buf_size = new_size * 2; // Double the size for efficiency
        char *temp = (char *)realloc(r_buf, buf_size);
        if (temp == NULL) {
            lr_error_message("Failed to reallocate memory for r_buf.");
            free(r_buf);
            return -1;
        }
        r_buf = temp;
    }

    // Append the new data to the buffer
    sprintf(r_buf, "%sselectedNotice=%s&", r_buf, lr_paramarr_idx("DownloadableRecords_FundingNotices", i));
}

lr_save_string(r_buf, "dpAllRecords");

// Free the allocated memory
free(r_buf);

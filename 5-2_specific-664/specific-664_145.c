#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *r_buf = NULL;
    int download_size, i, m;

    m = atoi(lr_eval_string("{DownloadableRecords_FundingNotices_count}"));
    
    // Allocate initial memory
    r_buf = (char *)malloc(1);  // Allocate at least one byte for the null terminator
    r_buf[0] = '\0';  // Initialize as an empty string
    
    for (i = 1; i <= m; i++) {
        // Calculate required size for concatenation
        download_size = snprintf(NULL, 0, "%sselectedNotice=%s&", r_buf, lr_paramarr_idx("DownloadableRecords_FundingNotices", i));
        
        // Reallocate memory to accommodate the new data
        r_buf = (char *)realloc(r_buf, strlen(r_buf) + download_size + 1);
        
        // Concatenate the new data to the buffer
        sprintf(r_buf, "%sselectedNotice=%s&", r_buf, lr_paramarr_idx("DownloadableRecords_FundingNotices", i));
    }
    
    // Save the final concatenated string
    lr_save_string(r_buf, "dpAllRecords");
    
    // Free dynamically allocated memory
    free(r_buf);

    return 0;
}

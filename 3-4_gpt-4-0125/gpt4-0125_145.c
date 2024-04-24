int download_size, i, m;
size_t bufferSize = 55000; // Initial buffer size
char *r_buf = (char *)malloc(bufferSize);

if (!r_buf) {
    lr_error_message("Failed to allocate memory.");
    return -1; // or appropriate error handling
}

memset(r_buf, 0, bufferSize);
m = atoi(lr_eval_string("{DownloadableRecords_FundingNotices_count}"));

for(i = 1; i <= m; i++) {
    char *record = lr_paramarr_idx("DownloadableRecords_FundingNotices", i);
    size_t requiredSize = strlen(r_buf) + strlen(record) + strlen("selectedNotice=&") + 1; // +1 for null terminator

    // Check if reallocation is needed
    if (requiredSize > bufferSize) {
        bufferSize = requiredSize + 1024; // Increase buffer size with some extra space to minimize realloc() calls
        char *temp_buf = (char *)realloc(r_buf, bufferSize);
        
        if (!temp_buf) {
            lr_error_message("Failed to reallocate memory.");
            free(r_buf);
            return -1; // or appropriate error handling
        }

        r_buf = temp_buf;
    }

    // Safe string concatenation
    snprintf(r_buf + strlen(r_buf), bufferSize - strlen(r_buf), "selectedNotice=%s&", record);
}

lr_save_string(r_buf, "dpAllRecords");
free(r_buf);

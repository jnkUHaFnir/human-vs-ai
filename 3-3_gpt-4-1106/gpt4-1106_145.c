// Allocate enough memory to hold the complete string. Make sure this is sufficient.
char *r_buf = (char *)malloc(very_large_size_required);
if(r_buf == NULL) {
    lr_error_message("Failed to allocate memory for r_buf.");
    return -1; // or handle the error accordingly
}

// Initialize the buffer to an empty string
r_buf[0] = '\0';

int download_size, i, m;
m = atoi(lr_eval_string("{DownloadableRecords_FundingNotices_count}"));
for(i=1; i<=m; i++) {
    // Concatenate without overwriting from the start every time.
    strcat(r_buf,"selectedNotice=");
    strcat(r_buf, lr_paramarr_idx("DownloadableRecords_FundingNotices", i));
    strcat(r_buf, "&");
}

lr_save_string(r_buf, "dpAllRecords");
free(r_buf); // Don't forget to free the allocated memory.

int i, m;
m = atoi(lr_eval_string("{DownloadableRecords_FundingNotices_count}"));

// Calculate the total size needed for r_buf
int totalSize = 0;
for (i = 1; i <= m; i++) {
    totalSize += snprintf(NULL, 0, "%sselectedNotice=%s&", r_buf, lr_paramarr_idx("DownloadableRecords_FundingNotices", i)) + 1;
}

// Allocate memory for r_buf
char *r_buf = (char *)malloc(totalSize);
if (r_buf == NULL) {
    lr_error_message("Failed to allocate memory for r_buf");
    return -1; // You can handle this error as needed
}

// Construct the r_buf string
r_buf[0] = '\0'; // Ensure the string is empty to start concatenating
for (i = 1; i <= m; i++) {
    sprintf(r_buf, "%sselectedNotice=%s&", r_buf, lr_paramarr_idx("DownloadableRecords_FundingNotices", i));
}

// Save the constructed r_buf string
lr_save_string(r_buf, "dpAllRecords");

// Free the allocated memory
free(r_buf);

// Allocate memory for r_buf
char *r_buf = (char *) malloc(55000);
if (r_buf == NULL) {
    lr_output_message("Failed to allocate memory");
    return -1; // Error handling
}

int download_size, i, m;
m = atoi(lr_eval_string("{DownloadableRecords_FundingNotices_count}"));

// Initialize r_buf with an empty string
r_buf[0] = '\0';

for (i = 1; i <= m; i++) {
    // Concatenate strings using snprintf
    snprintf(r_buf, 55000, "%sselectedNotice=%s&", r_buf, lr_paramarr_idx("DownloadableRecords_FundingNotices", i));
}

// Save the concatenated string
lr_save_string(r_buf, "dpAllRecords");

// Free allocated memory
free(r_buf);

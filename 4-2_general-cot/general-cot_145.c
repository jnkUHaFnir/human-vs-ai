int i, m;
m = atoi(lr_eval_string("{DownloadableRecords_FundingNotices_count}"));

// Allocate memory for buffer to hold concatenated strings
char *r_buf = (char *)malloc((m * 50) + 1); // Assuming maximum length of "selectedNotice=%s&" is 50

// Check if memory allocation was successful
if (r_buf == NULL) {
    lr_error_message("Failed to allocate memory for r_buf");
    lr_exit(LR_FAIL, LR_AUTO);
}

// Initialize buffer to empty string
r_buf[0] = '\0';

for (i = 1; i <= m; i++) {
    char temp[50];
    sprintf(temp, "selectedNotice=%s&", lr_paramarr_idx("DownloadableRecords_FundingNotices", i));
    strcat(r_buf, temp);
}

// Save the final concatenated string
lr_save_string(r_buf, "dpAllRecords");

// Free the allocated memory
free(r_buf);

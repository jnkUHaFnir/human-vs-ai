int download_size, i, m;
m = atoi(lr_eval_string("{DownloadableRecords_FundingNotices_count}"));

// Calculate total buffer size needed
int totalSize = m * (strlen("selectedNotice=") + strlen(lr_eval_string("{DownloadableRecords_FundingNotices_count}")) + strlen("&")) + 1;

char* r_buf = (char*)malloc(totalSize);
r_buf[0] = '\0'; // Ensure the string is empty

for (i = 1; i <= m; i++) {
    snprintf(r_buf + strlen(r_buf), totalSize - strlen(r_buf), "selectedNotice=%s&", lr_paramarr_idx("DownloadableRecords_FundingNotices", i));
}

lr_save_string(r_buf, "dpAllRecords");

// Free the allocated memory after using it
free(r_buf);

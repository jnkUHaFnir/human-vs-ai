int download_size, i, m;
char *r_buf;

m = atoi(lr_eval_string("{DownloadableRecords_FundingNotices_count}"));
r_buf = (char *) malloc((m * 30 + 1) * sizeof(char));

memset(r_buf, 0, m * 30 + 1);

for (i = 1; i <= m; i++) {
    sprintf(r_buf + strlen(r_buf), "selectedNotice=%s&", lr_paramarr_idx("DownloadableRecords_FundingNotices", i));
}

lr_save_string(r_buf, "dpAllRecords");
free(r_buf);

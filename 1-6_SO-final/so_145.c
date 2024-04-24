    char *r_buf;
    char buf[2048];
    int download_size,i,m;
    // Allocate memory
    if ( (r_buf= (char *)malloc(65535 * sizeof(char))) == NULL)
    {
        lr_error_message ("Insufficient memory available");
        return -1;
    }
    memset( buf, 0, sizeof(buf) );
    m = lr_paramarr_len("DownloadableRecords_FundingNotices");
    for(i=1; i<=m; i++) {
      sprintf( buf, "selectedNotice=%s&", lr_paramarr_idx("DownloadableRecords_FundingNotices",i) );
      
      // Check buffer is big enough to hold the new data
      if ( strlen(r_buf)+strlen(buf) > 65535 ) {
        lr_error_message("Buffer exceeded");
        lr_abort();
      }
      // Concatenate to final buffer
      strcat( r_buf, "%s", buf );
    }
    // Save buffer to variable
    lr_save_string(r_buf, "dpAllRecords");
    // Free memory
    free( r_buf );
    char buf[256];
    if (ground_truth_filename == NULL) {
       sprintf(buf,"%s.yaml",filename);
       ground_truth_filename = buf;
    }
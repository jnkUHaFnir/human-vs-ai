    char buf[256];
    if (ground_truth_filename == NULL) {
       /* make sure that buf is large enough */
       if(strlen(filename) + strlen(".yaml") >= sizeof(buf))
       {
           /* ack! buf isn't large enough! */ 
       }
       sprintf(buf,"%s.yaml",filename);
       ground_truth_filename = buf;
    }
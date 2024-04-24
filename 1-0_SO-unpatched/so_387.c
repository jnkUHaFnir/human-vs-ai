    char buf[8192];
    char *artist = NULL;
    size_t len = 0, total_len = 0;
    
    tmp1 = popen("cmus-remote -Q | grep 'tag artist' | sed s/'tag artist'/''/g | sed '1s/^.//'", "r");
    
    while (!feof(fp)) {
          if ( fgets(buf, sizeof(buf), fp) == NULL ) 
                 break;
          len = strlen(buf);
          artist = realloc(artist, len+1); /* +1 for \0 */
          if (artist == NULL) {
                 fprintf(stderr, "Ran out of memory\n");
                 exit(-1);
          }
          strncpy(artist+total_len, buf, len+1); /* concatenate the string at the end of artist */ 
          total_len += len;
    }
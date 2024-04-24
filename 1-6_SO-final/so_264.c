    char line[some_len];
    wp = fopen(some_file_name, "r");
    if(wp)
    {
        while(fgets(line, some_len, wp))
        {
            // use line
        }
        fclose(wp);
    }
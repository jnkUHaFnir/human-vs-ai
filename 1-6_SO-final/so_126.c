    mystruct s;
    
    s.size = 5;
    
    /* allocating array based on size */
    s.array = malloc (s.size * sizeof *s.array);
    if (!s.array) {
        fprintf (stderr, "error: virtual memory exhausted.\n");
        return 1;
    }
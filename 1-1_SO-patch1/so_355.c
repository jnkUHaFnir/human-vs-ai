        for (;;) {  /* loop continually until first_num integers found */
            char *p = buf,  /* nptr & endptr for strtol conversion */
                *endptr;
            if (!fgets (buf, MAXC, fp)) {   /* read line with integers */
                fputs ("error: EOF before all integers read.\n", stderr);
                exit (EXIT_FAILURE);
            }
            if (*p == '\n')     /* skip blank lines */
                continue;
            while (nval < first_num) {  /* loop until nval == first_num */
                errno = 0;              /* reset errno for each conversion */
                long tmp = strtol (p, &endptr, 0);  /* call strtol */
                if (p == endptr && tmp == 0) {  /* validate digits converted */
                    /* no digits converted - scan forward to next +/- or [0-9] */
                    while (*p && *p != '+' && *p != '-' && 
                            ( *p < '0' || '9' < *p))
                        p++;
                    if (*p)     /* valid start of numeric sequence? */
                        continue;   /* go attempt next conversion */
                    else
                        break;      /* go read next line */
                }
                else if (errno) {   /* validate successful conversion */
                    fputs ("error: overflow/underflow in conversion.\n", stderr);
                    exit (EXIT_FAILURE);
                }
                else if (tmp < INT_MIN || INT_MAX < tmp) {  /* validate int */
                    fputs ("error: value exceeds range of 'int'.\n", stderr);
                    exit (EXIT_FAILURE);
                }
                else {  /* valid conversion - in range of int */
                    arr[nval++] = tmp;      /* add value to array */
                    if (*endptr && *endptr != '\n') /* if chars remain */
                        p = endptr;         /* update p to endptr */
                    else        /* otherwise */
                        break;  /* bail */
                }
            }
            if (nval == first_num)  /* are all values filled? */
                break;
        }
        if (scanf ("%d", &n) != 1) {
            fputs ("error: invalid array size\n", stderr);
            return 1;
        }
        if (n > MAXA) {
            fprintf (stderr, "error: array size exceeds bound '%d'\n", MAXA);
            return 1;
        }
        
        for (i = 0; i < n; i++)
            if (scanf ("%d", &arr[i]) != 1) {
                fprintf (stderr, "error: invalid input 'arr[%d]'\n", i);
                return 1;
            }
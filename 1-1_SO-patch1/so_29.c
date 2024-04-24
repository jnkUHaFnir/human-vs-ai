    int function_example(int num_items)
    {
        int rc = EXIT_FAILURE;
        struct WotNot *wotsit = NULL;
        struct Havoc  *wreaker = NULL;
        FILE *fp = fopen(file, "r");
        if (fp == NULL)
            goto cleanup;
    
        if ((wotsit = malloc(num_items * sizeof(*wotsit))) == NULL)
            goto cleanup;
    
        rc = function_using_file(fp, num_items, wotsit);
        if (rc == EXIT_SUCCESS)
        {
            if ((wreaker = malloc(num_items * 2 * sizeof(*wreaker)) == 0)
                goto cleanup;
            rc = function_wreaking_havoc(num_items, wotsit, wreaker);
            if (rc != EXIT_SUCCESS)
                goto cleanup;
            rc = other_function(fp, num_items * 2, wreaker);
        }
    
    cleanup:
        free(wreaker);
        free(wotsit);
        if (fp != NULL)
            fclose(fp);
        return rc;
    }
    int function_example(int num_items)
    {
        int rc = EXIT_FAILURE;
        struct WotNot *wotsit = NULL;
        struct Havoc  *wreaker = NULL;
        FILE *fp = fopen(file, "r");
        if (fp == NULL)
        {
            err_remark("failed to open file '%s' for reading\n", file);
            goto cleanup;
        }
    
        if ((wotsit = malloc(num_items * sizeof(*wotsit))) == NULL)
        {
            err_remark("failed to allocated %zu bytes of memory\n",
                       num_items * sizeof(*wotsit));
            goto cleanup;
        }
    
        if ((rc = function_using_file(fp, num_items, wotsit)) != EXIT_SUCCESS)
        {
            err_remark("processing of wotsits failed\n");
            goto cleanup;
        }
        if ((wreaker = malloc(num_items * 2 * sizeof(*wreaker)) == NULL)
        {
            err_remark("failed to allocated %zu bytes of memory\n",
                       num_items * 2 * sizeof(*wreaker));
            goto cleanup;
        }
        if ((rc = function_wreaking_havoc(num_items, wotsit, wreaker) != EXIT_SUCCESS)
        {
            err_remark("failed to wreak appropriate havoc\n");
            goto cleanup;
        }
        rc = other_function(fp, num_items * 2, wreaker);
    
    cleanup:
        free(wreaker);
        free(wotsit);
        if (fp != NULL)
            fclose(fp);
        return rc;
    }
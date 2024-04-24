    int rc = EXIT_FAILURE;
    FILE *fp = fopen(file, "r");
    if (fp != NULL)
    {
        rc = function_using_resource(fp /* , … */);
        fclose(fp);
    }
    else
    {
        perror(file);
    }
    return rc;
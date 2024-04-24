    struct companyInfo * pdata = NULL; 
    pdata = calloc( 1, sizeof(struct companyInfo) ); 
    if( pdata != NULL )
        {
        strncpy(pdata->companyName, "sdfsd", sizeof(pdata->companyName));
        }
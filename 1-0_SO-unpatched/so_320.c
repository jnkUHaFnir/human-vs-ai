    intarr_t* intarr_create(unsigned int len)
    { 
        intarr_t *result;
        result = (intarr_t *)malloc(len * sizeof(intarr_t));
        if(result == NULL)
        {
            /* handle error */
        }
        return (result);
    }
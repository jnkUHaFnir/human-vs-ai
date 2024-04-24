    result = strstr(found, fetch);
    if(result)//if result is NULL, bypass the extraction
    {
        result[strlen(fetch) + 1)] = `\0`;
        printf("Your result is: %s",result);
    }
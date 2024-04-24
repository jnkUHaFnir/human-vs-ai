    ...
    int ret=0;
    int len = strlen(program_name) + strlen(argument_1)+ strlen(argument_2) + 2*strlen(space) + 1;
    char *runProgram = malloc( len);
    ret = snprintf(runProgram, len, "%s %s %s", program_name, argument_1, argument_2);
    if(ret < 0)
    {
        //handle if truncation occurred
    }
    if(ret < len)
    {
        //editing...
    }
    system(runProgram);
    free(runProgram);
    //exit(0);
    return 0;
    ...
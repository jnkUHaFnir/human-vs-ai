    while( fgets(buffer, sizeof(buffer), pdata) != NULL )
    {
        token = strtok(buffer, del);
        if (token != NULL) {
          value1 = atoi( strtok(NULL, del) );
          value2 = atof( strtok(NULL, del) );
        }
        printf("%s is %.3lf\n", token, value1 + value2);    
    }
    while( fgets(buffer, sizeof(buffer), pdata) != NULL )
    {
        char *temp;
        token = strtok(buffer, del);
        if (token != NULL) {
          temp = strtok(NULL, del);
          if (temp) value1 = atoi( strtok(NULL, del) );
          temp = strtok(NULL, del);
          if (temp) {
            value2 = atof( strtok(NULL, del) );
            printf("%s is %.3lf\n", token, value1 + value2);
          }
    }
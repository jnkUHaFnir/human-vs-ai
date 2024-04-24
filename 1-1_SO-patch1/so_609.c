        char *token = strtok(singleLineContent, ",\n");
        fprintf(fPointerForWriting, "%d", atoi(token));
        token = strtok(NULL, ",\n");
        fprintf(fPointerForWriting, ",%d     %d\n", atoi(token), i);
        if(token == NULL)
        {
            printf("There are no tokens\n");
            return -3;
        }
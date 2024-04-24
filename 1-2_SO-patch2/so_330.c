        // Stream file into memory
        size = fread(contents, 1, fileSize, stream);
        contents[size] = 0; 
        fclose(stream);
        size_t array_n;
        int n;
        if (sscanf(contents, "%zu%n", &array_n, &n) != 1) Handle_BadInput();
        
        my_array = malloc(array_n * sizeof *my_array);
        if (my_array == NULL) Handle_OOM();
         
        char *p = &contents[n];
        errno = 0;
        char *endptr;
        for (size_t count = 0; count < array_n; count++) {
          my_array[count] = strtol(p, &endptr, 10);
          if (p == endptr || errno) 
            Handle_BadInput();
          count++;
          p = endptr;
        }
        
        char ch;
        if (sscanf(p, " %c", &ch) == 1) Handle_ExtraInput();
                
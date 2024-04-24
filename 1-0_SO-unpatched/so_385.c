    while (  fgets(line, sizeof(line), fp) > 0) 
    {
      char* end;
      alive_row = strtol(&line[0], &end, 10);
      
      // If the end points to the &line[0], then no 
      // characters were converted!     
      if(end == &line[0])
      {
          printf("strtol failed!\n");
          return 0;
      }
      alive_column = strtol(&line[2], &end, 10);
      
      // If the end points to the &line[2], then no 
      // characters were converted!     
      if(end == &line[2])
      {
          printf("strtol failed!\n");
          return 0;
      }
    
      fprintf(stderr, "\n Cell: (%i)(%i)", alive_row, alive_column);       
    }
    while (  fgets(line, sizeof(line), fp) > 0) 
    {
     
      alive_row = atoi(&line[0]);
      alive_column = atoi(&line[2]);
    
      fprintf(stderr, "\n Cell: (%i)(%i)", alive_row, alive_column);       
    }
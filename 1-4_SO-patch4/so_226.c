    // improved fgets() usage  (catches IO error, unlike before
    while (fgets(buffer, BUFFSIZE, stdin) != NULL) {
      char bigWord[30];
      bigword[0] = '\0';  // Initialize bigWord
      int bigSize = 0;
      lineNum++;
      token = strtok(buffer, " \n\t");
      while(token != NULL) {               
        strcpy(currWord, token);
        int currSize = strlen(currWord);  // local declaration of currSize
        // if(currSize > bigSize && currSize != bigSize) {
        if(currSize > bigSize) {
          strcpy(bigWord, currWord);
          bigSize = strlen(bigWord);
        }
        token = strtok(NULL, " \n\t");  
      }
      printf("Line %d's word: %s\n", lineNum, bigWord);
    }
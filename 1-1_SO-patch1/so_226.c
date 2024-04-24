    // improved fgets() usage,  catches IO error, unlike before
    while (fgets(buffer, BUFFSIZE, file) != NULL) {
      char bigWord[BUFFSIZE]; // Worst case size
      bigWord[0] = '\0';  // Initialize bigWord
      int bigSize = 0;
      lineNum++;
      char *token = strtok(buffer, " \n\t"); // local declaration
      while(token != NULL) {               
        char currWord[BUFFSIZE]; // local declaration
        strcpy(currWord, token);
        int currSize = strlen(currWord);  // local declaration
        // Drop 2nd part of if() - not needed
        // if(currSize > bigSize && currSize != bigSize) {
        if(currSize > bigSize) {
          strcpy(bigWord, currWord);
          bigSize = strlen(bigWord);
        }
        token = strtok(NULL, " \n\t");  
      }
      printf("Line %d's word: `%s`\n", lineNum, bigWord);  // added ``
    }
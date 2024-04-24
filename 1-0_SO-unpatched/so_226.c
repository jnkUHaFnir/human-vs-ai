    // improved fgets() usage,  catches IO error, unlike before
    while (fgets(buffer, BUFFSIZE, file) != NULL) {
      char bigWord[BUFFSIZE]; // Worst case size
      bigWord[0] = '\0';  // Initialize bigWord
      size_t bigSize = 0;  // type int is OK for small buffers, but size_t is best
      lineNum++;
      char *token = strtok(buffer, " \n\t"); // local declaration
      while(token != NULL) {               
        char currWord[BUFFSIZE]; // local declaration
        strcpy(currWord, token);
        size_t currSize = strlen(currWord);  // local declaration
        // Drop 2nd part of if() - not needed
        // if(currSize > bigSize && currSize != bigSize) {
        if(currSize > bigSize) {
          strcpy(bigWord, currWord);
          bigSize = strlen(bigWord);  // or just use bigSize = currSize
        }
        token = strtok(NULL, " \n\t");  
      }
      printf("Line %d's word: `%s`\n", lineNum, bigWord);  // added ``
    }
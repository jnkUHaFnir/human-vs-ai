    int findRdrNum(char *userId) {
        int pos = 0;
        //iterate through 'userToRdrMap'
        for (pos = 0; pos < numOfReducers; pos++) {
            // check whether position hasn't been allocated yet
            if (userToRdrMap[pos] != NULL && strlen(userId) == strlen(userToRdrMap[pos])) {
                //compare string and return if equal
                for(int j = 0; j <= strlen(userId); j++)
                    // If letter doesn't match break loop
                    if (strcmp(userId, userToRdrMap[pos]) != 0)
                        break;
                    // if match, return position in vector    
                    else if (strcmp(userId, userToRdrMap[pos]) == 0 && strlen(userId) == j)
                        return pos;
            }
        }
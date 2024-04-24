    int findRdrNum(char *userId) {
        int pos = 0;
        // allocate your array and return -1 if not possible
        userToRdrMap = malloc(numOfReducers * sizeof(char));
        if (userToRdrMap == NULL)
            return -1;
        //iterate through 'userToRdrMap'
        for (pos = 0; pos < numOfReducers; pos++) {
            // check whether position hasn't been allocated yet
            if (userToRdrMap[pos] != NULL) {
                //compare string and return if equal
                if (strcmp(userId, userToRdrMap[pos]) == 0) {
                    return pos;
                }
            }
        }
    }
    n = fgets(currentWord[countX], 20, stdin);
    if (n > 0) {
        if (currentWord[countX][n-1] == '\n') {
            currentWord[countX][n-1] = 0;
        }
    }
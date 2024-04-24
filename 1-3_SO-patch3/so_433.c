    if (fgets(sentence, 11, stdin) != NULL) {
        size_t len = strlen(sentence);
        if (len > 0 && sentence[len - 1] == '\n')
            sentence[--len] = '\0';
        // useful side effect: len has been computed.
        ...
    }
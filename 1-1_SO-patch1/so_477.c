    if (fgets(sentence, 11, stdin) != NULL) {
        *strchrnul(sentence, '\n') = '\0';
        ...
    }
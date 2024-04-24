    if (fgets(sentence, 11, stdin) != NULL) {
        sentence[strcspn(sentence, "\n")] = '\0';
        ...
    }
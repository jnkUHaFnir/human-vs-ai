char **temp = realloc(words, (sizeof(char *) * number_of_words));
if(temp == NULL) {
    // realloc failed.
    perror("realloc");
    exit(EXIT_FAILURE);
}
words = temp;
words[number_of_words - 1] = malloc(strlen(word) + 1);
strcpy(words[number_of_words - 1], word);
void trim(char *word) {
    if ((word[strlen(word) - 1] < 48 || word[strlen(word) - 1] > 57) //numeric characters
        && (word[strlen(word) - 1] < 65 || word[strlen(word) - 1] > 90) //uppercase characters
        && ((word[strlen(word) - 1] < 97 || word[strlen(word) - 1] > 122))
    ) {
        word[strlen(word) - 1] = '\0';
        if (strlen(word) > 0)
            trim(word);
    }
    if ((word[0] < 48 || word[0] > 57) //numeric characters
        && (word[0] < 65 || word[0] > 90) //uppercase characters
        && ((word[0] < 97 || word[0] > 122))
    ) {
        memmove(word, word + 1, strlen(word) + 1);
        if (strlen(word) > 0)
            trim(word);
    }
}

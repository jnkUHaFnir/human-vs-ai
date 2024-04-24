number_of_words++;
char **temp = realloc(words, (sizeof(char *) * number_of_words));
if(temp == NULL) {
    perror("realloc");
    exit(EXIT_FAILURE);
}
words = temp;
words[number_of_words] = ...
char **temp = realloc(words, sizeof(char *) * (number_of_words + 1));
if(temp == NULL) {
    perror("realloc");
    exit(EXIT_FAILURE);
}
words = temp;
words[number_of_words] = malloc(strlen(word) + 1);
strcpy(words[number_of_words], word);
number_of_words++;
if(word[strlen(word) -1 ] < 48 || word[strlen(word) -1 ] > 57...
if((word[strlen(word) -1 ] < 48 || word[strlen(word) -1 ] > 57)
    && (word[strlen(word) -1 ] < 65 || word[strlen(word) -1 ] > 90)
    && (word[strlen(word) -1 ] < 97 || word[strlen(word) -1 ] > 122)) {
    ...
}
char word[64] = {0};

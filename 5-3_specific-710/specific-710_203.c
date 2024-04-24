void trim(char *word)
{
    // Trim leading characters
    while (isalnum(*word) == 0 && *word != '\0') {
        memmove(word, word + 1, strlen(word));
    }

    // Trim trailing characters
    size_t len = strlen(word);
    while (len > 0 && !isalnum(word[len - 1])) {
        word[--len] = '\0';
    }
}

void read_file(char *file_name, int file_number)
{
    // Your existing code...

    if (exists < 1)
    {
        printf("number of words: %i\n", number_of_words);
        number_of_words++;
        char **temp = realloc(words, sizeof(char *) * number_of_words);
        if (temp == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        words = temp;
        words[number_of_words - 1] = malloc(strlen(word) + 1);
        strcpy(words[number_of_words - 1], word);
    }

    // Your existing code...
}

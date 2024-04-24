char **temp = realloc(words, (sizeof(char *) * number_of_words));
if(temp == NULL) {
    // Handle error
    perror("realloc");
    exit(EXIT_FAILURE);
}
words = temp;
void trim(char *word)
{
    if(strlen(word) > 0) {
        if((word[strlen(word) - 1] < '0' || word[strlen(word) - 1] > '9') &&
           (word[strlen(word) - 1] < 'A' || word[strlen(word) - 1] > 'Z') &&
           (word[strlen(word) - 1] < 'a' || word[strlen(word) - 1] > 'z'))
        {
            word[strlen(word) - 1] = '\0';
            trim(word);
        }

        if((word[0] < '0' || word[0] > '9') &&
           (word[0] < 'A' || word[0] > 'Z') &&
           (word[0] < 'a' || word[0] > 'z'))
        {
            memmove(word, word + 1, strlen(word));
            trim(word);
        }
    }
}

number_of_words++;
//...
words[number_of_words] = malloc(strlen(word) + 1);
strcpy(words[number_of_words], word);
char **temp = realloc(words, (sizeof(char *) * number_of_words));
if (temp == NULL) {
    perror("realloc");
    // Proper error handling: Free previously allocated memory, notify user about the error, etc...
    exit(EXIT_FAILURE);
}
words = temp;
if((word[strlen(word) -1 ] < '0' || word[strlen(word) -1 ] > '9') //numeric characters
  && (word[strlen(word) -1 ] < 'A' || word[strlen(word) -1 ] > 'Z') //uppercase characters
  && (word[strlen(word) -1 ] < 'a' || word[strlen(word) -1 ] > 'z') //lowercase characters
)
{

void append(char **string, char ch)
{
    int size = strlen(*string);
    char *new_str = malloc(size + 2); // Allocate memory for the new string with new character
    strcpy(new_str, *string); // Copy old string to the new string
    new_str[size] = ch; // Add the new character
    new_str[size+1] = '\0'; // Null-terminate the new string
    free(*string); // Free the memory of the old string
    *string = new_str; // Point to the new string
}
words[number_of_words] = malloc(strlen(word) + 1);
strcpy(words[number_of_words], word);
words[number_of_words - 1] = malloc(strlen(word) + 1);
strcpy(words[number_of_words - 1], word);

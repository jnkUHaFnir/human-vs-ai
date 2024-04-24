if((word[strlen(word) -1 ] < 48 || word[strlen(word) -1 ] > 57)     // Numeric characters
   && (word[strlen(word) -1 ] < 65 || word[strlen(word) -1 ] > 90)  // Uppercase characters
   && (word[strlen(word) -1 ] < 97 || word[strlen(word) -1 ] > 122) // Lowercase characters
)
char **temp = realloc(words, (sizeof(char *) * (number_of_words + 1)));
if(temp == NULL) {
    // Handle realloc failure
} else {
    words = temp;
    words[number_of_words] = malloc(strlen(word) + 1);
    strcpy(words[number_of_words], word);
    number_of_words++;
}
memset(word, 0, sizeof(word));
// ...
while (i < strlen(line) && line[i] != '\n')
{
    if (line[i] != ' ')
    {
        append(word, line[i]);
    }
    else 
    {
        if (strlen(word) > 0)
        {
            // Trim the word
            trim(word);

            // Do your magic
            int exists = 0;
            for (int a = 0; a < number_of_words; a++)
            {
                if (strcmp(words[a], word) == 0) // Word exists in the words array
                {
                    exists = 1;
                    break;
                }
            }

            if (!exists)
            {
                char **temp = realloc(words, sizeof(char *) * (number_of_words + 1));
                if (temp)
                {
                    words = temp;
                    words[number_of_words] = malloc(strlen(word) + 1);
                    strcpy(words[number_of_words], word);
                    number_of_words++;
                }
                else
                {
                    // Handle realloc failure
                    perror("realloc");
                    exit(EXIT_FAILURE);
                }
            }
            memset(word, 0, sizeof(word)); // Reset word after processing
        }
    }
    i++;
}
// ...
for (int i = 0; i < number_of_words; i++)
{
    free(words[i]);
}
free(words);

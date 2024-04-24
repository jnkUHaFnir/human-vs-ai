void read_file(char *file_name, int file_number)
{
    FILE *file = fopen(file_name, "r");
    char line[2048];
    int i = 0;
    char word[64];
    
    while (fgets(line, sizeof line, file) != NULL)
    {
        i = 0;
        
        while (i < strlen(line) && line[i] != '\n')
        {
            if (line[i] != ' ')
            {
                append(word, line[i]);
            }
            else
            {
                if (strlen(word) > 1)
                {
                    trim(word);
                    
                    int a = 0;
                    int exists = 0;

                    while (a < number_of_words)
                    {
                        if (strcmp(words[a], word) == 0)
                        {
                            exists = 1;
                            printf("%s\n", words[a]);
                        }
                        a++;
                    }

                    if (!exists)
                    {
                        printf("number of words: %i\n", number_of_words);
                        
                        char **temp = realloc(words, sizeof(char *) * number_of_words);
                        if (temp == NULL) {
                            perror("realloc");
                            exit(EXIT_FAILURE);
                        }
                        words = temp;
                        
                        words[number_of_words] = malloc(strlen(word) + 1);
                        strcpy(words[number_of_words], word);
                        number_of_words++;
                    }

                    printf("%s\n", word);

                    memset(word, 0, strlen(word));
                }
            }
            i++;
        }
    }

    fclose(file);
}

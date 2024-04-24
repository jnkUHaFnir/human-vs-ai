strcpy(temp->word, word);
temp->word = (char*)malloc(sizeof(char));
temp->word = (char*)malloc(strlen(word) + 1);

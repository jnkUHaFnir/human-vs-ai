int wordSize = 2;
char *word = (char *)malloc(wordSize*sizeof(char));
char ch;

FILE* InputWords = NULL;
InputWords = fopen(ListOfWords,"r"); /* variable ListOfWords contains name of the file */

if (InputWords == NULL)
{
  printf("Error while opening the file.\n");
  return 0;
}

int index = 0;
while((ch = fgetc(InputWords)) != EOF)
{
  if(ch == ' ' || ch == '\n' || ch == '\t')
  {
    word[index] = '\0'; // Null-terminate the string
    printf("%s\n", word);
    wordSize = 2;
    index = 0;
    free(word);
    word = (char *)malloc(wordSize*sizeof(char));
  }
  else
  {
    word[index] = ch;
    index++;
    if (index >= wordSize) // If the word is too long for the current allocation
    {
      wordSize *= 2; // Increase the word size
      word = (char *)realloc(word, wordSize*sizeof(char)); // Reallocate memory
    }
  }
}
fclose(InputWords);

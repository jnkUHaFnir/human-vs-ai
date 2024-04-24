#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int wordSize = 2;
  char *word = malloc(wordSize*sizeof(char));
  int ch;

  FILE* InputWords = NULL;
  InputWords = fopen("ListOfWords.txt","r");

  if (InputWords == NULL) {
    printf("Error while opening the file.\n");
    return 0;
  }

  int index = 0;
  while((ch = fgetc(InputWords)) != EOF) {
    if(ch == ' ') {
        word[index] = '\0'; // Add null-terminator
        printf("%s\n", word);
        wordSize = 2;
        index = 0;
        free(word);
        word = malloc(wordSize*sizeof(char));
    }
    else {
        word[index] = ch;
        index++;
        if(index >= wordSize) {
            wordSize *= 2; // Double the size
            word = realloc(word, wordSize*sizeof(char));
        }
    }
  }
  word[index] = '\0'; // Add null-terminator for the last word
  printf("%s\n", word);
  fclose(InputWords);
  free(word);

  return 0;
}

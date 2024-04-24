#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned char* bit_encrypt(const char* text){
  char text_copy[strlen(text)];
  printf("Strlen: %ld\n", strlen(text));
  bool (*bits)[8] = malloc(strlen(text) * sizeof(*bits));
  
  int dec = 0;
  int j = 0;

  for(int i = 0; i < strlen(text); i++){
    text_copy[i] = text[i];
    dec = (int)text_copy[i];

    if(dec >= 128){
      bits[i][j] = true;
      dec = dec - 128;
    }
    else{
      bits[i][j] = false;
    }
    j++;

    // Rest of your conversion logic remains the same

    // Reset j for the next character
    j = 0;
  }
  
  text_copy[strlen(text)] = '\0';

  for(int i = 0; i < strlen(text_copy); i++){
    printf("%c:  ", text_copy[i]); 
    for(int j = 0; j < 8; j++){
      printf("%d ", bits[i][j]);
    }
    printf("\n");
  }

  // Free the dynamically allocated memory
  free(bits);

  return 0;
}

int main() {
  const char *text = "Hello world!";
  bit_encrypt(text);

  return 0;
}

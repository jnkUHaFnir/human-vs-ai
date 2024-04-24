#include <stdio.h>
#include <stdbool.h>
#include <string.h>

unsigned char* bit_encrypt(const char* text){
  int text_length = strlen(text);

  // Initialize text_copy
  char text_copy[text_length + 1]; // +1 for null terminator
  strcpy(text_copy, text);

  bool (*bits)[8] = malloc(text_length * sizeof(*bits)); // Allocate memory for bits

  int dec = 0;
  int j = 0;

  for(int i = 0; i < text_length; i++){
    dec = (int)text_copy[i];

    for(int k = 0; k < 8; k++){
      bits[i][k] = dec & (1 << (7 - k));
    }

    j = 0;
  }

  text_copy[text_length] = '\0';

  for(int i = 0; i < text_length; i++){
    printf("%c:  ", text_copy[i]); 
    for(int j = 0; j < 8; j++){
      printf("%d ", bits[i][j]);
    }
    printf("\n");
  }

  int a = 53;
  printf("%d", a);

  free(bits); // Free dynamically allocated memory

  return 0;
}

int main() {
  bit_encrypt("Hello world!");
  return 0;
}

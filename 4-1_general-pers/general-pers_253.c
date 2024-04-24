#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned char** bit_encrypt(const char* text){
  char text_copy[strlen(text) + 1]; // +1 for the null terminator
  strcpy(text_copy, text);

  unsigned char** bits = (unsigned char**)malloc(strlen(text_copy) * sizeof(unsigned char*));
  
  for(int i = 0; i < strlen(text_copy); i++){
    bits[i] = (unsigned char*)malloc(8 * sizeof(unsigned char));

    int dec = (int)text_copy[i];
    int j = 0;

    for(int k = 128; k > 0; k /= 2){
      bits[i][j] = dec & k;
      j++;
    }
  }

  text_copy[strlen(text)] = '\0';

  for(int i = 0; i < strlen(text_copy); i++){
    printf("%c:  ", text_copy[i]); 
    for(int j = 0; j < 8; j++){
      printf("%d ", bits[i][j]);
    }
    printf("\n");
  }

  return bits;
}

int main() {
  const char* text = "Hello world!";
  unsigned char** encrypted_bits = bit_encrypt(text);

  // Don't forget to free the memory allocated for bits
  for(int i = 0; i < strlen(text) + 1; i++) {
      free(encrypted_bits[i]);
  }
  free(encrypted_bits);

  return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

unsigned char* bit_encrypt(const char* text){
  char text_copy[strlen(text)];
  printf("Strlen: %ld\n", strlen(text));
  
  int text_length = strlen(text);
  bool** bits = (bool**)malloc(text_length * sizeof(bool*));
  for (int i = 0; i < text_length; i++) {
    bits[i] = (bool*)malloc(8 * sizeof(bool));
  }

  for(int i = 0; i < text_length; i++){
    text_copy[i] = text[i];
    int dec = (int)text_copy[i];
    
    int j = 0;
    int temp_dec = dec;

    for(int k = 128; k >= 1; k /= 2) {
      bits[i][j] = temp_dec >= k;
      if(temp_dec >= k) {
        temp_dec -= k;
      }
      j++;
    }
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

  for (int i = 0; i < text_length; i++) {
    free(bits[i]);
  }
  free(bits);
  return 0;
}

int main() {
  bit_encrypt("Hello world!");
  return 0;
}

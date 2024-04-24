#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void bit_encrypt(const char* text) {
  char text_copy[strlen(text)];
  printf("Strlen: %ld\n", strlen(text));
  bool bits[strlen(text)][8];
  int dec = 0;

  for(int i = 0; i < strlen(text); i++) {
    text_copy[i] = text[i];
    dec = (int)text_copy[i];
    int j = 7;

    while(dec > 0) {
      bits[i][j] = dec % 2;
      dec /= 2;
      j--;
    }

    while(j >= 0) {
      bits[i][j] = false;
      j--;
    }
  }

  text_copy[strlen(text)] = '\0';

  for(int i = 0; i < strlen(text_copy); i++) {
    printf("%c:  ", text_copy[i]); 
    for(int j = 0; j < 8; j++) {
      printf("%d ", bits[i][j]);
    }
    printf("\n");
  }
}

int main() {
  const char* input = "Hello world!";
  bit_encrypt(input);

  return 0;
}

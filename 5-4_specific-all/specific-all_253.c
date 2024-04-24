#include <stdio.h>
#include <stdbool.h>
#include <string.h>

unsigned char* bit_encrypt(const char* text){
  size_t text_length = strlen(text);
  char text_copy[text_length+1]; // +1 for null terminator
  strcpy(text_copy, text);

  printf("Strlen: %ld\n", text_length);
  bool bits[text_length][8];
  int dec = 0;

  for(int i = 0; i < text_length; i++){
    dec = (int)text_copy[i];

    for (int j = 0; j < 8; j++) {
      bits[i][j] = dec & 0x80; // Check the leftmost bit
      dec = dec << 1; // Shift left by one bit
    }
  }

  for(int i = 0; i < text_length; i++){
    printf("%c:  ", text_copy[i]); 
    for(int j = 0; j < 8; j++){
      printf("%d ", bits[i][j]);
    }
    printf("\n");
  }

  int a = 53;
  printf("%d", a);

  return 0;
}

int main() {
  const char* text = "Hello world!";
  bit_encrypt(text);
  return 0;
}

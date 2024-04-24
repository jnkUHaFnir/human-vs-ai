text_copy[strlen(text)] = '\0';
char text_copy[strlen(text) + 1];
unsigned char* bit_encrypt(const char* text){
  char text_copy[strlen(text) + 1];
  printf("Strlen: %ld\n", strlen(text));
  bool bits[strlen(text) + 1][8];
  int dec = 0;
  int j = 0;
  // ...
  text_copy[strlen(text)] = '\0';
  // ...
}

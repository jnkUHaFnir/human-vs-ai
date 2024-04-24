unsigned char* bit_encrypt(const char* text){
  size_t len = strlen(text);
  char text_copy[len + 1];
  memcpy(text_copy, text, len);
  text_copy[len] = '\0';

  ... // rest of the code
}
unsigned char* bit_encrypt(const char* text){
  
  size_t len = strlen(text);
  bool bits[len][8];
  int dec = 0;
  int j = 0;

  for(int i = 0; i < len; i++){
    dec = (int)text[i];
    // ... rest of the code
}
  //return 0; // Remove this line
  // Instead, return the encrypted data structure (or NULL if you don't create it)
  return NULL;

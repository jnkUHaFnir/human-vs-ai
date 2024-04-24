unsigned char* bit_encrypt(const char* text){
  char text_copy[strlen(text)];
  printf("Strlen: %ld\n", strlen(text));
  bool** bits = (bool**)malloc(strlen(text) * sizeof(bool*));
  for(int i = 0; i < strlen(text); i++){
    bits[i] = (bool*)malloc(8 * sizeof(bool));
  }

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

      // Add the rest of your code here...

  }

  text_copy[strlen(text)] = '\0';

  for(int i = 0; i < strlen(text_copy); i++){
    printf("%c:  ", text_copy[i]); 
    for(int j = 0; j < 8; j++){
      printf("%d ", bits[i][j]);
    }
    printf("\n");
  }
  int a = 53;
  printf("%d", a);

  for(int i = 0; i < strlen(text); i++){
    free(bits[i]);
  }
  free(bits);

  /* unsigned char* vystup = (unsigned char*)calloc(strlen(text_copy), sizeof(unsigned char*));
  */

  return 0;
}

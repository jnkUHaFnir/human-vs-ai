char text_copy[strlen(text) + 1];
unsigned char* bit_encrypt(const char* text){
  // Allocate space for copy of text + null terminator
  char text_copy[strlen(text) + 1]; 
  printf("Strlen: %ld\n", strlen(text));
  bool bits[strlen(text)][8];
  int dec = 0;
  int j = 0;

  for(int i = 0; i < strlen(text); i++){
    text_copy[i] = text[i];
    dec = (int)text_copy[i];
    // Reset j to 0 at the start of every character
    j = 0;

    // Your bit-setting logic here remains unchanged

    // After processing each character
    text_copy[i + 1] = '\0'; // Move this inside the loop to avoid overrunning in the first iteration
  }

  // Logic to print bits and text_copy remains unchanged

  return 0;
}

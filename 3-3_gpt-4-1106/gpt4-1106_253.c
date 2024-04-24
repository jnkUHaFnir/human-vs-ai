unsigned char* bit_encrypt(const char* text){
  char text_copy[strlen(text)]; // This line doesn't allocate space for the null terminator
  // ...
  text_copy[strlen(text)] = '\0'; // This line writes past the end of the array
char text_copy[strlen(text) + 1]; // This allocates the correct amount of space
size_t text_length = strlen(text);
char text_copy[text_length + 1]; // +1 for the '\0' null terminator
bool bits[text_length][8];
// ...
text_copy[text_length] = '\0'; // Now it is safe to set null terminator

// Similarly update your for-loop conditions
for(int i = 0; i < text_length; i++){
    // ...
}
// And you can use `text_length` instead of calling `strlen(text_copy)` again.
for (int i = 0; i < text_length; i++) {
    unsigned char ch = text[i];
    for (int j = 7; j >= 0; j--) {
        bits[i][j] = (ch >> (7 - j)) & 1;
    }
}

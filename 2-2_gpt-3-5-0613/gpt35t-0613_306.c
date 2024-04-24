void remove_zero(struct number *a) {
  char *b = (*a).digits; // pointer to the digits array
  
  // Find the first non-zero digit
  int i;
  for (i = 0; b[i] == '0'; i++) {
    if (b[i] == '\0') { // Reached the end of the string
      break;
    }
  }
  
  // Copy the remaining digits back to (*a).digits
  int j;
  for (j = 0; b[i + j] != '\0'; j++) {
    (*a).digits[j] = b[i + j];
  }
  
  // Add null character at the end of the new string
  (*a).digits[j] = '\0';
}

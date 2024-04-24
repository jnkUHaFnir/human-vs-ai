void insert(char *str, char input, int n) {
  str = realloc(str, (n + 2) * sizeof(char)); // Increase the size of the array to accommodate the new character and the null terminator
  int i;
  for (i = n; i > 0; i--) {
    str[i] = str[i-1]; // Shift the characters to the right
  }
  str[0] = input; // Insert the new character at the beginning
  str[n+1] = '\0'; // Add the null terminator at the end of the string
  printf("Resulting string: %s\n", str);
}

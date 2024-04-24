#include <stdio.h>
#include <string.h>

int main() {
  char input[] = "ABCDEFGHIJKL";
  int input_len = strlen(input);
  int output_len = (2 * input_len) - 1;
  char output[output_len + 1]; // Add 1 for the null terminator
  output[output_len] = '\0'; // Null terminator at the end of the output array

  int j = 0;
  for(int i = 0; i < input_len; i++) {
    output[j] = input[i]; // Copy the character from input to output

    if(i < input_len - 1) {
      output[j+1] = ' '; // Add a space after each character pair
    }

    j += 2; // Move to the next position in the output array
  }

  printf("%s\n", output);

  return 0;
}

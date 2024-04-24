#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse the hexadecimal string and convert it into binary byte values
void parse_hex(const char *hex_string, unsigned char **bytes, size_t *bytes_len) {
  *bytes_len = strlen(hex_string) / 2;
  *bytes = (unsigned char *) malloc(*bytes_len);
  
  for (size_t i = 0; i < *bytes_len; ++i) {
      sscanf(hex_string + 2 * i, "%2hhx", *bytes + i);
  }
}

int main() {
  // Input a sample binary file
  FILE *f = fopen("example.exe", "rb+");
  
  if (!f) {
    printf("Could not open the binary file!\n");
    return 1;
  }
  
  long int offset_ed;
  printf("Specify offset within the binary:    ");
  scanf("%ld", &offset_ed);
  
  fseek(f, offset_ed, SEEK_SET);
  
  printf("Specify HEX bytes to be written to the binary:  ");

  // Dynamic memory allocation for hexes
  char* hexes = malloc(1024 * sizeof(char));
  
  scanf("%s", hexes);
  
  // Convert the input string into binary byte values and store them into "bytes"
  unsigned char *bytes;
  size_t bytes_len;
  parse_hex(hexes, &bytes, &bytes_len);
  
  // Write the byte values into the binary file
  fwrite(bytes, sizeof(unsigned char), bytes_len, f);

  // Cleanup
  free(hexes);
  free(bytes);
  
  fclose(f);
  
  return 0;
}

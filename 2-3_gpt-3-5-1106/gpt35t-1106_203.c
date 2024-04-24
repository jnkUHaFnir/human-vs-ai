#include <ctype.h>

void trim(char *word) {
  // Trim leading non-alphanumeric characters
  while (*word && !isalnum((unsigned char)*word)) {
    word++;
  }

  // Trim trailing non-alphanumeric characters
  char *end = word + strlen(word) - 1;
  while (end > word && !isalnum((unsigned char)*end)) {
    end--;
  }
  *(end + 1) = '\0'; // Terminate the trimmed string
}
void read_file(char *file_name, int file_number) {
  FILE *file = fopen(file_name, "r");
  if (file == NULL) {
    perror("Error opening file");
    return;
  }

  // ... (rest of the function)

  fclose(file);
}

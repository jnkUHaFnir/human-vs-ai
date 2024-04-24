#include <stdio.h>
#include <string.h>

int main() {

  // Define color values
  char green[] = "green";
  char red[] = "red";

  char bands[10], color1[10], color2[10];
  int mult;

  printf("Select how many bands the resistor has");
  printf("\n A. 4 bands");
  printf("\n B. 5 bands");
  printf("\n C. 6 bands");
  scanf("%s", bands);

  switch (bands[0]) {

    case 'a':
    case 'A':
      printf("Enter the colors");
      scanf("%s %s", color1, color2);

      // Compare color strings and assign values
      if (strcmp(color1, green) == 0 && strcmp(color2, red) == 0) {
        mult = 6;
      } else {
        mult = 0; // or any default value you want to assign
      }

      printf("%d\n", mult);
      break;

    default:
      printf("Invalid input\n");
      break;
  }

  return 0;
}

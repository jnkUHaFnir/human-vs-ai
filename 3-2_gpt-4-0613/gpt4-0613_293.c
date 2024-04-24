#include <stdio.h>
#include <string.h>

int main() {
  char bands;
  char color1[10], color2[10];
  int mult;
  
  printf("Select how many bands the resistor has\n");
  printf("A. 4 bands\n");
  printf("B. 5 bands\n");
  printf("C. 6 bands\n");
  scanf(" %c", &bands);
  
  if (bands == 'A' || bands == 'a')
  {
    printf("Enter the colors\n");
    scanf("%s %s", &color1, &color2);
    
    int color1_val, color2_val;
    if (strcmp(color1, "green") == 0)
      color1_val = 2;
    else if (strcmp(color1, "red") == 0)
      color1_val = 3;
    
    if (strcmp(color2, "green") == 0)
      color2_val = 2;
    else if (strcmp(color2, "red") == 0)
      color2_val = 3;

    mult = color1_val * color2_val;
    printf("%d\n", mult);
  
  }

  return 0;
}

#include <stdio.h>
#include <string.h>

int main()
{    
  char String4H1[10] = "*FV";
  char String4H3[10] = "*RV";
  char String4H2[10] = "#";

  char data1[10];
  char data2[10];

  snprintf(data1, 4, "%03d", 200); //Convert integer to string function
  snprintf(data2, 4, "%03d", 200); //Convert integer to string function

  strcat(String4H1, data1);    //*FV200
  strcat(String4H3, data2);    //*RV200

  strcat(String4H1, String4H2);   //*FV200#
  strcat(String4H3, String4H2);   //*RV200#

  printf("String4H1: %s\n", String4H1);
  printf("String4H3: %s\n", String4H3);

  return 0;

}

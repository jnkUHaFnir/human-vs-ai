    #include <stdio.h>
    #include <stdlib.h>
    
    #define MAX 50
    
    char* get_string() {
      // Declaring and allocating the required memory
      char *val = (char *)malloc(sizeof(int) * MAX);
    
      printf("Enter target: ");
      scanf("%s", val);
      // Returning the provided value
      return val;
    }
    
    int main(void) {
      // Initializing the strings
      char *x1 = get_string();
      char *x2 = get_string();
      char *x3 = get_string();
      char *x4 = get_string();
      char buffer[MAX] = {0};
      // buffer = ping str1.str2.str3.str4
      sprintf(buffer, "ping %s.%s.%s.%s", x1, x2, x3, x4);
      // Command execution will succeed now, only one argument given here
      system(buffer);
    
      return 0;
    }
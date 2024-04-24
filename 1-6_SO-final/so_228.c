    #include <stdio.h>
    #include <stdlib.h>
    
    #define MAX 50
    
    char* get_string() {
      char *val = (char *)malloc(sizeof(int) * MAX);
    
      printf("Enter target: ");
      scanf("%s", val);
    
      return val;
    }
    
    int main(void) {
      // Initializing the strings
      char *str1 = get_string();
      char *str2 = get_string();
      char *str3 = get_string();
      char *str4 = get_string();
      char buffer[MAX] = {0};
      // buffer = ping str1.str2.str3.str4
      sprintf(buffer, "ping %s.%s.%s.%s", str1, str2, str3, str4);
      // Command execution will succeed now, only one argument given here
      system(buffer);
    
      return 0;
    }
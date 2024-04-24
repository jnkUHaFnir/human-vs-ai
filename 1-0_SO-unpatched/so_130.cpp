    #include <stdio.h>
    #include <stdlib.h>
    
    int main(int argc, char* argv[])
    {
      for (int i=1; i < argc; i++){
          char* end;
          int val = strtol(argv[i], &end, 10);
          if (argc >= 2 && !end[0] && val >= 0){
              printf("%s is valid\n", argv[i]);
          } else {
              printf("%s is invalid\n", argv[i]);
          }
      }
      return 0;
    }
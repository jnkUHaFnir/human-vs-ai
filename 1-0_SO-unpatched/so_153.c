	#include <stdio.h>
	#include <string.h>
    #include <stdlib.h>
	int
	main() 
    {
	   char *string = "?cmd=ASET&12&30";
	   #define ASET_CMD "?cmd=ASET"
	   int hour, minute;
	   if (strncmp(string, ASET_CMD, strlen(ASET_CMD)) == 0) {
		   if (sscanf(string + strlen(ASET_CMD), "&%d&%d", &hour, &minute) != 2)  {
              printf("Couldn't parse input string");
              exit(EXIT_FAILURE);
           }
	   }
	   printf("hour: %d, minute: %d\n", hour, minute);
       return(EXIT_SUCCESS);
	}
    $ cc -o prog prog.c
    $ ./prog
    hour: 12, minute: 30
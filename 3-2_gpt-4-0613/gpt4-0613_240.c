
In this example, sprintf is used to write the formatted string to 'buf', which is a pointer to a place in 'buffer'. 'buf' is then updated to point to the end of the string in 'buffer' where the next sprintf will write to. Once 'buffer' is almost full (or after the end of the loop if it didn't fill up), it gets written to the file. 

This method should be faster than calling fprintf for every set of numbers, as each write operation can take a significant amount of time and minimizing the number of writes can thus significantly reduce the time needed to write to the file.

Remember: size of BUFSIZ is platform dependent. make sure you added the necessary includes(#include <stdio.h>), and use a safe margin (e.g., 50 here) for the check to flush the buffer into the file, otherwise, buffer overflow may happen. 

Further optimization may be achieved by using write() syscall instead of fputs(), but this method would be more complicated as you would need to deal with file descriptors rather than FILE pointers and handle any potential partial writes.

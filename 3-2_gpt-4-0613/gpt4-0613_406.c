In this example, fgets() reads at most MAX_SIZE-1 characters from the user and automatically adds the null character at the end of the string, making it safe. If the user input exceeds the size, it's not read which means it won't crash your program.

A more robust solution could involve dynamically allocating the buffer size based on the input size which is more complex and involves more understanding about memory management in C.

A final note, using gets_s is generally not recommended due to its unsafe nature, fgets() would be the preferred function.

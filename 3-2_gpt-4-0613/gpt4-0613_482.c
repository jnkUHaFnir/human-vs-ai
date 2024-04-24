
Changes:

1) For reading lines from your files, use `fgets` instead of repeated `fgetc`.
2) Keep track of the tail node as you build your list so you can always append to the end, avoiding the need for a variable to keep track of EOF.
3) Allocate memory for each node as you read a new line. Only after copying the line from the buffer to your linked list, move to the next line.
4) Safely free your linked lists by using a temporary pointer.
5) Closing files after reading is always a good practice.

free(buffer);
//free(temporary); // no need to free here
return 0;

// As for other possible problems in your code, one thing to keep in mind is that if the input textfile is very large, your program might run out of memory, since you're allocating memory in chunks of 1001 bytes each time. A more efficient way would be to allocate a larger buffer upfront, and then use realloc only when you need more space. For example, you could start with a buffer of size 10000, and then double its size every time you need more space. 

// Also, you should check if the initial malloc calls succeed, since they could return NULL if there's not enough memory available.

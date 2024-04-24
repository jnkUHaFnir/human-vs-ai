
Remember to free the allocated memory for str0 when you're done with it:

```c++
delete[] str0;

This will automatically handle memory allocation and deallocation for you.

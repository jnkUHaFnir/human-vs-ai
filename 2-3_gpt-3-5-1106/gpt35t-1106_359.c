
Additionally, it's good to avoid using `malloc` and `free` in C++ code. It's better to use `new` and `delete` for memory allocation and deallocation. Also, use a smart pointer like `unique_ptr` to manage memory and avoid memory leaks.

After making these changes, try recompiling the code and creating the shared library. If the segmentation fault persists, there might be other issues in the code that need to be addressed.

This would allow you to pass in any number of arguments to your `MYNEW()` macro, which would then be perfectly forwarded to your `Alloc()` function. This way you can create any object, default-constructible or not, with any number of arguments to the constructor.

This approach requires C++11 and its features such as variadic template and perfect forwarding, which are powerful tools when you want to "pass through" a variable number of arguments from one place to another.

This code will fail at compile-time if you try to use it to create an object of a class that lacks a suitable constructor. So, you will always be safe to use this for any object: if it compiles, it works. 

Note: Remember to guard your code with a condition to handle `std::bad_alloc` exception when `malloc` fails to allocate memory. It's a good practice to handle exceptions for such situations.

Also, remember to deallocate the memory properly. Memory allocated with `malloc` should be deallocated with `free`, but here, we also need destructor of the object to be automatically called, which `free` won't do. So, when you want to release this memory, you'll need to explicitly call the destructor and then `free` the memory: 

```cpp
Type* obj = MYNEW(Type, Allocator, args...);

// ... use obj ...

obj->~Type(); // call destructor
std::free(obj); // release memory


Please do not use `free` for objects that were allocated with `new` in C++ – instead, you should use `delete`. The above code handles deletion for all nodes except the tail. If needed to delete the tail, you have to use a different strategy or modify the structure such that you always have access to the previous node.

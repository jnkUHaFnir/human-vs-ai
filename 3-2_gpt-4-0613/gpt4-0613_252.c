
This code will print:


As you can see, this way is safer since it handles possible memory issues by allocating enough memory to store concatenated strings using malloc function. 

Note: Always make sure to free any memory that you have allocated with `malloc`. To avoid memory leaks, you should always `free()` memory that isn't being used anymore.

Moreover, this method might be a little bit tricky if you target different OS's since different operating systems use different directory separators. It is always a good idea to use libraries that handle paths' normalization.

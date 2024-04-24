
This way you:

- Make sure to free the data if anything goes wrong
- Allocate the correct sizes for your arrays
- Create the Pixel struct inside the loop and read data directly into it
- Store the normalised height in the given structure field

Note: You have allocated memory for BMPImage, BMPHeader and Pixel, which requires manual memory management. After using these data structures you should free the allocated memory to prevent memory leaks. Use `free()` method for each `malloc()` you've called.

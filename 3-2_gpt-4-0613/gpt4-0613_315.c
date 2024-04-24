This program will print out "197121" as requested. Note that this will work only if your original `unsigned char` values were in big-endian order, that is, the most significant byte was at the higher index. If your data is in little-endian order, you'll need to reverse that as well before running this function.

Please note that to handle larger arrays some parts of the code need to be updated. For example, it's possible to handle larger arrays by making sure `tmp` and `result` are large enough, or by allocating memory dynamically using `malloc()`. If your array can exceed 256 bytes, just increase the size of these arrays or switch to dynamic allocation.


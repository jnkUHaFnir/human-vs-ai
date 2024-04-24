
In this corrected version, dummies is now a pointer-to-Dummy. When passing to load_dummies function, &dummies passes the address of this pointer, so by using * operator, load_dummies can assign the allocated array to dummies. When using the dummies array, just use [] operator or proper pointer arithmetic.

Also, note that function main should return an int, instead of void.

    int main()
    {
        int* myArray = malloc(50 * sizeof(int));   // gets you 50 integers
	    // perform operations on myArray, accessing it like myArray[3]
	    myArray = realloc(myArray, 25 * sizeof(int));
        // perform some more operations.
        free(myArray);  // free the memory once you are done with it
    }
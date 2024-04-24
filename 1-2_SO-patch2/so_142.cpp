    int main()
    {
        int* myArray = malloc(50 * sizeof(int));   // gets you 50 integers
	    // perform operation on myArray, accessing it like myArray[3]
	    myArray = realloc(myArray, 25 * sizeof(int));
    }
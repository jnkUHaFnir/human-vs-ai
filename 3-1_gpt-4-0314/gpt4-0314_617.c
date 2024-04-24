void readFromFile() {
     FILE *myfile; //File to access randomized floats
     int currentSz = 10; //Size iterator
     int maxSz = 1000010; // Maximum size to reference in the loop

     while (currentSz <= maxSz) {
         // Creates a new array with the current size.
         float *fileArr = (float *)malloc(currentSz * sizeof(float)); // Allocate memory on the heap

         // ... (rest of the code remains the same) ...

         fclose(myfile);

         // Updates the size.
         currentSz += 20000;

         free(fileArr); // Free the allocated memory
     }
}

void readFromFile() {
     FILE *myfile; //File to access randomized floats
     int currentSz = 10; //Size iterator
     int maxSz = 1000010; // Maximum size to reference in the loop

     while (currentSz <= maxSz) {
         // Creates a new array with the current size using dynamic memory allocation.
         float *fileArr = (float*)malloc(currentSz * sizeof(float));
         if (fileArr == NULL) {
             // Handle allocation error
             fprintf(stderr, "Error: Unable to allocate memory\n");
             exit(1);
         }

         // ... (rest of the code remains the same)

         // Free the dynamically allocated memory
         free(fileArr);

         // Updates the size.
         currentSz += 20000;
     }
}

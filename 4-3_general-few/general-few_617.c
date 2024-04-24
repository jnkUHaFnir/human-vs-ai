void readFromFile() {
     FILE *myfile; //File to access randomized floats
     int currentSz = 10; //Size iterator
     int maxSz = 1000010; // Maximum size to reference in the loop

     while (currentSz <= maxSz) {
         // Allocate memory dynamically on the heap for the array
         float *fileArr = (float*)malloc(currentSz * sizeof(float));

         // Check if memory allocation was successful
         if (fileArr == NULL) {
            printf("Memory allocation failed.\n");
            return;
         }

         // Your existing code to read values into fileArr remains the same

         // Sorts the randomized elements, and times the sorting algorithm.
         clock_t start = clock(), diff;
         heapSort(fileArr, currentSz);
         diff = clock() - start;

         // Converts to milliseconds.
         int millisec = diff * 1000000 / CLOCKS_PER_SEC;

         printf("size: %d runtime: %d\n", currentSz, millisec);
         fclose(myfile);

         // Free the dynamically allocated memory
         free(fileArr);

         // Updates the size.
         currentSz += 20000;
     }
}

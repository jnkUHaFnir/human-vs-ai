#include <stdlib.h> // for malloc and free

void readFromFile() {
     FILE *myfile; //File to access randomized floats
     int currentSz = 10; //Size iterator
     int maxSz = 1000010; // Maximum size to reference in the loop

     while (currentSz <= maxSz) {
         // Dynamically allocate memory for the float array
         float *fileArr = (float*)malloc(currentSz * sizeof(float));
         if (fileArr == NULL) {
             printf("Memory allocation failed for size: %d\n", currentSz);
             return; // Exit function or handle failure accordingly
         }

         // Rest of the code remains unchanged

         // Free the dynamically allocated memory
         free(fileArr);

         // Updates the size.
         currentSz += 20000;
     }
}

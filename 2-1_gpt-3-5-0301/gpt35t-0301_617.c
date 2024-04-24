void readFromFile() {
     FILE *myfile; //File to access randomized floats
     int currentSz = 10; //Size iterator
     int maxSz = 1000010; // Maximum size to reference in the loop

     while (currentSz <= maxSz) {
         // Creates a new array with the current size.
         float *fileArr = malloc(currentSz * sizeof(float));

         //Initializes file path
         char fileName[200];
         fileName[0] = '\0';
         strcat(fileName, "C:\\Users\\MatthewC\\Documents\\HonorsProject341\\RandomFloats\\");

         // Creates a size string to represent the current array size, and adds sizeStr
         // to the file path.
         char sizeStr[50];
         sprintf(sizeStr, "%d", currentSz);
         strcat(sizeStr, "Floats.txt");
         strcat(fileName, sizeStr);                 

         // Opens the file 
         myfile = fopen(fileName, "r");

         int iterator;

         // Feeds the elements from the file into the created array
         for (iterator = 0; iterator < currentSz; iterator++) 
             fscanf(myfile, "%f", &fileArr[iterator]);

         // Sorts the randomized elements, and times the sorting algorithm.
         clock_t start = clock(), diff;
         heapSort(fileArr, currentSz);
         diff = clock() - start;

         // Converts to milliseconds.
         int millisec = diff * 1000000 / CLOCKS_PER_SEC;

         printf("size: %d runtime: %d\n", currentSz, millisec);
         fclose(myfile);

         // Updates the size and frees the memory allocated for the array.
         currentSz += 20000;
         free(fileArr);
     }
}
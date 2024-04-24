     float *fileArr = NULL;
     while (currentSz <= maxSz) {
         fileArr = realloc(fileArr, currentSz * sizeof(float));
         if (!fileArr) {
            printf("Error allocating %d floats.", currentSz);
            break;
         }
         ...
     }
     free(fileArr);
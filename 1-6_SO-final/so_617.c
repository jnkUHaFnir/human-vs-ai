     float *fileArr = NULL;
     while (currentSz <= maxSz) {
         fileArr = realloc(fileArr, currentSz * sizeof(float));
         ...
     }
     free(fileArr);
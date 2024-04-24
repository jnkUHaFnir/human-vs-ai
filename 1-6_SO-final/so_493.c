    instr* read_file(const char*filename)
    {
      instr* arr=NULL;
      int len=0, size=0;
      FILE* f= fopen(filename, "r");
      if (!f) { perror(filename); exit(EXIT_FAILURE); };
      while (!feof (f)) {
         if (len>=size) {
           int newsize = 3*len/2+50;
           instr* newarr = calloc(newsize, sizeof(instr));
           if (!newarr) { perror("calloc"); exit(EXIT_FAILURE); };
           memcpy (newarr, arr, sizeof(instr)*len);
           free (arr);
           arr = newarr;
           size = newsize;
         };
         if (fscanf(f, "%d %d %d",
                    &arr[len]->op, &arr[len]->l, &arr[len]->m)<3)
           break;
         len++;
     }
     arr[len]->op = -1; // end of array marker
     fclose(f);
     return arr;
    }
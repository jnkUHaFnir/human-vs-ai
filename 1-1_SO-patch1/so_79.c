    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int intcmp(const void* a, const void* b) {
      return *(int*)a < *(int*)b ? -1 : 
             *(int*)a > *(int*)b ?  1 :
                                    0 ;
    }
    int main(int argc, char** argv) {
      size_t k = (argc > 1) ? atoi(argv[1]) : 0;
      if (argc < k + 2) {
        fprintf(stderr, "Usage: %s K element...\n"
                        "       where K <= number of elements\n",
                        argv[0]);
        return 1;
      }
      size_t n = argc - 2;
      int elements[n];
      for (int i = 0; i < n; ++i) elements[i] = atoi(argv[i + 2]);
      qsort(elements, n, sizeof *elements, intcmp);
      do {
        const char* delimiter = "";
        for (size_t i = 0; i < k; ++i) {
          printf("%s%2d ", delimiter, elements[i]);
          delimiter = " ";
        }
        putchar('\n');
      } while (next_k_permutation(elements, n, k));
      return 0;
    }
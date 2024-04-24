    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    bool print_array(void* vf, int* elements, size_t n) {
      FILE* f = vf;
      const char* delim = "";
      for (size_t i = 0; i < n; ++i) {
        fprintf(f, "%s%2d", delim, elements[i]);
        delim = " ";
      }
      putc('\n', f);
      return true;
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
      for (int i = 0; i < n; ++i)
        elements[i] = atoi(argv[i + 2]);
      k_heap_permute(elements, n, k, stdout, print_array);
      return 0;
    }
    #include <assert.h>
    #include <stdbool.h>
    #include <stddef.h>
    /* Helper functions */
    static void swap(int* elements, size_t a, size_t b) {
      int tmp = elements[a]; elements[a] = elements[b]; elements[b] = tmp;
    }
    static void flip(int* elements, size_t lo, size_t hi) {
      for (; lo + 1 < hi; ++lo, --hi) swap(elements, lo, hi - 1);
    }
    static void rotate_left(int* elements, size_t lo, size_t hi) {
      if (hi > lo) {
        int tmp = elements[lo];
        for (size_t i = lo + 1; i < hi; ++i) elements[i - 1] = elements[i];
        elements[hi - 1] = tmp;
      }
    }
    /* Recursive function; the main function will fill in the extra parameters */
    /* Requires hi >= lo and hi >= k. Array must have size (at least) lo + k */    
    static bool helper(int* array, size_t lo, size_t k, size_t hi,
                           void* baton, bool(*process)(void*, int*, size_t)) {
      if (hi == lo) {
        if (!process(baton, array + lo, k)) return false;
        if (lo % 2)
          flip(array, 0, lo);
        else
          rotate_left(array, 0, lo);
      }
      else {
        for (size_t i = 0; i < hi - 1; ++i) {
          if (!helper(array, lo, k, hi - 1, baton, process))
            return false;
          swap(array, hi % 2 ? 0 : i, hi - 1);
        }
        if (!helper(array, lo, k, hi - 1, baton, process))
          return false;
      }
      return true;
    }
    
    /* Generate all k-permutations of the given array of size n.
     * The process function is called with each permutation; if it returns false,
     * generation of permutations is terminated.
     */ 
    bool k_heap_permute(int* array, size_t n, size_t k,
                        void* baton, bool(*process)(void*, int*, size_t)) {
      assert(k <= n);
      return helper(array, n - k, k, n, baton, process);
    }
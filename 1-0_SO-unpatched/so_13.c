    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    
    #define ISPRIME(x) isprime(x)
    //#define ISPRIME(x) isprime_wheel(x)
    static int wheel[] = {
    1, 2, 2, 4, 2, 4, 2, 4, 6, 2, 6, 4, 2, 4, 6, 6, 2, 6, 4, 2, 6, 4, 6, 8, 4, 2,
    4, 2, 4, 14, 4, 6, 2, 10, 2, 6, 6, 4, 2, 4, 6, 2, 10, 2, 4, 2, 12, 10, 2, 4, 2,
    4, 6, 2, 6, 4, 6, 6, 6, 2, 6, 4, 2, 6, 4, 6, 8, 4, 2, 4, 6, 8, 6, 10, 2, 4, 6,
    2, 6, 6, 4, 2, 4, 6, 2, 6, 4, 2, 6, 10, 2, 10, 2, 4, 2, 4, 6, 8, 4, 2, 4, 12,
    2, 6, 4, 2, 6, 4, 6, 12, 2, 4, 2, 4, 8, 6, 4, 6, 2, 4, 6, 2, 6, 10, 2, 4, 6, 2,
    6, 4, 2, 4, 2, 10, 2, 10, 2, 4, 6, 6, 2, 6, 6, 4, 6, 6, 2, 6, 4, 2, 6, 4, 6, 8,
    4, 2, 6, 4, 8, 6, 4, 6, 2, 4, 6, 8, 6, 4, 2, 10, 2, 6, 4, 2, 4, 2, 10, 2, 10,
    2, 4, 2, 4, 8, 6, 4, 2, 4, 6, 6, 2, 6, 4, 8, 4, 6, 8, 4, 2, 4, 2, 4, 8, 6, 4,
    6, 6, 6, 2, 6, 6, 4, 2, 4, 6, 2, 6, 4, 2, 4, 2, 10, 2, 10, 2, 6, 4, 6, 2, 6, 4,
    2, 4, 6, 6, 8, 4, 2, 6, 10, 8, 4, 2, 4, 2, 4, 8, 10, 6, 2, 4, 8, 6, 6, 4, 2, 4,
    6, 2, 6, 4, 6, 2, 10, 2, 10, 2, 4, 2, 4, 6, 2, 6, 4, 2, 4, 6, 6, 2, 6, 6, 6, 4,
    6, 8, 4, 2, 4, 2, 4, 8, 6, 4, 8, 4, 6, 2, 6, 6, 4, 2, 4, 6, 8, 4, 2, 4, 2, 10,
    2, 10, 2, 4, 2, 4, 6, 2, 10, 2, 4, 6, 8, 6, 4, 2, 6, 4, 6, 8, 4, 6, 2, 4, 8, 6,
    4, 6, 2, 4, 6, 2, 6, 6, 4, 6, 6, 2, 6, 6, 4, 2, 10, 2, 10, 2, 4, 2, 4, 6, 2, 6,
    4, 2, 10, 6, 2, 6, 4, 2, 6, 4, 6, 8, 4, 2, 4, 2, 12, 6, 4, 6, 2, 4, 6, 2, 12,
    4, 2, 4, 8, 6, 4, 2, 4, 2, 10, 2, 10, 6, 2, 4, 6, 2, 6, 4, 2, 4, 6, 6, 2, 6, 4,
    2, 10, 6, 8, 6, 4, 2, 4, 8, 6, 4, 6, 2, 4, 6, 2, 6, 6, 6, 4, 6, 2, 6, 4, 2, 4,
    2, 10, 12, 2, 4, 2, 10, 2, 6, 4, 2, 4, 6, 6, 2, 10, 2, 6, 4, 14, 4, 2, 4, 2, 4,
    8, 6, 4, 6, 2, 4, 6, 2, 6, 6, 4, 2, 4, 6, 2, 6, 4, 2, 4, 12, 2, 12
    };
    int isprime_wheel(unsigned long n)
    {
      unsigned long isqrt = (unsigned long) (floor(sqrt(n)) + 1);
      unsigned long start = 5, factor = 2;
      int wlen = sizeof(wheel) / sizeof(int);
      int next = 0;
      if(n == 2){
        return 1;
      }
      if ((n & 1) == 0) {
        return 0;
      }
      if (isqrt * isqrt == n) {
        return 0;
      }
      while (factor < isqrt) {
        if (n % factor == 0) {
          return 0;
        }
        factor += (unsigned long) wheel[next];
        next++;
        if (next == wlen) {
          next = start;
        }
      }
    
      return 1;
    }
    
    unsigned long primefactors(unsigned long n)
    {
      unsigned long start = 5, factor = 2;
      unsigned long biggest = 0;
      int wlen = sizeof(wheel) / sizeof(int);
      int next = 0;
      if (n == 1) {
        return 0;
      }
      if (n == 2 || n == 3) {
        return n;
      }
    
      while (factor <= n) {
        while (n % factor == 0) {
          biggest = factor;
          n /= factor;
        }
        factor += (unsigned long) wheel[next];
        next++;
        if (next == wlen) {
          next = start;
        }
      }
      if (n > 1 && biggest == 0) {
        return n;
      }
    
      return biggest;
    }
    
    
    
    int isprime(unsigned long n)
    {
      unsigned long i;
      unsigned long isqrt = (unsigned long) floor(sqrt(n)) + 1;
    
      for (i = 2; i < isqrt; i++) {
        if ((n % i) == 0) {
          return 0;
        }
      }
      return 1;
    }
    #include <time.h>
    int main()
    {
      unsigned long n, i, lpf = 0, wheelfactor = 0;
      clock_t start,stop;
  
      if(scanf("%lu", &n) != 1){
         fprintf(stderr,"Must be a positive, small integer \n");
         exit(EXIT_FAILURE);
      }
    
      start = clock();
      wheelfactor = primefactors(n);
      stop = clock();
      printf("WHEEL Time %.10f seconds\n", (double) (stop - start) / CLOCKS_PER_SEC);
      printf("WHEEL %lu\n",wheelfactor );
    
      start = clock();
      if (n == 1) {
        puts("0");
        goto END;
      }
      if (n == 2 || ISPRIME(n) == 1) {
        printf("NAIVE %lu (n is prime, next print must show 0)\n", n);
        goto END;
      }
      for (i = 2; i < n / 2 + 1; i++) {
        if (ISPRIME(i) == 1 && n % i == 0) {
          //printf("PRIME %lu\n", i);
          lpf = i;
          n /= i;
          // n might be down to 2 and isprime(2) returns true
          // but  only odd primes are allowed at this point
          if (ISPRIME(n) == 1 && n != 2) {
            //printf("ISPRIME %lu\n", n);
            lpf = n;
          }
        }
      }
    END:
      stop = clock();
    
      printf("NAIVE Time %.10f seconds\n", (double) (stop - start) / CLOCKS_PER_SEC);
      printf("NAIVE %lu\n", lpf);
      return 0;
    }
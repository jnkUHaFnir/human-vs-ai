    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    
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
    
    int main()
    {
      unsigned long n, i, lpf;
      scanf("%ld", &n);
      unsigned long isqrt = (unsigned long) floor(sqrt(n)) + 1;
      for (i = 2; i < isqrt; i++) {
        if (i % 2 == 1) {
          if (isprime(i) == 1 && n % i == 0) {
            printf("PRIME %lu\n",i);
            lpf = i;
            n /= i;
          }
        }
      }
      printf("%lu\n", lpf);
      return 0;
    }
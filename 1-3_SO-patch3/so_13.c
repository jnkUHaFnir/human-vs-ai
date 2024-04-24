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
      // Seems as if this program needs to output n if it is a prime, too
      if(isprime(n)){
        printf("%lu\n", n);
        return 0;
      }
      for (i = 2; i < n/2 +1; i++) {
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
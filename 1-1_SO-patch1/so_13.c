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
      unsigned long n, i, lpf = 0;
      scanf("%lu", &n);
      // 1 is  not prime
      if(n == 1){
        puts("0");
        return 0;
      }
      // 2 is not prime (mnore shortcuts possible)
      // the number might be prime itself
      if (n == 2 || isprime(n) == 1) {
        printf("%lu\n", n);
        return 0;
      }
      // largest factor is at most n/2 +1
      for (i = 2; i < n/2 + 1; i++) {
        // if n is divisble by n and i is prime
        if (isprime(i) == 1 && n % i == 0) {
          printf("PRIME %lu\n", i);
          // replace max prime with current prime
          lpf = i;
          // divide by current prime to reduce work
          n /= i;
          // n might be prime now, check here befor i gets incremented
          if (isprime(n) == 1) {
            lpf = n;
          }
        }
      }
      printf("%lu\n", lpf);
      return 0;
    }
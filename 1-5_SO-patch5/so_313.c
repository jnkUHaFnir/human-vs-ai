    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    enum { SHF = 31, BMASK = 0x1 << SHF, MODULE = 1000000000UL, LEN = 345, LIMIT = 1024 };
    unsigned int scaleBigNum(const unsigned short scale, const unsigned int lim, unsigned int *num);   
    unsigned int pow2BigNum(const unsigned int lim, unsigned int *nsrc, unsigned int *ndst);
    unsigned int addBigNum(const unsigned int lim1, unsigned int *num1, const unsigned int lim2, unsigned int *num2);
    void bigNum(const unsigned short int base, const unsigned int exp, unsigned int *lim, unsigned int *num);
    int main(void)
    {
      unsigned int num[LEN + 2], lim;
      int i, j;
     
      for(i = 1; i < LIMIT; ++i)
      {
        bigNum(i, i, &lim, num);
        
        printf("%i^%i == ", i, i);
        for(j = lim - 1; j > -1; --j)
          printf("%09u", num[j]);
        printf("\n");
      } 
    
    
    /* Don't try it!!!
        bigNum(65535, 65535, &lim, num);
        
      printf("%i^%i == ", 65535, 65535);
      for(i = lim - 1; i > -1; --i)
        printf("%09u", num[i]);
        printf("\n");
    */
     
      return 0;
    }
    /*
      bigNum: Compute number base^exp and store it in num array
      @base: Base number
      @exp: Exponent number
      @lim: Length of result number
      @num: Array where it stores big number
    */
    void bigNum(const unsigned short int base, const unsigned int exp, unsigned int *lim, unsigned int *num)
    {
      unsigned int m; 
      unsigned int cop[LEN + 2];
      unsigned int *v, *w, *k;
      
      for(m = BMASK; ( (m & exp) == 0 ) && m;  m >>= 1 ) ;
    
      /*
        //Note: mem has the exactly amount memory to allocate (dinamic memory version) 
         mem = ( (unsigned int) (exp * log10( (float) base ) / 9 ) ) + 1;
      */
      
      num[0] = (m) ? 1 : 0;
      for(*lim = 1, v = num, w = cop; m > 1; m >>= 1)
      { 
        bzero(((void *) w), ( 2 * (*lim + 1) ) * sizeof(unsigned int) );
    
        if( exp & m )
          *lim = scaleBigNum(base, *lim, v);
    
        *lim = pow2BigNum(*lim, v, w);
        
        k = v;
        v = w;
        w = k;
      }
      if(exp & 0x1)
        *lim = scaleBigNum(base, *lim, v);
      if(v != num )
        memcpy(num, cop, *lim * sizeof(unsigned int) );  
    }
    /*
      scaleBigNum: Make an (num[] <- scale*num[]) big number operation
      @scale: Scalar that multiply big number
      @lim: Length of source big number
      @num: Source big number (array of unsigned int). Update it with new big number value
      
      Return: Length of operation result (new length of num)   
    */
    unsigned int scaleBigNum(const unsigned short scale, const unsigned int lim, unsigned int *num)
    {
      unsigned int i;
      unsigned long long int n, t;
    
    
      for(n = 0, t = 0, i = 0; i < lim; ++i)
      {
        t = (n / MODULE) + (t / MODULE);
        n = ( (unsigned long long int) scale * num[i]  );
        
        t = (n % MODULE) + t;
        num[i] =  t % MODULE;
      }
    
      num[i] = (n / MODULE) + (t / MODULE);
  
      return ( (num[i]) ? lim + 1 : lim )
    }
    
    
    /*
      pow2BigNum: Make a (dst[] <- src[] * src[]) big number operation  
      @lim: Length of source big number
      @src: Source big number (array of unsigned int)
      @dst: Destination big number (array of unsigned int)
    
      Return: Length of operation result (length of destination big number)   
    */
    unsigned int pow2BigNum(const unsigned int lim, unsigned int *src, unsigned int *dst)
    {
      unsigned int i, j;
      unsigned long long int n, t;
    
      
      for(i = 0; i < lim; ++i)
      {
        for(j = i, n = 0; j < lim; ++j)
        {
          n = ( (unsigned long long int) src[i] * src[j] );
          
          if(i != j)
          {
            t = 2 * (n % MODULE);
            n = 2 * (n / MODULE);
    	
            dst[i + j] += t % MODULE;	  
            dst[i + j + 1] += ( (t / MODULE) + (n % MODULE) );
            dst[i + j + 2] += (n / MODULE);
          }
          else
          {
            dst[i + j] += n % MODULE;
            dst[i + j + 1] += n / MODULE;
          }
          
          
          for(t = i + j; t < (lim + j); ++t)
          {
            dst[t + 1] += (dst[t] / MODULE);
       	    dst[t] %= MODULE;
          }
          
        }
      }
      
      i = lim << 1;
      return ((dst[i - 1]) ? i : i - 1);
    }
    
    /*
      addBigNum: Make a (num2[] <- num1[] + num2[]) big number operation
      @lim1: Length of source num1 big number
      @num1: First source operand big number (array of unsigned int). Should be smaller than second
      @lim2: Length of source num2 big number
      @num2: Second source operand big number (array of unsigned int). Should be equal or greater than first
  
      Return: Length of operation result (new length of num2) or 0 if num1[] > num2[] (dosen't do any op.)  
    */
    unsigned int  addBigNum(const unsigned int lim1, unsigned int *num1, const unsigned int lim2, unsigned int *num2)
    {
      unsigned long long int n;
      unsigned int i;
    
      if(lim1 > lim2)
        return 0;
      
      for(num2[lim2] = 0, n = 0, i = 0; i < lim1; ++i)
      {
        n = num2[i] + num1[i] + (n / MODULE); 
        num2[i] = n % MODULE;
      }
    
      for(n /= MODULE; n; ++i)
      {
        num2[i] += n;
        n = (num2[i] / MODULE);
      }
    
      return (lim2 > i) ? lim2 : i;
    }
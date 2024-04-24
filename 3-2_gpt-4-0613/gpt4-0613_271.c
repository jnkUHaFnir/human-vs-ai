#include<gmp.h>
#include<stdio.h>

void print_in_base10(const unsigned char *arr, int size) 
{
  mpz_t num;
  mpz_init_set_si(num,0); //initialize num to 0
    
  for(int i = size-1 ; i >= 0 ; i--)
  {
    mpz_mul_si(num,num,256);  //multiply by 256
    mpz_add_ui(num,num,arr[i]); //add ith element of n
  }
  
  mpz_out_str(stdout, 10, num);
  mpz_clear(num); 
}

int main()
{
  unsigned char n[3];
  n[0] = 1;
  n[1] = 2;
  n[2] = 3;
  
  print_in_base10(n,3);
      
  return 0;  
} 

#include <stdio.h>

struct x{
    int a;
    int b;
};

int main(void)
{
   char input[]= "((1828,299),(2729,2553),(2797,2929),(2200,1383),(2894,876))";
   struct x arr[5];
    
   int i = 0, j = 0, num1, num2;
   while(sscanf(input + i, " ((%d,%d)%*[,()]", &num1, &num2)==2)
   {
        arr[j].a = num1;
        arr[j].b = num2;
        ++j;
        
        // to avoid being caught in infinite loop
        i += 12;
    }
    
    for(int k =0;k<5;++k)
    {
        printf("(%d,%d)\n", arr[k].a, arr[k].b);
    }
    
   return 0;
}

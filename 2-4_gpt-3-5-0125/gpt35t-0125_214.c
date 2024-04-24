#include<stdio.h>

int main()
{
   char* ptr, str[30];
   int size=0;
   int word=0;

   puts("enter the string");
   gets(str);

   for(ptr=str; *ptr!='\0'; ptr++)
   {
       if(*ptr != ' ') // skip counting spaces
       {
           size++;
       }
   }

   printf("size of string without spaces is = %d", size);
   
   return 0;
}

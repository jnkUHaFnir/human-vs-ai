#include<stdio.h>
//#include<conio.h>  // Consider commenting this out if you're not using Turbo C/C++ or similar

void main()
{
   char *ptr, str[30];
   int size = 0;  // This will count characters excluding spaces

   puts("enter the string:");
   gets(str); // Note: gets() is unsafe; consider using fgets(str, sizeof(str), stdin)
   fflush(stdin); // This is typically not advisable after gets() or fgets(), as it can cause undefined behavior depending on the environment and is usually unnecessary.

   for(ptr = str; *ptr != '\0'; ptr++)
   {
       if(*ptr != ' ')  // Check if the current character is not a space
       {
           size++;
       }
   }

   printf("size of string excluding spaces is = %d\n", size);
   getchar(); // Wait for an additional key press before closing, mainly for console window environments.
}
